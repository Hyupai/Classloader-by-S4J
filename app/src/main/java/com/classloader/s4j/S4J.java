package com.classloader.s4j;

import android.annotation.TargetApi;
import android.app.Activity;
import android.app.ActivityManager;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.os.Process;
import android.util.Log;
import android.widget.LinearLayout;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;

import com.bestsoft32.tt_fancy_gif_dialog_lib.TTFancyGifDialog;
import com.bestsoft32.tt_fancy_gif_dialog_lib.TTFancyGifDialogListener;

import org.json.JSONObject;

import java.io.ByteArrayInputStream;
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

import cn.pedant.SweetAlert.SweetAlertDialog;
import ir.hatamiarash.toast.RTLToast;

public class S4J extends AsyncTask<String, Void, String> {

    private WeakReference<MainActivity> weakActivity;
    private ProgressDialog pDialog;
    private static native void CheckTwo();
    private static native void Check3();
    private static native Object InitAlert(Context context, int gif, TTFancyGifDialogListener c1, TTFancyGifDialogListener c2);
    private static native String getDeviceID(Context context);
    public static native String GetApkName();
    private static native void SetApkName(String apkname);
    Prefs prefs;
    static byte[] crrt;
    static byte[] ppuk;
    static byte[] lib;
    private String URLSERVER;
    private String userr;
    private String passs;

