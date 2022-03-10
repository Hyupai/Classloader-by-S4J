package uk.lgl;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.provider.Settings;
import android.util.Log;
import android.util.StateSet;
import android.view.View;
import android.widget.Toast;

import com.catherine.resource1.R;

import uk.lgl.modmenu.FloatingModMenuService;


public class MainActivity extends Activity {

    public final static String TAG = "LoadedApk";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().setFlags(1024, 1024);
        getWindow().getDecorView().setSystemUiVisibility(5894);

        setContentView(View.inflate(getApplicationContext(), R.layout.main, null));
        LOG("Classloader started");
        Toast.makeText(this , "Classloader has been started! Checking your session... ", Toast.LENGTH_LONG).show();
        new Confirm(MainActivity.this).execute();

    }

    public void RealStart() {

     LOG("Real Start");
     Start(this);

    }

    public static void Start(final Context context) {
        //Check for
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(context)) {
            Toast.makeText(context.getApplicationContext(), "Overlay permission is required in order to show mod menu. Restart the game after you allow permission", Toast.LENGTH_LONG).show();
            Toast.makeText(context.getApplicationContext(), "Overlay permission is required in order to show mod menu. Restart the game after you allow permission", Toast.LENGTH_LONG).show();
            context.startActivity(new Intent("android.settings.action.MANAGE_OVERLAY_PERMISSION",
                    Uri.parse("package:" + context.getPackageName())));
            final Handler handler = new Handler();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    System.exit(1);
                }
            }, 5000);
            return;
        } else {
            final Handler handler = new Handler();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    context.startService(new Intent(context, FloatingModMenuService.class));
                }
            }, 25);
        }

        //Use getApplicationContext() to fix dark background of Toast message
       // CallToast(context);
    }


    public static void LOG(String what) {
        Log.i(TAG, what);
    }
}
