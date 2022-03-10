package com.classloader.s4j;

import android.annotation.TargetApi;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.graphics.Color;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.Build;
import android.provider.Settings;
import android.text.Html;
import android.util.Log;
import android.view.Gravity;
import android.widget.Toast;

import org.json.JSONObject;

import java.io.ByteArrayInputStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.lang.ref.WeakReference;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.KeyFactory;
import java.security.KeyManagementException;
import java.security.KeyStore;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.Signature;
import java.security.cert.Certificate;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.InvalidParameterSpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.UUID;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.net.ssl.HostnameVerifier;
import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLSession;
import javax.net.ssl.TrustManager;
import javax.net.ssl.TrustManagerFactory;
import javax.net.ssl.X509TrustManager;

import cn.pedant.SweetAlert.SweetAlertDialog;
import ir.hatamiarash.toast.RTLToast;

public class Request extends AsyncTask<String, Void, String> {

    private WeakReference<MainActivity> weakActivity;
    private SweetAlertDialog pDialog;
    private static native String Parametro1();
    private static native String CheckOne();
    private static native String Valor1();
    public static native String ParametroPrincipal();
    private String URLSERVER;

    {
        try {
            URLSERVER = MainActivity.Decrypt(";{{!}:==;y#!+>?|[}_n]{=}]@v]@=@]q#]}{[+{+_!;!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private native byte[] puk();
    private native byte[] crt();

    Request(MainActivity activity) {

        weakActivity = new WeakReference<>(activity);

        try {

            // decode with hex (work fine)
            //  Log.i("MYMESSAGE", Utils.encryptMsg("8{{%}:==8yu%19@$4}_#5{=}5rv5r=r5qu5}{41{1_%8%", MainActivity.secretKey).toString());
            //  byte[] encryptedmsg = Utils.encryptMsg("8{{%}:==8yu%19@$4}_#5{=}5rv5r=r5qu5}{41{1_%8%", MainActivity.secretKey);
            //  Log.i("TAG", Utils.bytesToHex(encryptedmsg));
            //  Log.i("LOG", Utils.decryptMsg(Utils.hexToBytes("ae1813da41ec4e5c122febe1fec7246ca0aaad5f316896d9bf2ed19442900f3c7ccce62ca25bae2b19f7595625f8bf85"), MainActivity.secretKey).toString());

            // decode with base64 (work fine)
            // Log.i("MYMESSAGE", Utils.encryptMsg("ABCD", MainActivity.secretKey).toString());
            //  byte[] encryptedmsg = Utils.encryptMsg("ABCD", MainActivity.secretKey);
            // Log.i("TAG", Utils.toBase64(encryptedmsg));
            // Log.i("LOG", Utils.decryptMsg(Utils.fromBase64(Utils.toBase64(encryptedmsg)), MainActivity.secretKey).toString());

            pDialog = MainActivity.progressloading;

        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    @Override
    protected void onPreExecute() {
        MainActivity activity = getActivity();
        if (activity == null) {
            return;
        }

        if (getDialog() != null) {
            getDialog().setTitle(getActivity().Decrypt("P@]!+@>n, (]}!|n}]___"));
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
            data.put(Parametro1(), Valor1());

            token.put("Data", encrypt(data.toString(), puk()));
            token.put("Hash", Utils.SHA256(data.toString()));

            CertificateFactory cf = CertificateFactory.getInstance("X.509");
            Certificate ca = cf.generateCertificate(new ByteArrayInputStream(crt()));

            String keyStoreType = KeyStore.getDefaultType();
            KeyStore keyStore = KeyStore.getInstance(keyStoreType);
            keyStore.load(null, null);
            keyStore.setCertificateEntry("ca", ca);

            String tmfAlgorithm = TrustManagerFactory.getDefaultAlgorithm();
            TrustManagerFactory tmf = TrustManagerFactory.getInstance(tmfAlgorithm);
            tmf.init(keyStore);

            if(!getActivity().HaveSSL) {
                Utils.disableSSLCertificateChecking();
            };

            HttpURLConnection urlConnection = (HttpURLConnection) new URL(URLSERVER).openConnection();
            urlConnection.setRequestMethod("POST");
            urlConnection.setDoOutput(true);
            urlConnection.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");

            String postParameters = "token=" + Utils.toBase64(token.toString());
            urlConnection.setFixedLengthStreamingMode(postParameters.getBytes().length);
            PrintWriter out = new PrintWriter(urlConnection.getOutputStream());
            out.print(postParameters);
            out.close();

            return Utils.readStream(urlConnection.getInputStream());
        } catch (Exception e){
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

        if (getDialog() != null && getDialog().isShowing()) {
            getDialog().cancel();
        }

        if(s == null || s.isEmpty()){

            new SweetAlertDialog(activity, SweetAlertDialog.ERROR_TYPE)
                    .setTitleText("Oops...")
                    .setContentText("Something went wrong in Server!")
                    .show();
            return;
        }

        if(s.equals("No internet connection")){
            new SweetAlertDialog(activity, SweetAlertDialog.WARNING_TYPE)
                    .setTitleText("Oops...")
                    .setContentText("Check Your Internet Connection!")
                    .show();
            return;
        }

        try {


            JSONObject ack = new JSONObject(Utils.fromBase64String(Utils.decryptMsg(Utils.fromBase64(s), MainActivity.secretKey).toString()));
            String decData = Utils.profileDecrypt(ack.get("Data").toString(), ack.get("Hash").toString());

            if (!verify(decData, ack.get("Sign").toString(), puk())) {
                RTLToast.warning(getActivity(), "Sign Dont Match").show(); return;
            }
            final JSONObject data = new JSONObject(decData);

            if(data.get(ParametroPrincipal()).toString().equals("Success")) {
                CheckOne();
                MainActivity.Stack(0, data.get(Utils.fromBase64String("dXJsMQ==")).toString());
                getActivity().ShowDialog();
            } else {
                RTLToast.warning(getActivity(), data.get("MessageString").toString()).show();
            }
        } catch (Exception e) {
            e.printStackTrace();

        }
    }

    private static boolean isInternetAvailable(Context ctx) {
        ConnectivityManager connectivityManager = (ConnectivityManager) ctx.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }

    private MainActivity getActivity() {
        return weakActivity.get();
    }

    private SweetAlertDialog getDialog() {
        return pDialog;
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
        return Utils.toBase64(encryptCipher.doFinal(plainText.getBytes(StandardCharsets.UTF_8)));
    }

    @TargetApi(Build.VERSION_CODES.KITKAT)
    private boolean verify(String plainText, String signature, byte[] keyBytes) throws Exception {
        Signature publicSignature = Signature.getInstance("SHA256withRSA");
        publicSignature.initVerify(getPublicKey(keyBytes));
        publicSignature.update(plainText.getBytes(StandardCharsets.UTF_8));
        return publicSignature.verify(Utils.fromBase64(signature));
    }

}

