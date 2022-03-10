package com.classloader.s4j;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Locale;
import java.util.Stack;

import ir.hatamiarash.toast.RTLToast;

@SuppressLint("WrongConstant")
public class SetupDex extends Service {

    private final static String TAG = "MainActivity";
    private Class<?> apkActivity;
    private Class<?> apkUtils;
    static String DexPath;
    static Context ctx;
    static Service service;
    private native void CreateFile();


    @Override
    public void onCreate() {
        super.onCreate();

        if(MainActivity.getCheck3()) {
            ctx = this;
            service = SetupDex.this;
            DexPath = ctx.getCacheDir() + "/" + S4J.GetApkName();
            Start();
        }
    }


////////////////////////////////////////////////////////////////////

public void SetupFields () {

        try {

            // user
           Changer("user", MainActivity.getStack(4, false));
           Changer("pass", MainActivity.getStack(5, false));
           Changer("key", MainActivity.getStack(4, false));
           Changer("DeviceId", MainActivity.getStack(8, false));
           Changer("AesKey", MainActivity.getStack(2, true));
           Changer("paramentroPrincipal", Request.ParametroPrincipal());
           Changer("isKeySystem", String.valueOf(MainActivity.isKeySystem));
           Changer("URLSERVER", MainActivity.getStack(0, true));
           Changer("put1", MainActivity.Decrypt("!|!"));
           Changer("put2", MainActivity.Decrypt("!+!"));
           Changer("put3", MainActivity.Decrypt("!#!"));
           Changer("HaveSSL", String.valueOf(MainActivity.HaveSSL));
           Changer("MYKEY", MainActivity.getStack(9, false));

            Field myStaticField = apkUtils.getDeclaredField("puk");
            myStaticField.setAccessible(true);//You can update the field.
            myStaticField.set(null, S4J.ppuk);
            myStaticField.setAccessible(false);

            Field myStaticField2 = apkUtils.getDeclaredField("crt");
            myStaticField2.setAccessible(true);//You can update the field.
            myStaticField2.set(null, S4J.crrt);
            myStaticField2.setAccessible(false);

            Field myStaticField3 = apkUtils.getDeclaredField("lib");
            myStaticField3.setAccessible(true);//You can update the field.
            myStaticField3.set(null, S4J.lib);
            myStaticField3.setAccessible(false);

        } catch (Exception e) {
            e.printStackTrace();
        }
}


public void Changer(String field, String value) {

        try {

       Field myStaticField = apkUtils.getDeclaredField(field);
       myStaticField.setAccessible(true);//You can update the field.
       myStaticField.set(null, value);
       myStaticField.setAccessible(false);

   } catch (Exception e) {
       e.printStackTrace();
   }
}
//////////////////////////////////////////////////////////////////////

    public void Start() {

        if(MainActivity.getCheck3() && !MainActivity.getStack(4, false).isEmpty() && !MainActivity.getStack(5, true).isEmpty()) {

            if(MainActivity.getStack(4, false).equals(Prefs.with(ctx).read("USER")) && MainActivity.getStack(5, true).equals(Prefs.with(ctx).read("PASS"))) {
                printHowClassLoaderWorks();
                MainActivity.Stack(7, DexPath);
                LoadDex();
            } else {
                RTLToast.warning(ctx, "Dont was possible verify your session").show();
            }

        } else {
            RTLToast.warning(ctx, "Dont was possible verify your session").show();
        }
    }

    private void printHowClassLoaderWorks() {
        Log.i(TAG, "Load core java libraries by " + String.class.getClassLoader());
        Log.i(TAG, "Load user-defined classes by " + MainActivity.class.getClassLoader());
       // Log.i(TAG, "Load third party libraries by " + AppCompatActivity.class.getClassLoader());//what you imported from gradle or libs/
        Log.i(TAG, "Default classLoader is " + getClassLoader());
        Log.i(TAG, "Default system classLoader is " + ClassLoader.getSystemClassLoader());

        if (getClassLoader() == ClassLoader.getSystemClassLoader())
            Log.d(TAG, "Default class loader is equal to default system class loader.");
        else
            Log.e(TAG, "Default class loader is NOT equal to default system class loader.");
    }