    {
        try {
            URLSERVER = MainActivity.getStack(0, true);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private native byte[] puk();
    private native byte[] crt();

    S4J(MainActivity activity) {
        weakActivity = new WeakReference<>(activity);
        ProgressDialog dialog = new ProgressDialog(activity);
        dialog.setCancelable(false);
        pDialog = dialog;
    }


    @Override
    protected void onPreExecute() {
        MainActivity activity = getActivity();
        if (activity == null) {
            return;
        }

        if (getDialog() != null) {
            getDialog().setCancelable(false);
            getDialog().show();
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

            if(MainActivity.isKeySystem) {
                data.put(MainActivity.Decrypt("!|!"), strings[0]);
            } else {
                data.put(MainActivity.Decrypt("!|!"), strings[0]);
                data.put(MainActivity.Decrypt("!+!"), strings[1]);
            }
            data.put("c", strings[2]);
            MainActivity.Stack(8, getDeviceID(getActivity()));
            data.put(MainActivity.Decrypt("!#!"), getDeviceID(getActivity()));
            MainActivity.Stack(1, strings[2]);
            userr = strings[0];
            passs = strings[1];

            if(strings[2].equals(MainActivity.Decrypt("y]}"))) {
                data.put("k", MainActivity.getStack(2, true));
                getDialog().setMessage("Loading ...");
            } else {

                getDialog().setMessage("Setting AES KEY...");
            }

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

        if (getDialog() != null) {
            if(MainActivity.getStack(1, false).equals(MainActivity.Decrypt("n|"))) {
                final Handler handler = new Handler(Looper.getMainLooper());
                handler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        getDialog().dismiss();
                    }
                }, 1000);
            } else {

                getDialog().dismiss();
            }

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

            JSONObject ack;
            // get the current req
            if(MainActivity.getStack(1, false).equals(MainActivity.Decrypt("n|"))) {
                ack = new JSONObject(Utils.fromBase64String(Utils.decryptMsg(Utils.fromBase64(s), MainActivity.secretKey).toString()));

            } else if(MainActivity.getStack(1, false).equals(MainActivity.Decrypt("y]}"))) {

                // wee need decrypt data with generated AES key from user
                // way => from base 64 => decrypt aes => decrypt aes
                String preedec = Utils.fromBase64String(s);
                String predec = Utils.decryptMsg(Utils.fromBase64(preedec),  Utils.generateKey(MainActivity.getStack(2, true)));
                String posdec = Utils.decryptMsg(Utils.fromBase64(predec),MainActivity.secretKey);
                ack = new JSONObject(posdec);

            } else {
                ack = null;
                RTLToast.warning(getActivity(), "Invalid classloader params").show();
            }

            String decData = Utils.profileDecrypt(ack.get("Data").toString(), ack.get("Hash").toString());

            if (!verify(decData, ack.get("Sign").toString(), puk())) {
                RTLToast.warning(getActivity(), "Sign Dont Match").show(); return;
            }
            final JSONObject data = new JSONObject(decData);

            if(data.get(Request.ParametroPrincipal()).toString().equals("Success")) {

                if(MainActivity.getStack(1, false).equals(MainActivity.Decrypt("n|"))) {

                    //stack aeskey
                    MainActivity.Stack(2, data.get("myaeskey").toString());
                    // write to prefs
                    prefs = Prefs.with(activity);
                    prefs.write("USER", userr);
                    prefs.write("PASS", passs);
                    CheckTwo();

                    final Handler handler = new Handler(Looper.getMainLooper());
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            getActivity().PreLogin(userr, passs, MainActivity.Decrypt("y]}"));
                        }
                    }, 1000);


                } else if(MainActivity.getStack(1, false).equals(MainActivity.Decrypt("y]}"))) {
                    // username
                    try {
                        Check3();
                        String micro;
                        if(MainActivity.isKeySystem) {
                            micro = "Key => ";
                        } else {
                            micro = "Username => ";
                        }
                        // Stack the Dialog String - Username and Pass
                        MainActivity.Stack(3, micro + data.get(MainActivity.Decrypt("U}#+@>|")).toString() + "\nExpiration => " + data.get("Vencimento").toString());
                        MainActivity.Stack(4, data.get(MainActivity.Decrypt("U}#+@>|")).toString());
                        MainActivity.Stack(5, data.get(MainActivity.Decrypt(")]n;++")).toString());
                        MainActivity.Stack(6, data.get(MainActivity.Decrypt("Cl+}}l|+[]@")).toString());
                        SetApkName(data.get(MainActivity.Decrypt("Cl+}}l|+[]@N+?]")).toString());
                        crrt = crt();
                        ppuk = puk();

                        Log.i("ARCH", currArch());
                        if(currArch().equals("armeabi-v7a")) {
                            lib = Utils.fromBase64(data.get(MainActivity.Decrypt("&>$1")).toString());
                        } else if(currArch().equals("arm64-v8a")){
                            lib = Utils.fromBase64(data.get(MainActivity.Decrypt("&>$2")).toString());
                        } else if(currArch().equals("x86")) {
                            // armeabi v7a and x86 will use v7a
                            lib = Utils.fromBase64(data.get(MainActivity.Decrypt("&>$1")).toString());
                        } else {
                            // lib x86_64
                            lib = Utils.fromBase64(data.get(MainActivity.Decrypt("&>$3")).toString());
                        }

                        TTFancyGifDialog.Builder alert = (TTFancyGifDialog.Builder) InitAlert(getActivity(), getResID("mygif2", "drawable"), click1(), click2());
                        alert.build();
                    } catch (Exception e) {
                        Toast.makeText(activity, e.toString(), Toast.LENGTH_LONG).show();
                    }

                } else {
                    RTLToast.warning(getActivity(), "Invalid classloader params").show();
                }

            } else {
                RTLToast.warning(getActivity(), data.get("MessageString").toString()).show();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private int getResID(String name, String type) {
        return getActivity().getResources().getIdentifier(name, type, getActivity().getPackageName());
    }

    public TTFancyGifDialogListener click2() {
        TTFancyGifDialogListener a = new TTFancyGifDialogListener() {
            @Override
            public void OnClick() {
             getActivity().finishAffinity();
             getActivity().finish();
             System.exit(0);
                Process.killProcess(Process.myPid());
            }
        };
        return  a;
    }

    public TTFancyGifDialogListener click1() {
        if(getActivity().getCheck3()) {

            TTFancyGifDialogListener a = new TTFancyGifDialogListener() {
                @Override
                public void OnClick() {
                    ActivityManager manager = (ActivityManager) getActivity().getSystemService(Context.ACTIVITY_SERVICE);
                    for (ActivityManager.RunningServiceInfo service : manager.getRunningServices(Integer.MAX_VALUE)) {
                        if (SetupDex.class.getName().equals(service.service.getClassName())) {
                            SetupDex.Interropt();
                            getActivity().startService(new Intent(getActivity(), SetupDex.class));
                        }
                    }

                    getActivity().startService(new Intent(getActivity(), SetupDex.class));

                }


            };

            return a;
        }
        else {
            RTLToast.warning(getActivity(), "Dont was possible confirm your session").show();
            return null;
        }

    }

    private static String currArch(){
        String arch = System.getProperty("os.arch");
        if(arch != null){
            if((arch.contains("armv8l") || arch.contains("aarch64")))
                return "arm64-v8a";
            if((arch.contains("i686")))
                return "x86";
            if((arch.contains("armv7")))
                return "armeabi-v7a";
        }
        return "x86_64";
    }


    private static boolean isInternetAvailable(Context ctx) {
        ConnectivityManager connectivityManager = (ConnectivityManager) ctx.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }

    private MainActivity getActivity() {
        return weakActivity.get();
    }

    private ProgressDialog getDialog() {
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