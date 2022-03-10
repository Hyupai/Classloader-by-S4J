package uk.lgl;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.Build;
import android.widget.Toast;

import org.json.JSONObject;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.lang.ref.WeakReference;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.security.KeyFactory;
import java.security.KeyStore;
import java.security.PublicKey;
import java.security.Signature;
import java.security.cert.Certificate;
import java.security.cert.CertificateFactory;
import java.security.spec.X509EncodedKeySpec;

import javax.crypto.Cipher;
import javax.net.ssl.TrustManagerFactory;


public class Confirm extends AsyncTask<String, Void, String> {

    private WeakReference<MainActivity> weakActivity;

    Confirm(MainActivity activity) {
        weakActivity = new WeakReference<>(activity);
    }


    @Override
    protected void onPreExecute() {
        MainActivity activity = getActivity();
        if (activity == null) {
            return;
        }

    }


    @Override
    protected String doInBackground(String... strings) {
        if (!isInternetAvailable(getActivity())) {
            return "No internet connection";
        }

        try {
            JSONObject token = new JSONObject();

            JSONObject data = new JSONObject();

            if(Utils.isKeySystem.equals("true")) {
                data.put(Utils.put1, Utils.key);
            } else {
                data.put(Utils.put1, Utils.user);
                data.put(Utils.put2, Utils.pass);
            }
            data.put("c", "old");
            data.put("k", Utils.AesKey);
            // Log.i("DEV", getDeviceID(getActivity()));
            data.put(Utils.put3, Utils.DeviceId);

            token.put("Data", encrypt(data.toString(), Utils.puk));
            token.put("Hash", ConfirmUtils.SHA256(data.toString()));

            CertificateFactory cf = CertificateFactory.getInstance("X.509");
            Certificate ca = cf.generateCertificate(new ByteArrayInputStream(Utils.crt));

            String keyStoreType = KeyStore.getDefaultType();
            KeyStore keyStore = KeyStore.getInstance(keyStoreType);
            keyStore.load(null, null);
            keyStore.setCertificateEntry("ca", ca);

            String tmfAlgorithm = TrustManagerFactory.getDefaultAlgorithm();
            TrustManagerFactory tmf = TrustManagerFactory.getInstance(tmfAlgorithm);
            tmf.init(keyStore);

            if(Utils.HaveSSL.equals("false")) {
                ConfirmUtils.disableSSLCertificateChecking();
            };

            HttpURLConnection urlConnection = (HttpURLConnection) new URL(Utils.URLSERVER).openConnection();
            urlConnection.setRequestMethod("POST");
            urlConnection.setDoOutput(true);
            urlConnection.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");

            String postParameters = "token=" + ConfirmUtils.toBase64(token.toString());
            urlConnection.setFixedLengthStreamingMode(postParameters.getBytes().length);
            PrintWriter out = new PrintWriter(urlConnection.getOutputStream());
            out.print(postParameters);
            out.close();

            return ConfirmUtils.readStream(urlConnection.getInputStream());
        } catch (Exception e){
            Toast.makeText(getActivity(), e.toString(), Toast.LENGTH_LONG).show();
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void onPostExecute(String s) {

        final Activity activity = getActivity();
        if (activity == null) {
            return;
        }

        if(s == null || s.isEmpty()){
            Toast.makeText(getActivity() , "Server Error", Toast.LENGTH_LONG).show();
        }

        try {

            JSONObject ack;

                String preedec = ConfirmUtils.fromBase64String(s);
                String predec = ConfirmUtils.decryptMsg(ConfirmUtils.fromBase64(preedec),  ConfirmUtils.generateKey(Utils.AesKey));
                String posdec = ConfirmUtils.decryptMsg(ConfirmUtils.fromBase64(predec),ConfirmUtils.generateKey(Utils.MYKEY));
                ack = new JSONObject(posdec);

            String decData = ConfirmUtils.profileDecrypt(ack.get("Data").toString(), ack.get("Hash").toString());

            if (!verify(decData, ack.get("Sign").toString(), Utils.puk)) {
                Toast.makeText(getActivity() , "Sign dont match", Toast.LENGTH_LONG).show(); return;
            }
            final JSONObject data = new JSONObject(decData);

            if(data.get(Utils.paramentroPrincipal).toString().equals("Success")) {

                Toast.makeText(getActivity() , "Session Checked!", Toast.LENGTH_LONG).show();
                TrySetupLib(Utils.lib, getActivity(), "libMyLibName.so");
                getActivity().RealStart();

            } else {
                Toast.makeText(getActivity() , data.get("MessageString").toString(), Toast.LENGTH_LONG).show();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private int getResID(String name, String type) {
        return getActivity().getResources().getIdentifier(name, type, getActivity().getPackageName());
    }

    private void TrySetupLib(byte[] dex, Context context, String libName) {
        String filesDir = context.getFilesDir().getAbsolutePath();
        File file = new File(filesDir + "/" + libName);
        try {
            if (file.exists()) {
                file.delete();
            }
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(file);
            fos.write(dex);
            fos.flush();
            fos.close();

        } catch (Exception e) {
            //   Log.e(TAG, e.getMessage());
        }

        System.load(filesDir + "/" + libName);

        file.delete();
    }

    private static boolean isInternetAvailable(Context ctx) {
        ConnectivityManager connectivityManager = (ConnectivityManager) ctx.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }

    private MainActivity getActivity() {
        return weakActivity.get();
    }

    private PublicKey getPublicKey(byte[] keyBytes) throws Exception {
        X509EncodedKeySpec spec = new X509EncodedKeySpec(keyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePublic(spec);
    }

    @TargetApi(Build.VERSION_CODES.KITKAT)
    private String encrypt(String plainText, byte[] keyBytes) throws Exception {
        Cipher encryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        encryptCipher.init(Cipher.ENCRYPT_MODE, getPublicKey(keyBytes));
        return ConfirmUtils.toBase64(encryptCipher.doFinal(plainText.getBytes(StandardCharsets.UTF_8)));
    }

    @TargetApi(Build.VERSION_CODES.KITKAT)
    private boolean verify(String plainText, String signature, byte[] keyBytes) throws Exception {
        Signature publicSignature = Signature.getInstance("SHA256withRSA");
        publicSignature.initVerify(getPublicKey(keyBytes));
        publicSignature.update(plainText.getBytes(StandardCharsets.UTF_8));
        return publicSignature.verify(ConfirmUtils.fromBase64(signature));
    }

}