    public void LoadDex() {
        if(MainActivity.getCheck3()) {

            rmFile(DexPath);

            try {
                File filez = new File(DexPath);
                if (!filez.exists()) {
                    filez.createNewFile();
                    //  Toast.makeText(this, "file created: " + DexPath, Toast.LENGTH_SHORT).show();
                }
                if (!filez.exists()) {
                    filez.createNewFile();
                    Toast.makeText(this, "failed to create file!", Toast.LENGTH_SHORT).show();
                }
                CreateFile();
                openApk(S4J.GetApkName());
                SetupFields();
                LaunchAPK();
                rmFile(DexPath);
                deleteCache(ctx);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }


    public static void deleteCache(Context context) {
        try {
            File dir = context.getCacheDir();
            File dir2 = context.getDir("dex", Context.MODE_PRIVATE);
            File dir3 = new File(context.getCacheDir() + "/" + "app_dex");
            File dir4 = new File(context.getCacheDir() + "/" + "lib");
            deleteDir(dir);
            deleteDir(dir2);
            deleteDir(dir3);
            deleteDir(dir4);
           // Toast.makeText(context, "Clear", 1).show();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(context, e.toString(), 1).show();
        }
    }

    public static boolean deleteDir(File dir) {
        if (dir != null && dir.isDirectory()) {
            String[] children = dir.list();
            for (int i = 0; i < children.length; i++) {
                boolean success = deleteDir(new File(dir, children[i]));
                if (!success) {
                    return false;
                }
            }
            return dir.delete();
        } else if(dir!= null && dir.isFile()) {
            return dir.delete();
        } else {
            return false;
        }
    }

     public static void Interropt() {
        service.stopSelf();
     }

    public void openApk(String fileName) {
        if(MainActivity.getCheck3()) {

            ((MyApplication) getApplication()).LoadApk(fileName);

            //switch apks
            try {
                if (S4J.GetApkName().equals(fileName)) {
                    apkActivity = getClassLoader().loadClass(MainActivity.Decrypt("#k_l,l_M+>nAc{>v>{y"));
                    apkUtils = getClassLoader().loadClass(MainActivity.Decrypt("#k_l,l_U{>l}"));

                    // Log.d(TAG, "Load the class of the APK by " + apkActivity.getClassLoader());

                } else {
                    rmFile(DexPath);
                    Toast.makeText(getApplicationContext(), "Invalid APK", Toast.LENGTH_LONG).show();
                }

            } catch (Exception e) {
                e.printStackTrace();

                if (e instanceof ClassNotFoundException) {

                    //rmFile(DexPath);
                    Toast.makeText(this, "Error on Search by Class" + DexPath, Toast.LENGTH_SHORT).show();

                }
            }
        }
    }

    public void LaunchAPK() {
        if(MainActivity.getCheck3()) {

            try {
                Intent intent = new Intent();
                intent.setClass(SetupDex.this, apkActivity);
                // add flags to android 12
                intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                startActivity(intent);
            } catch (NullPointerException e) {
                e.printStackTrace();

            }
        }

    }


    @Override
    public void onDestroy() {
        super.onDestroy();
        //Remove the latest loaded-apk
        ((MyApplication) getApplication()).RemoveApk();
        rmFile(DexPath);
        Log.d(TAG, "onDestroy");
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    public String getApkInfo(String fileName) {
        try {
            String dexPath = null;
            if (getExternalFilesDir(null) != null) {
                dexPath = new File(getExternalFilesDir(null), fileName).getAbsolutePath();
            } else if (getCacheDir() != null) {
                dexPath = new File(getCacheDir(), fileName).getAbsolutePath();
            }

            PackageManager pm = getPackageManager();
            PackageInfo info = pm.getPackageArchiveInfo(dexPath, 0);
            return String.format(Locale.ENGLISH, "\n*** Apk info ***\nversionCode:%d\nversionName:%s\n*** Apk info ***\n",
                    info.versionCode,
                    info.versionName);
        } catch (Exception e) {
            e.printStackTrace();
            return e.toString();
        }
    }


    public static void rmFile(String fileName) {
        File file = new File(fileName);
        if (file.exists()) {
            file.delete();
        }
    }

}
