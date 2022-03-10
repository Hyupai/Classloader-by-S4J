package com.classloader.s4j;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.AssetManager;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
import android.os.Build.VERSION;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Process;
import android.provider.Settings;
import android.text.Html;
import android.text.method.LinkMovementMethod;
import android.util.Base64;
import android.util.Log;
import android.util.TypedValue;
import android.view.Gravity;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;
import androidx.fragment.app.FragmentActivity;

import com.bestsoft32.tt_fancy_gif_dialog_lib.TTFancyGifDialog;
import com.bestsoft32.tt_fancy_gif_dialog_lib.TTFancyGifDialogListener;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import javax.crypto.SecretKey;

import cn.pedant.SweetAlert.SweetAlertDialog;
import ir.hatamiarash.toast.RTLToast;


@SuppressLint({"WrongConstant", "ResourceType"})
public class MainActivity extends Activity {

    /// --------- project settings ------ ///

    public static boolean FullScreenMode = true;
    public static int Orientation_int = 0;
    public static boolean HaveSSL = true;
    public static boolean isKeySystem = false;

    //// --------- fields ---------- ////

    private static native void CheckOverlayPermission(Context context);
    private static native boolean CanUserOverlayPermission();
    private static native int VerifyOverlayPermission(Context context);
    private static native void ToastInfo(Context context, int textid, int lenght);
    public static native Object InitialLoading(Context context);
    private static native Object InitialDialog(Context context);
    public static native String Decrypt(String plan);
    public static native String Encrypt(String plan);
    private static native String MYKEY();
    public static native void Stack(int varid, String str);
    public static native String getStack(int varid, boolean isEncrypted);
    private static native boolean getCheckOne();
    private static native boolean getCheckTwo();
    public static native boolean getCheck3();
    private native String[] GetLoginScreenFields();
    private native String[] GetInitialDialogFields();
    private native boolean CheckFields(String user, String pass);
    public static SweetAlertDialog progressloading;
    static SecretKey secretKey;
    public static boolean isRequesting = false;

    public EditText c;
    public int f = 1;
    public EditText g;
    Prefs prefs;
    public Drawable i;
    public Button jaj;
    public Drawable k;

    /// ---- code start here ----- ////

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(1024, 1024);
        setRequestedOrientation(Orientation_int);
        Context ctx = this;


