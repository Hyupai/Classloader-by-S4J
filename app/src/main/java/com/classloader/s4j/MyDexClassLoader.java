package com.classloader.s4j;

import android.app.Activity;
import android.app.Application;
import android.app.Service;
import android.content.Context;
import android.content.res.Resources;
import android.util.Log;

import java.net.URL;
import java.util.Enumeration;

import dalvik.system.DexClassLoader;

    public class MyDexClassLoader extends DexClassLoader {
        private static final String TAG = "MyDexClassLoader";

        /**
         * @param Application MyApplication
         * @param dexPath     String: the list of jar/apk files containing classes and resources, delimited by File.pathSeparator, which defaults to ":" on Android
         * @param soPath      native libraries (path of .so files)
         * @param classloader the parent class loader
         */
        public MyDexClassLoader(Application Application, String dexPath, String soPath, ClassLoader classloader) {
            super(dexPath, Application.getDir("dex", Context.MODE_PRIVATE).getAbsolutePath(), soPath.replace("files", "lib"),
                    classloader);

            Log.i(TAG, "DexClassLoader " + classloader.toString());
            Log.i(TAG, "dexPath " + dexPath);
            Log.i(TAG, "optimizedDirectory " + Application.getDir("dex", Context.MODE_PRIVATE).getAbsolutePath());
            Log.i(TAG, "soPath_lib " + soPath);
            Log.i(TAG, "librarySearchPath " + soPath.replace("files", "lib"));

        }

        @Override
        protected Class<?> findClass(String name) throws ClassNotFoundException {
            Log.i(TAG, "findClass:" + name);
            return super.findClass(name);
        }

        @Override
        public String findLibrary(String name) {
            Log.i(TAG, "findLibrary:" + name);
            return super.findLibrary(name);
        }

        @Override
        protected URL findResource(String name) {
            Log.i(TAG, "findResource:" + name);
            return super.findResource(name);
        }

        @Override
        protected Enumeration<URL> findResources(String name) {
            Log.i(TAG, "findResources:" + name);
            return super.findResources(name);
        }

        @Override
        protected synchronized Package getPackage(String name) {
            Log.i(TAG, "getPackage:" + name);
            return super.getPackage(name);
        }

        @Override
        public Class<?> loadClass(String name) throws ClassNotFoundException{
            Log.d(TAG, "loadClass:" + name);
            return super.loadClass(name);
        }

        @Override
        protected Class<?> loadClass(String name, boolean resolve) throws ClassNotFoundException{
            Log.d(TAG, "loadClass:" + name + " : " + resolve);
            return super.loadClass(name, resolve);
        }
    }