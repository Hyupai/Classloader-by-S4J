## Classloader Version S4J

**What is this project?**
This project consists of making a secure system through Classloader on Android. For this we will use a server and other resources in Java/JNI.
The classloader basically as the name says is a "class loader". In this way, we can load an APK dynamically and use its resources "online".

## Is this system secure?

Well, there is no system that is 100% secure. If you can, for example, encode a word to base64, you can decode it. This goes for all types of encryption. Of course, stronger encryption systems exist, but at some point they will become obsolete.

However, I can say that this system is a little more complex to break. People can look for loopholes and find them, even more so in an open source. I won't release updates so you'll have to do extra protections yourself if you want. I'll save a few more for last.

## What are the differences between this and your previous project?

Well here are some differences:

- This project uses some JNI methods for better protection...
- Use of AES to encrypt the server response
- The key for AES is generated only when the user is authenticated
- User session confirmation, etc.
- Android 12 compatibility

## Usage tips:

Knowledge of PHP, JAVA, JNI(C++) is essential. Here are some explanations regarding the methods;

- Encrypt (Android Project)

     `Log.i("JNI", MainActivity.Encrypt("String to Encrypt"));`
here you display the encrypted string in logcat

- Encrypt(PHP)

 `<?php include 'Utils.php`
 `echo EncryptByS4J("String to Encrypt)`


 - Decrypt (Android Project)

     `Log.i("JNI", MainActivity.Decrypt("String to Decrypt"));`
here you display the decrypted string in logcat

- stack

You can store a variable in your JNI using:
`MainActivity.Stack(int id, String str);`

and you can get it through:
`MainActivity.getStack(int id, bool isEncrypt);`

the bool isEncrypt is used for the Decrypt method, that is, if you store a string that was Encrypted you can automatically decrypt it;

## Concepts

**Input limit** => There is a limit of 128 bytes you can send to the server. That's why users are limited to 16 characters, as other things are also sent;

**Memory limit** => The memory limit is a server configuration, it varies from each hosting or its configuration.
If you make a request to the server and it doesn't show "Server Error" or no response this could be the cause. If your Apks/libs are too big this can happen.

**DDOS** => They can make multiple requests to your server. You can solve this using Cloudflare or filtering IPs or User Agents..

**My Sql Inject** => In this version bugs related to this were fixed. The DeviceID is obtained through the native code and the parameters are passed a check in the JNI code. Also used mysql `real_escape_string` in login.php

**App shutdown?** => Check the logcat, check the architecture versions of the libs match.

## Tips

**If your android studio is not compiling the JNI code:**

You can use the DAEMON that is in the project folder, just change the directory inside the make.bat file and run it with the JNI folder.

**How do I use implementations like Custom Toast, Alerts with GIFS?**

Implement this in the build.gradle of the app module and the loader module and use it at will.

**Can I use this in AIDE?**

Yes, as long as you know what you're doing.

**Can I sell this project?**

I don't think anyone would buy something public.

**I don't understand anything about your project, my eyes hurt**

Solution => Don't try to write an essay in German if you don't even know how to speak German.
Likewise, don't try to use this project if you don't even know how to read it.

## Updates

This project will not have updates unless there is a bug that exposes the data.
But i can close and answer yours by the Issues tab or in my Telegram: @HyupaiJoker

## I need more security

Download the NP Manager that I left in https://drive.google.com/file/d/1pd7bTFkF4b5A8BHDJbmh9LcNpWQJw7h1/view?usp=sharing and look for the **DexToC** function, it is the only one that cannot be reversed. Use it in the Main App or in the Loader, however in the Loader you will have to load it by the server.

## Known Bugs

- In the first access of the user it says something about the UID, but just click again that goes;

- Sometimes it doesn't find the APK in the cache;

- Sometimes it fails to put the user's "tempaeskey" (Same case as the UID);