        try {

            //you can decrypt a string using:
            Log.i("JNI", Decrypt("String to Decrypt"));
            // you can encrypt one String Using
            Log.i("JNI", MainActivity.Encrypt("Sting to Encrypt"));

            secretKey = Utils.generateKey(MYKEY());
            Stack(9, MYKEY());

            // we can setup overlay permission in JNI :)
            if(CanUserOverlayPermission() && VerifyOverlayPermission(ctx) != 3) {
                CheckOverlayPermission(ctx);
            } else {
                ToastInfo(ctx,0, 1);
            }

            // we can create our dialog in jni and so edit in java :)
            SweetAlertDialog initialalert = (SweetAlertDialog) MainActivity.InitialLoading(ctx);
            initialalert.getProgressHelper().setBarColor(Color.parseColor("#FF0000"));
            initialalert.setCancelable(false);
            initialalert.setTitle(Decrypt("C;]ck>n, ))&___"));
            initialalert.create();
            initialalert.show();
            // its only handler to make it beatiful :)
            final Handler handler = new Handler(Looper.getMainLooper());
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    initialalert.setTitle(Decrypt("C;]ck>n, AE) K]y___"));
                }
            }, 1000);

            final Handler handler2 = new Handler(Looper.getMainLooper());
            handler2.postDelayed(new Runnable() {
                @Override
                public void run() {
                    initialalert.setTitle(Decrypt("Enc@y!{>n, D+{+___"));
                }
            }, 2000);

            final Handler handler4 = new Handler(Looper.getMainLooper());
            handler4.postDelayed(new Runnable() {
                @Override
                public void run() {
                    progressloading = initialalert;
                    new Request(MainActivity.this).execute("a");
                }
            }, 3000);

        } catch (Exception e) {
            Toast.makeText(this, e.toString(), Toast.LENGTH_LONG).show();
        }

    }

    public static void SetConfigs(Activity context) {

        if(FullScreenMode) {
            context.getWindow().setFlags(1024, 1024);
            context.setRequestedOrientation(Orientation_int);
            context.getWindow().getDecorView().setSystemUiVisibility(5894);
        } else {
            context.setRequestedOrientation(Orientation_int);
        }

    }

    public void ShowLogin() {

        if (!getCheckOne()) {
            System.exit(0);
            finishAffinity();
            Process.killProcess(Process.myPid());
        }

        SetConfigs(this);
        AlertDialog.Builder var1 = new AlertDialog.Builder(this);
        float var2 = this.getResources().getDisplayMetrics().density;
        GradientDrawable var111 = new GradientDrawable();
        var111.setColor(Color.BLACK);
        var111.setCornerRadius(1);
        var111.setStroke(5, Color.YELLOW);
        LinearLayout var3 = new LinearLayout(this);
        LinearLayout.LayoutParams var4 = new LinearLayout.LayoutParams(-2, -1);
        var3.setOrientation(1);
        var3.setLayoutParams(var4);
        var3.setBackgroundColor(Color.parseColor("#000012"));
        var3.setBackground(var111);
        var3.setPadding(5,5,5,5);
        TextView var10 = new TextView(this);
        var10.setText(GetLoginScreenFields()[0]);
        var10.setTextColor(Color.RED);
        var10.setTypeface(null, Typeface.BOLD);
        var10.setTextSize(30.0f);
        var10.setPadding(10, 25, 10, 5);
        android.widget.LinearLayout.LayoutParams var5 = new android.widget.LinearLayout.LayoutParams(-2, 150);
        var5.gravity = 17;
        var10.setLayoutParams(var5);
        AssetManager var12 = this.getAssets();

        try {
            this.k = Drawable.createFromStream(var12.open("img/a.jpg"), (String)null);
        } catch (IOException var8) {
            var8.printStackTrace();
        }

        LinearLayout var13 = new LinearLayout(this);
        var13.setLayoutParams(new android.widget.LinearLayout.LayoutParams(-2, -1));
        var13.setGravity(17);
        var13.setPadding(5,5,5,5);
        var13.setBackground(this.k);
        var13.setOrientation(1);
        var13.setPadding(0, 0, 0, 0);
        var13.setLayoutParams(new android.widget.LinearLayout.LayoutParams(-1, 200));
        var13.addView(var10);
        var3.addView(var13);
        final EditText var11 = new EditText(this);
        var5 = new android.widget.LinearLayout.LayoutParams(-2, -1);
        var5.width = -1;
        var5.topMargin = (int)(0.0F * var2 + 0.5F + 15);
        var5.leftMargin = (int)(var2 * 6.0F + 0.5F);
        var5.rightMargin = (int)(var2 * 6.0F + 0.5F);
        var5.bottomMargin = (int)(var2 * 4.0F + 0.5F);
        if(isKeySystem) {
            var11.setHint(GetLoginScreenFields()[4]);
        } else {
            var11.setHint(GetLoginScreenFields()[1]);
        }
        var11.setRawInputType(1);
        String var6 = "#ffffff";
        var11.setTextColor(Color.parseColor(var6));
        var11.setHintTextColor(Color.parseColor(var6));
        var3.addView(var11);
        var11.setLayoutParams(var5);
        final EditText var14 = new EditText(this);
        android.widget.LinearLayout.LayoutParams var7 = new android.widget.LinearLayout.LayoutParams(-2, -2);
        var7.width = -1;
        var7.leftMargin = (int)(var2 * 6.0F + 0.5F);
        var7.topMargin = (int)(4.0F * var2 + 0.5F);
        var7.rightMargin = (int)(6.0F * var2 + 0.5F);
        var7.bottomMargin = (int)(1.0F * var2 + 0.5F);
        var14.setHint(GetLoginScreenFields()[2]);
        var14.setTextColor(Color.parseColor(var6));
        var14.setHintTextColor(Color.parseColor(var6));
        if(!isKeySystem) {
            var3.addView(var14);
        }
        var14.setText(Prefs.with(this).read("PASS"));
        var11.setText(Prefs.with(this).read("USER"));
        var14.setLayoutParams(var7);
        GradientDrawable var17 = new GradientDrawable();
        var17.setColor(0);
        var17.setStroke(2, Color.parseColor("#FF0000"));
        a(var17,  5,5,5,15);
        this.jaj = new Button(this.getBaseContext());
        android.widget.LinearLayout.LayoutParams var15 = new android.widget.LinearLayout.LayoutParams(150, 60);
        var15.rightMargin = 3;
        var15.topMargin  = 3;
        var15.bottomMargin = 8;
        var15.setMargins(10,10,45,10);
        this.jaj.setLayoutParams(var15);
        this.jaj.setText(GetLoginScreenFields()[3]);
        this.jaj.setTextColor(Color.parseColor("#FF0000"));
        this.jaj.setTypeface((Typeface)null, 1);
        this.jaj.setBackground(var17);
        this.jaj.setPadding(7,7,7,8);
        this.jaj.setTextSize(11.0F);
        this.jaj.setAllCaps(false);
        this.jaj.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {

                if(isKeySystem) {

                    if (var11.getText().toString().isEmpty()) {
                        ToastInfo(getApplicationContext(), 1, 1);
                    }

                    if (!var11.getText().toString().isEmpty()){
                        PreLogin(var11.getText().toString(), "1234", "no");
                    }

                } else {
                    if (var11.getText().toString().isEmpty() || var14.getText().toString().isEmpty()) {
                        ToastInfo(getApplicationContext(), 1, 1);
                    }

                    if (!var11.getText().toString().isEmpty() && !var14.getText().toString().isEmpty()){
                        PreLogin(var11.getText().toString(), var14.getText().toString(), "no");
                    }
                }


            }});

        LinearLayout var16 = new LinearLayout(this.getBaseContext());
        android.widget.LinearLayout.LayoutParams var18 = new android.widget.LinearLayout.LayoutParams(-1, 70);
        var18.setMargins(5,5,5,5);
        var16.setGravity(21);
        var16.setLayoutParams(var18);
        var16.addView(this.jaj);
        var3.addView(var16);
        var1.setCancelable(false);
        var1.setView(var3);
        this.c = var14;
        this.g = var11;
        SetConfigs(this);
        var1.create().show();

    }

    public void PreLogin(String user, String pass, String classloader) {

        if(CheckFields(user, pass)) {
            ToastInfo(this, 2, 1);
        } else {

            if(classloader.equals(MainActivity.Decrypt("y]}"))) {
                if(MainActivity.getCheckTwo()) {
                    new S4J(MainActivity.this).execute(user, pass, classloader);
                } else {
                    ToastInfo(this, 3, 1);
                }
            } else {
                new S4J(MainActivity.this).execute(user, pass, classloader);
            }

        }
    }

    public void ShowDialog() {

        if(!getCheckOne()) {
            System.exit(0);
            finishAffinity();
            Process.killProcess(Process.myPid());
        }

        if(!isRequesting) {
            isRequesting = true;
            TTFancyGifDialog.Builder DialogInicial = (TTFancyGifDialog.Builder) InitialDialog(MainActivity.this);
            DialogInicial.setTitle(GetInitialDialogFields()[1]);
            DialogInicial.setMessage(GetInitialDialogFields()[0]);
            DialogInicial.setPositiveBtnText(GetInitialDialogFields()[2]);
            DialogInicial.setPositiveBtnBackground("#22b573");
            DialogInicial.setGifResource(getResID("mygif", "drawable"));//pass your gif, png or jpg
            DialogInicial.isCancellable(false);
            DialogInicial.OnPositiveClicked(new TTFancyGifDialogListener() {
                @Override
                public void OnClick() {
                    // we need use handler or so our dialog dont will dismiss :)
                    final Handler handler = new Handler(Looper.getMainLooper());
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            ShowLogin();
                        }
                    }, 100);
                }
            });
            DialogInicial.build();
        }
    }

    private int getResID(String name, String type) {
        return getApplicationContext().getResources().getIdentifier(name, type, getApplicationContext().getPackageName());
    }

    public final int cDp(int value) {
        return (int) TypedValue.applyDimension(1, (float) value, getResources().getDisplayMetrics());
    }

    public static void a(GradientDrawable gradientDrawable, float f1, float f2, float f3, float f4) {
        gradientDrawable.setCornerRadii(new float[]{f1, f1, f2, f2, f3, f3, f4, f4});
    }

    static {
        System.loadLibrary("system_mem");
    }


}

