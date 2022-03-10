#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sstream>
#include <jni.h>
#include "obfuscate.h"
#include "skdversion.h"
#include "Logger.h"
#include "sha256.h"

using namespace std;
/*
 *  Thanks to following projects and sources:
 *
 *  - LGL MOD MENU -> https://github.com/LGLTeam/Android-Mod-Menu
 *  - CLASSLOADER -> https://github.com/Catherine22/ClassLoader
 *  - SERVER AND CONNECTION -> https://github.com/kp7742/PUBGPatcher
 *
 */

extern  "C" {

/// ----- Important Things --------  ///
bool CheckOne = false;
bool CheckTwo = false;
bool Check3 = false;

// you need encrypt urlserver using the apk in app folder to setup :)
static const char* Parametro1 = OBFUSCATE("key");
static const char* Valor1 = OBFUSCATE("LPNGuhasd654823nskmfdsdoijdskajsdh7248739486");
static const char* ParametroPrincipal = OBFUSCATE("SamuelForJuliana");
static const char* AESKEY = OBFUSCATE("SAMUELFORJULIANA");
static const char* ClassloaderName = NULL;


static const char* ToastInfoTexts[] = {

        OBFUSCATE("Your device need be android 6+, or you dont have allowed permission"), // 0
        OBFUSCATE("Please Fill all the fields requireds"), // 1
        OBFUSCATE("Invalid given characters or more than 16 chars"), // 2
        OBFUSCATE("You dont have permission to make this request") // 3

};

static const char* InitialDialog[] = {

        OBFUSCATE("This project was made by Samuel Filipe (old Hyupai), do not share this source with others and guarantee your application.\n\nThe version of this project is in honor of a special person to me.\n\nMyTelegram = @HyupaiJoker"), // text
        OBFUSCATE("Warning"), // title
        OBFUSCATE("OK") // Button Text

};

jobjectArray GetLoginScreenFields(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {

            OBFUSCATE("Make Login"), // Title
            OBFUSCATE("Username"), // Username Field
            OBFUSCATE("Password"), // Password Field
            OBFUSCATE("Login"), // Button
            OBFUSCATE("Your Key: "), // keyField
    };

    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
   if(CheckOne) {
       return (ret);
   } else {
       return NULL;
   }
}

jobjectArray GetInitialDialogFields(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {

            InitialDialog[0], // 0
            InitialDialog[1], //1
            InitialDialog[2] // 2
    };

    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    if(CheckOne) {
        return (ret);
    } else {
        return NULL;
    }
}

//// --- here code start ---- ///

// we can store still 11 values into char dont modify
static const char* Storage[] = {

        OBFUSCATE(""), // 0
        OBFUSCATE(""), // 1
        OBFUSCATE(""), // 2
        OBFUSCATE(""), // 3
        OBFUSCATE(""), // 4
        OBFUSCATE(""), // 5
        OBFUSCATE(""), // 6
        OBFUSCATE(""), // 7
        OBFUSCATE(""), // 8
        OBFUSCATE(""), // 9
        OBFUSCATE(""), // 10
        OBFUSCATE("") // 11

};

static bool getCheckOneValue() {
    return CheckOne;
}

static bool getCheckTwoValue() {
    return CheckTwo;
}

static bool getCheck3Value() {
    return Check3;
}

  /// --- Request.java Fields ---------- ///

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_Request_Valor1
        (JNIEnv * env, jobject obj) {
    return env->NewStringUTF(Valor1);
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_Request_Parametro1
        (JNIEnv * env, jobject obj) {
    return env->NewStringUTF(Parametro1);
}

JNIEXPORT jbyteArray JNICALL Java_com_classloader_s4j_Request_puk
        (JNIEnv *env, jobject This)
{
    jbyte a[] = {48, -127, -97, 48, 13, 6, 9, 42, -122, 72, -122, -9, 13, 1, 1, 1, 5, 0, 3, -127, -115, 0, 48, -127, -119, 2, -127, -127, 0, -41, 36, -11, -27, -61, 32, 124, 58, 39, -94, -13, 7, 48, -104, -109, 106, -75, -8, -128, -92, -89, -125, -49, -83, 75, 12, -26, 90, 56, 35, 52, -116, 30, 40, -69, -70, 86, 14, -80, -20, 55, -89, 104, -46, -17, -80, -119, 83, -14, 116, -66, 11, -108, 5, 76, 12, -43, -89, -49, 11, 38, -124, 71, 45, 65, -103, 10, 99, 33, 79, 21, -16, -38, -60, 24, -108, 101, -89, -18, 48, -37, -78, 59, 10, 89, 42, 51, -43, 9, -33, -68, 61, -45, 94, -49, 83, 52, 56, 105, -123, 18, 89, 3, 54, -48, -63, -61, -103, -9, 79, -36, 18, 119, 11, -35, 82, 73, -66, 12, 123, -38, 97, 121, -30, 31, -50, -106, 127, 2, 3, 1, 0, 1};
    jbyteArray ret = env->NewByteArray(162);
    env->SetByteArrayRegion (ret, 0, 162, a);
    return ret;
}

JNIEXPORT jbyteArray JNICALL Java_com_classloader_s4j_Request_crt
        (JNIEnv *env, jobject This)
{
    jbyte a[] = {45, 45, 45, 45, 45, 66, 69, 71, 73, 78, 32, 67, 69, 82, 84, 73, 70, 73, 67, 65, 84, 69, 45, 45, 45, 45, 45, 13, 10, 77, 73, 73, 70, 54, 122, 67, 67, 66, 78, 79, 103, 65, 119, 73, 66, 65, 103, 73, 82, 65, 73, 68, 53, 88, 53, 112, 118, 85, 72, 71, 112, 43, 81, 49, 84, 54, 88, 103, 117, 67, 78, 81, 119, 68, 81, 89, 74, 75, 111, 90, 73, 104, 118, 99, 78, 65, 81, 69, 76, 66, 81, 65, 119, 13, 10, 99, 106, 69, 76, 77, 65, 107, 71, 65, 49, 85, 69, 66, 104, 77, 67, 86, 86, 77, 120, 67, 122, 65, 74, 66, 103, 78, 86, 66, 65, 103, 84, 65, 108, 82, 89, 77, 82, 65, 119, 68, 103, 89, 68, 86, 81, 81, 72, 69, 119, 100, 73, 98, 51, 86, 122, 100, 71, 57, 117, 77, 82, 85, 119, 13, 10, 69, 119, 89, 68, 86, 81, 81, 75, 69, 119, 120, 106, 85, 71, 70, 117, 90, 87, 119, 115, 73, 69, 108, 117, 89, 121, 52, 120, 76, 84, 65, 114, 66, 103, 78, 86, 66, 65, 77, 84, 74, 71, 78, 81, 89, 87, 53, 108, 98, 67, 119, 103, 83, 87, 53, 106, 76, 105, 66, 68, 90, 88, 74, 48, 13, 10, 97, 87, 90, 112, 89, 50, 70, 48, 97, 87, 57, 117, 73, 69, 70, 49, 100, 71, 104, 118, 99, 109, 108, 48, 101, 84, 65, 101, 70, 119, 48, 120, 79, 84, 65, 51, 77, 68, 77, 119, 77, 68, 65, 119, 77, 68, 66, 97, 70, 119, 48, 120, 79, 84, 69, 119, 77, 68, 69, 121, 77, 122, 85, 53, 13, 10, 78, 84, 108, 97, 77, 66, 77, 120, 69, 84, 65, 80, 66, 103, 78, 86, 66, 65, 77, 84, 67, 71, 116, 116, 98, 50, 82, 122, 76, 109, 49, 115, 77, 73, 73, 66, 73, 106, 65, 78, 66, 103, 107, 113, 104, 107, 105, 71, 57, 119, 48, 66, 65, 81, 69, 70, 65, 65, 79, 67, 65, 81, 56, 65, 13, 10, 77, 73, 73, 66, 67, 103, 75, 67, 65, 81, 69, 65, 113, 68, 77, 48, 52, 103, 116, 121, 106, 80, 76, 114, 117, 97, 113, 103, 70, 84, 56, 71, 99, 49, 112, 103, 68, 48, 77, 49, 71, 78, 49, 86, 43, 49, 78, 56, 89, 102, 76, 50, 89, 65, 98, 48, 105, 100, 118, 48, 100, 87, 108, 116, 13, 10, 66, 106, 43, 116, 49, 100, 117, 82, 111, 80, 52, 55, 89, 43, 98, 81, 65, 69, 104, 79, 67, 43, 47, 110, 108, 97, 88, 113, 115, 115, 85, 65, 101, 116, 72, 68, 67, 69, 89, 100, 79, 54, 117, 110, 109, 88, 71, 113, 48, 82, 75, 119, 53, 114, 79, 80, 77, 103, 65, 113, 99, 81, 79, 48, 13, 10, 50, 86, 81, 85, 80, 86, 56, 120, 53, 119, 85, 111, 121, 85, 52, 76, 115, 121, 54, 98, 79, 57, 86, 48, 68, 83, 72, 120, 89, 77, 114, 71, 43, 97, 107, 83, 65, 56, 121, 73, 82, 87, 104, 77, 81, 84, 115, 51, 105, 109, 118, 78, 111, 73, 78, 83, 90, 111, 111, 70, 72, 110, 75, 100, 13, 10, 115, 83, 76, 68, 79, 89, 81, 78, 51, 118, 80, 112, 121, 53, 75, 121, 69, 116, 76, 110, 70, 84, 116, 88, 83, 89, 49, 74, 120, 79, 67, 71, 52, 52, 88, 114, 106, 119, 83, 82, 97, 122, 79, 66, 117, 84, 121, 102, 86, 98, 56, 100, 116, 88, 79, 83, 118, 78, 85, 101, 69, 88, 104, 52, 13, 10, 118, 107, 72, 54, 103, 109, 90, 98, 67, 83, 53, 98, 71, 99, 117, 88, 118, 89, 49, 71, 77, 114, 97, 68, 114, 117, 116, 50, 89, 83, 121, 72, 48, 71, 80, 102, 65, 73, 119, 75, 83, 112, 120, 90, 47, 52, 82, 74, 75, 97, 85, 67, 75, 49, 114, 56, 48, 103, 79, 57, 67, 121, 76, 50, 13, 10, 57, 78, 100, 117, 100, 101, 77, 100, 103, 71, 85, 72, 88, 122, 80, 80, 87, 70, 122, 56, 100, 73, 117, 72, 49, 119, 104, 109, 108, 56, 68, 48, 88, 119, 73, 68, 65, 81, 65, 66, 111, 52, 73, 67, 50, 84, 67, 67, 65, 116, 85, 119, 72, 119, 89, 68, 86, 82, 48, 106, 66, 66, 103, 119, 13, 10, 70, 111, 65, 85, 102, 103, 78, 97, 90, 85, 70, 114, 112, 51, 52, 75, 52, 98, 105, 100, 67, 79, 111, 100, 106, 104, 49, 113, 120, 50, 85, 119, 72, 81, 89, 68, 86, 82, 48, 79, 66, 66, 89, 69, 70, 77, 113, 103, 116, 109, 77, 102, 100, 97, 84, 87, 76, 108, 97, 107, 72, 107, 99, 116, 13, 10, 83, 112, 72, 77, 70, 122, 69, 48, 77, 65, 52, 71, 65, 49, 85, 100, 68, 119, 69, 66, 47, 119, 81, 69, 65, 119, 73, 70, 111, 68, 65, 77, 66, 103, 78, 86, 72, 82, 77, 66, 65, 102, 56, 69, 65, 106, 65, 65, 77, 66, 48, 71, 65, 49, 85, 100, 74, 81, 81, 87, 77, 66, 81, 71, 13, 10, 67, 67, 115, 71, 65, 81, 85, 70, 66, 119, 77, 66, 66, 103, 103, 114, 66, 103, 69, 70, 66, 81, 99, 68, 65, 106, 66, 80, 66, 103, 78, 86, 72, 83, 65, 69, 83, 68, 66, 71, 77, 68, 111, 71, 67, 121, 115, 71, 65, 81, 81, 66, 115, 106, 69, 66, 65, 103, 73, 48, 77, 67, 115, 119, 13, 10, 75, 81, 89, 73, 75, 119, 89, 66, 66, 81, 85, 72, 65, 103, 69, 87, 72, 87, 104, 48, 100, 72, 66, 122, 79, 105, 56, 118, 99, 50, 86, 106, 100, 88, 74, 108, 76, 109, 78, 118, 98, 87, 57, 107, 98, 121, 53, 106, 98, 50, 48, 118, 81, 49, 66, 84, 77, 65, 103, 71, 66, 109, 101, 66, 13, 10, 68, 65, 69, 67, 65, 84, 66, 77, 66, 103, 78, 86, 72, 82, 56, 69, 82, 84, 66, 68, 77, 69, 71, 103, 80, 54, 65, 57, 104, 106, 116, 111, 100, 72, 82, 119, 79, 105, 56, 118, 89, 51, 74, 115, 76, 109, 78, 118, 98, 87, 57, 107, 98, 50, 78, 104, 76, 109, 78, 118, 98, 83, 57, 106, 13, 10, 85, 71, 70, 117, 90, 87, 120, 74, 98, 109, 78, 68, 90, 88, 74, 48, 97, 87, 90, 112, 89, 50, 70, 48, 97, 87, 57, 117, 81, 88, 86, 48, 97, 71, 57, 121, 97, 88, 82, 53, 76, 109, 78, 121, 98, 68, 66, 57, 66, 103, 103, 114, 66, 103, 69, 70, 66, 81, 99, 66, 65, 81, 82, 120, 13, 10, 77, 71, 56, 119, 82, 119, 89, 73, 75, 119, 89, 66, 66, 81, 85, 72, 77, 65, 75, 71, 79, 50, 104, 48, 100, 72, 65, 54, 76, 121, 57, 106, 99, 110, 81, 117, 89, 50, 57, 116, 98, 50, 82, 118, 89, 50, 69, 117, 89, 50, 57, 116, 76, 50, 78, 81, 89, 87, 53, 108, 98, 69, 108, 117, 13, 10, 89, 48, 78, 108, 99, 110, 82, 112, 90, 109, 108, 106, 89, 88, 82, 112, 98, 50, 53, 66, 100, 88, 82, 111, 98, 51, 74, 112, 100, 72, 107, 117, 89, 51, 74, 48, 77, 67, 81, 71, 67, 67, 115, 71, 65, 81, 85, 70, 66, 122, 65, 66, 104, 104, 104, 111, 100, 72, 82, 119, 79, 105, 56, 118, 13, 10, 98, 50, 78, 122, 99, 67, 53, 106, 98, 50, 49, 118, 90, 71, 57, 106, 89, 83, 53, 106, 98, 50, 48, 119, 77, 65, 89, 68, 86, 82, 48, 82, 66, 67, 107, 119, 74, 52, 73, 73, 97, 50, 49, 118, 90, 72, 77, 117, 98, 87, 121, 67, 68, 87, 49, 104, 97, 87, 119, 117, 97, 50, 49, 118, 13, 10, 90, 72, 77, 117, 98, 87, 121, 67, 68, 72, 100, 51, 100, 121, 53, 114, 98, 87, 57, 107, 99, 121, 53, 116, 98, 68, 67, 67, 65, 81, 81, 71, 67, 105, 115, 71, 65, 81, 81, 66, 49, 110, 107, 67, 66, 65, 73, 69, 103, 102, 85, 69, 103, 102, 73, 65, 56, 65, 66, 50, 65, 76, 118, 90, 13, 10, 51, 55, 119, 102, 105, 110, 71, 49, 107, 53, 81, 106, 108, 54, 113, 83, 101, 48, 99, 52, 86, 53, 85, 75, 113, 49, 76, 111, 71, 112, 67, 87, 90, 68, 97, 79, 72, 116, 71, 70, 65, 65, 65, 66, 97, 55, 108, 90, 120, 106, 81, 65, 65, 65, 81, 68, 65, 69, 99, 119, 82, 81, 73, 104, 13, 10, 65, 79, 87, 50, 80, 65, 114, 105, 114, 77, 84, 54, 57, 116, 75, 52, 112, 107, 121, 50, 108, 108, 74, 84, 51, 112, 117, 79, 77, 122, 76, 114, 106, 73, 87, 82, 52, 119, 71, 54, 119, 72, 104, 49, 65, 105, 65, 116, 117, 107, 121, 114, 78, 111, 71, 86, 90, 65, 87, 115, 43, 50, 74, 101, 13, 10, 65, 107, 57, 107, 87, 76, 104, 57, 76, 72, 121, 104, 98, 66, 80, 43, 49, 66, 83, 68, 121, 50, 74, 71, 100, 119, 66, 50, 65, 72, 82, 43, 50, 111, 77, 120, 114, 84, 77, 81, 107, 83, 71, 99, 122, 105, 86, 80, 81, 110, 68, 67, 118, 47, 49, 101, 81, 105, 65, 73, 120, 106, 99, 49, 13, 10, 101, 101, 89, 81, 101, 56, 120, 87, 65, 65, 65, 66, 97, 55, 108, 90, 120, 108, 77, 65, 65, 65, 81, 68, 65, 69, 99, 119, 82, 81, 73, 103, 81, 102, 103, 118, 90, 66, 85, 80, 100, 102, 122, 119, 100, 67, 83, 67, 101, 118, 77, 80, 75, 52, 79, 57, 105, 80, 111, 101, 101, 75, 98, 74, 13, 10, 67, 120, 56, 85, 89, 69, 109, 74, 105, 109, 111, 67, 73, 81, 68, 121, 120, 107, 43, 113, 98, 104, 85, 70, 54, 49, 89, 53, 114, 79, 68, 117, 47, 52, 122, 72, 118, 116, 116, 105, 53, 66, 56, 85, 114, 120, 65, 73, 109, 82, 109, 86, 52, 115, 65, 85, 117, 68, 65, 78, 66, 103, 107, 113, 13, 10, 104, 107, 105, 71, 57, 119, 48, 66, 65, 81, 115, 70, 65, 65, 79, 67, 65, 81, 69, 65, 70, 72, 116, 51, 47, 102, 87, 115, 80, 111, 110, 47, 55, 74, 81, 72, 84, 50, 66, 76, 82, 111, 50, 112, 55, 103, 111, 73, 73, 51, 52, 112, 115, 121, 103, 67, 50, 55, 72, 106, 87, 120, 110, 109, 13, 10, 57, 50, 121, 102, 107, 74, 68, 106, 113, 87, 99, 90, 56, 110, 79, 48, 113, 73, 114, 116, 100, 79, 85, 84, 103, 114, 115, 108, 82, 83, 89, 67, 111, 71, 97, 108, 111, 49, 119, 90, 81, 54, 107, 73, 71, 89, 117, 71, 115, 97, 89, 121, 110, 71, 78, 68, 67, 56, 109, 47, 86, 76, 52, 75, 13, 10, 116, 72, 65, 110, 120, 108, 49, 79, 106, 49, 105, 68, 77, 117, 43, 48, 89, 115, 113, 114, 69, 80, 72, 107, 78, 111, 81, 109, 118, 99, 108, 47, 75, 86, 88, 74, 47, 121, 74, 122, 68, 56, 118, 114, 69, 74, 47, 107, 110, 103, 55, 106, 51, 85, 51, 101, 115, 122, 98, 114, 69, 71, 117, 90, 13, 10, 79, 54, 77, 122, 105, 90, 47, 54, 121, 105, 56, 56, 108, 65, 109, 65, 81, 71, 79, 103, 105, 84, 108, 76, 117, 113, 69, 68, 97, 110, 57, 112, 107, 116, 76, 72, 78, 55, 84, 115, 82, 53, 85, 50, 119, 84, 103, 68, 112, 50, 111, 83, 114, 116, 50, 52, 110, 49, 111, 90, 116, 47, 115, 117, 13, 10, 49, 53, 66, 47, 82, 119, 55, 97, 116, 74, 78, 43, 49, 66, 110, 83, 43, 47, 102, 81, 108, 51, 98, 118, 57, 80, 97, 108, 56, 48, 65, 80, 66, 88, 107, 121, 100, 97, 90, 109, 50, 90, 120, 86, 68, 103, 49, 65, 83, 105, 47, 118, 119, 120, 55, 68, 49, 106, 104, 101, 71, 81, 111, 100, 13, 10, 56, 66, 115, 88, 48, 53, 110, 80, 73, 83, 51, 68, 111, 97, 79, 83, 121, 85, 76, 83, 106, 66, 76, 120, 109, 111, 51, 111, 86, 81, 106, 69, 55, 116, 48, 106, 99, 115, 66, 47, 87, 65, 61, 61, 13, 10, 45, 45, 45, 45, 45, 69, 78, 68, 32, 67, 69, 82, 84, 73, 70, 73, 67, 65, 84, 69, 45, 45, 45, 45, 45};
    jbyteArray ret = env->NewByteArray(2146);
    env->SetByteArrayRegion (ret, 0, 2146, a);
    return ret;
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_Request_CheckOne
        (JNIEnv * env, jobject obj) {

    CheckOne = true;

    return env->NewStringUTF("Checked!");
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_Request_ParametroPrincipal
        (JNIEnv * env, jobject obj) {

    CheckOne = true;
    LOGI("Checked One");

    return env->NewStringUTF(ParametroPrincipal);
}

//// ----- s4J.java fields --------------- ///

std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

JNIEXPORT jbyteArray JNICALL Java_com_classloader_s4j_S4J_puk
        (JNIEnv *env, jobject This)
{
    jbyte a[] = {48, -127, -97, 48, 13, 6, 9, 42, -122, 72, -122, -9, 13, 1, 1, 1, 5, 0, 3, -127, -115, 0, 48, -127, -119, 2, -127, -127, 0, -41, 36, -11, -27, -61, 32, 124, 58, 39, -94, -13, 7, 48, -104, -109, 106, -75, -8, -128, -92, -89, -125, -49, -83, 75, 12, -26, 90, 56, 35, 52, -116, 30, 40, -69, -70, 86, 14, -80, -20, 55, -89, 104, -46, -17, -80, -119, 83, -14, 116, -66, 11, -108, 5, 76, 12, -43, -89, -49, 11, 38, -124, 71, 45, 65, -103, 10, 99, 33, 79, 21, -16, -38, -60, 24, -108, 101, -89, -18, 48, -37, -78, 59, 10, 89, 42, 51, -43, 9, -33, -68, 61, -45, 94, -49, 83, 52, 56, 105, -123, 18, 89, 3, 54, -48, -63, -61, -103, -9, 79, -36, 18, 119, 11, -35, 82, 73, -66, 12, 123, -38, 97, 121, -30, 31, -50, -106, 127, 2, 3, 1, 0, 1};
    jbyteArray ret = env->NewByteArray(162);
    env->SetByteArrayRegion (ret, 0, 162, a);
    return ret;
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_S4J_CheckTwo
        (JNIEnv * env, jobject obj) {

    CheckTwo = true;

    return env->NewStringUTF("Checked Two!");
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_S4J_Check3
        (JNIEnv * env, jobject obj) {

    Check3 = true;

    return env->NewStringUTF("Checked 3!");
}

JNIEXPORT void JNICALL Java_com_classloader_s4j_S4J_SetApkName
        (JNIEnv * env, jobject obj, jstring apkname) {

   if(Check3) {
       ClassloaderName = env->GetStringUTFChars(apkname, 0);
   }

    return;
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_S4J_GetApkName
        (JNIEnv * env, jobject obj, jstring apkname) {

    if(Check3) {
        return env->NewStringUTF(ClassloaderName);
    } else {
        return NULL;
    }

}

void AlertDialog( JNIEnv *env, jobject ctx, jobject clicklistener){

    jclass Alert = env->FindClass(OBFUSCATE("android/app/AlertDialog$Builder"));
    jmethodID AlertCons = env->GetMethodID(Alert, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;)V"));

    jobject MainAlert = env->NewObject(Alert, AlertCons, ctx);

    jmethodID setTitle = env->GetMethodID(Alert, OBFUSCATE("setTitle"), OBFUSCATE("(Ljava/lang/CharSequence;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setTitle, env->NewStringUTF(OBFUSCATE("Welcome - Info")));

    jmethodID setMsg = env->GetMethodID(Alert, OBFUSCATE("setMessage"), OBFUSCATE("(Ljava/lang/CharSequence;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setMsg, env->NewStringUTF(Storage[3]));

    jmethodID setCa = env->GetMethodID(Alert, OBFUSCATE("setCancelable"), OBFUSCATE("(Z)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setCa, false);

    jmethodID setPB = env->GetMethodID(Alert, OBFUSCATE("setPositiveButton"), OBFUSCATE("(Ljava/lang/CharSequence;Landroid/content/DialogInterface$OnClickListener;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setPB, env->NewStringUTF("Continue"), static_cast<jobject>(clicklistener));

    jmethodID create = env->GetMethodID(Alert, OBFUSCATE("create"), OBFUSCATE("()Landroid/app/AlertDialog;"));
    jobject creaetob = env->CallObjectMethod(MainAlert, create);

    jclass AlertN = env->FindClass(OBFUSCATE("android/app/AlertDialog"));

    jmethodID show = env->GetMethodID(AlertN, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(creaetob, show);
}

jobject AlertDialogGif( JNIEnv *env, jobject ctx, jint gif, jobject clicklistener1, jobject clicklistener2){

jclass Alert = env->FindClass(OBFUSCATE("com/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder"));
jmethodID AlertCons = env->GetMethodID(Alert, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/app/Activity;)V"));

jobject MainAlert = env->NewObject(Alert, AlertCons, ctx);

jmethodID setTitle = env->GetMethodID(Alert, OBFUSCATE("setTitle"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setTitle, env->NewStringUTF(OBFUSCATE("Welcome - Info")));

jmethodID setMsg = env->GetMethodID(Alert, OBFUSCATE("setMessage"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setMsg, env->NewStringUTF(Storage[3]));

jmethodID setCa = env->GetMethodID(Alert, OBFUSCATE("isCancellable"), OBFUSCATE("(Z)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setCa, false);

jmethodID setBtn1 = env->GetMethodID(Alert, OBFUSCATE("setPositiveBtnText"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setBtn1, env->NewStringUTF("Continue"));

jmethodID setBtn2 = env->GetMethodID(Alert, OBFUSCATE("setNegativeBtnText"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setBtn2, env->NewStringUTF("Cancel"));

jmethodID setBtn2Color = env->GetMethodID(Alert, OBFUSCATE("setNegativeBtnBackground"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setBtn2Color, env->NewStringUTF("#FF0000"));

jmethodID setBtn1Color = env->GetMethodID(Alert, OBFUSCATE("setPositiveBtnBackground"), OBFUSCATE("(Ljava/lang/String;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setBtn1Color, env->NewStringUTF("#22b573"));

jmethodID setGif = env->GetMethodID(Alert, OBFUSCATE("setGifResource"), OBFUSCATE("(I)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setGif, gif);

jmethodID setPB = env->GetMethodID(Alert, OBFUSCATE("OnPositiveClicked"), OBFUSCATE("(Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialogListener;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setPB, static_cast<jobject>(clicklistener1));

jmethodID setPB2 = env->GetMethodID(Alert, OBFUSCATE("OnNegativeClicked"), OBFUSCATE("(Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialogListener;)Lcom/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder;"));
env->CallObjectMethod(MainAlert, setPB2, static_cast<jobject>(clicklistener2));

return MainAlert;

}

JNIEXPORT jobject JNICALL Java_com_classloader_s4j_S4J_InitAlert
        (JNIEnv * env, jobject obj, jobject ctx,  jint gifif, jobject clicklistener1, jobject clicklistener2) {

    if(Check3) {

        return AlertDialogGif(env, ctx, gifif, clicklistener1, clicklistener2);
    } else {
        return NULL;
    }

}

std::string getPublicStaticString(JNIEnv *env, const char *className, const char *fieldName) {
    jclass clazz = env->FindClass(className);
    if (clazz != nullptr) {
        jfieldID fid = env->GetStaticFieldID(clazz, fieldName, "Ljava/lang/String;");
        if (fid != nullptr) {
            jstring GladioReceiver = (jstring) env->GetStaticObjectField(clazz, fid);
            jboolean blnIsCopy;
            std::string mystr = env->GetStringUTFChars(GladioReceiver, &blnIsCopy);
            return mystr;
        }
    }
    return "ERROR";
}

std::string CreateDeviceUniqueID(JNIEnv *env) {
    std::string strReturn;
    std::string board = getPublicStaticString(env, "android/os/Build", "BOARD");
    std::string brand = getPublicStaticString(env, "android/os/Build", "BRAND");
    std::string display = getPublicStaticString(env, "android/os/Build", "DISPLAY");
    std::string device = getPublicStaticString(env, "android/os/Build", "DEVICE");
    std::string manufacturer = getPublicStaticString(env, "android/os/Build", "MANUFACTURER");
    std::string model = getPublicStaticString(env, "android/os/Build", "MODEL");
    std::string product = getPublicStaticString(env, "android/os/Build", "PRODUCT");

    int mod = 10;
    int a1 = ((int) board.size()) % mod;
    int a2 = ((int) brand.size()) % mod;
    int a3 = ((int) display.size()) % mod;
    int a4 = ((int) device.size()) % mod;
    int a5 = ((int) manufacturer.size()) % mod;
    int a6 = ((int) model.size()) % mod;
    int a7 = ((int) product.size()) % mod;

    strReturn = "35" +
                std::to_string(a1) +
                std::to_string(a2) +
                std::to_string(a3) +
                std::to_string(a4) +
                std::to_string(a5) +
                std::to_string(a6) +
                std::to_string(a7);

    return strReturn;
}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_S4J_getDeviceID
        (JNIEnv *env, jobject This, jobject context)
{

    const int ANDROID_ID_SIZE = 15;
    const char *settings_name = "android/provider/Settings$Secure";
    const char *context_name = "android/content/Context";

    jclass class_settings_secure = env->FindClass(settings_name);
    jclass class_context = env->FindClass(context_name);

    if(class_settings_secure == nullptr || class_context == nullptr){
        return env->NewStringUTF("Not found!");
    }

    //Get the getContentResolver method
    jmethodID m_get_content_resolver = env->GetMethodID(
            class_context,
            "getContentResolver",
            "()Landroid/content/ContentResolver;");

    if(m_get_content_resolver == nullptr){
        return env->NewStringUTF("Not found ContentResolver");
    }

    // get Secure.ANDROID_ID
    jfieldID f_android_id = env->GetStaticFieldID(class_settings_secure, "ANDROID_ID", "Ljava/lang/String;");

    if(f_android_id == nullptr){
        return env->NewStringUTF("Not found ANDROID_ID field");
    }

    jobject s_android_id = env->GetStaticObjectField(class_settings_secure, f_android_id);

    //create a ContentResolver instance context.getContentResolver()
    jobject o_content_resolver = env->CallObjectMethod(context, m_get_content_resolver);
    if(o_content_resolver == nullptr || s_android_id == nullptr){
        return env->NewStringUTF("Not create content resolver instance!");
    }

    //get the method getString
    jmethodID m_get_string = env->GetStaticMethodID(
            class_settings_secure,
            "getString",
            "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;");

    if(m_get_string == nullptr){
        return env->NewStringUTF("Not create content resolver instance string!");
    }

    //get the Android ID
    auto android_id = (jstring) env->CallStaticObjectMethod(class_settings_secure,
                                                            m_get_string,
                                                            o_content_resolver,
                                                            s_android_id);

    // generate SHA-256 from ANDROID_ID
    jboolean isCopy;
    const char *convertedValue = env->GetStringUTFChars(android_id, &isCopy);
    string src_comp = "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;";
    string src_str = string(convertedValue, ANDROID_ID_SIZE) + CreateDeviceUniqueID(env);

    //vector<unsigned char> hash(picosha2::k_digest_size);
    //picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());

    //string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());

    return env->NewStringUTF(src_str.c_str());

}

JNIEXPORT jbyteArray JNICALL Java_com_classloader_s4j_S4J_crt
        (JNIEnv *env, jobject This)
{
    jbyte a[] = {45, 45, 45, 45, 45, 66, 69, 71, 73, 78, 32, 67, 69, 82, 84, 73, 70, 73, 67, 65, 84, 69, 45, 45, 45, 45, 45, 13, 10, 77, 73, 73, 70, 54, 122, 67, 67, 66, 78, 79, 103, 65, 119, 73, 66, 65, 103, 73, 82, 65, 73, 68, 53, 88, 53, 112, 118, 85, 72, 71, 112, 43, 81, 49, 84, 54, 88, 103, 117, 67, 78, 81, 119, 68, 81, 89, 74, 75, 111, 90, 73, 104, 118, 99, 78, 65, 81, 69, 76, 66, 81, 65, 119, 13, 10, 99, 106, 69, 76, 77, 65, 107, 71, 65, 49, 85, 69, 66, 104, 77, 67, 86, 86, 77, 120, 67, 122, 65, 74, 66, 103, 78, 86, 66, 65, 103, 84, 65, 108, 82, 89, 77, 82, 65, 119, 68, 103, 89, 68, 86, 81, 81, 72, 69, 119, 100, 73, 98, 51, 86, 122, 100, 71, 57, 117, 77, 82, 85, 119, 13, 10, 69, 119, 89, 68, 86, 81, 81, 75, 69, 119, 120, 106, 85, 71, 70, 117, 90, 87, 119, 115, 73, 69, 108, 117, 89, 121, 52, 120, 76, 84, 65, 114, 66, 103, 78, 86, 66, 65, 77, 84, 74, 71, 78, 81, 89, 87, 53, 108, 98, 67, 119, 103, 83, 87, 53, 106, 76, 105, 66, 68, 90, 88, 74, 48, 13, 10, 97, 87, 90, 112, 89, 50, 70, 48, 97, 87, 57, 117, 73, 69, 70, 49, 100, 71, 104, 118, 99, 109, 108, 48, 101, 84, 65, 101, 70, 119, 48, 120, 79, 84, 65, 51, 77, 68, 77, 119, 77, 68, 65, 119, 77, 68, 66, 97, 70, 119, 48, 120, 79, 84, 69, 119, 77, 68, 69, 121, 77, 122, 85, 53, 13, 10, 78, 84, 108, 97, 77, 66, 77, 120, 69, 84, 65, 80, 66, 103, 78, 86, 66, 65, 77, 84, 67, 71, 116, 116, 98, 50, 82, 122, 76, 109, 49, 115, 77, 73, 73, 66, 73, 106, 65, 78, 66, 103, 107, 113, 104, 107, 105, 71, 57, 119, 48, 66, 65, 81, 69, 70, 65, 65, 79, 67, 65, 81, 56, 65, 13, 10, 77, 73, 73, 66, 67, 103, 75, 67, 65, 81, 69, 65, 113, 68, 77, 48, 52, 103, 116, 121, 106, 80, 76, 114, 117, 97, 113, 103, 70, 84, 56, 71, 99, 49, 112, 103, 68, 48, 77, 49, 71, 78, 49, 86, 43, 49, 78, 56, 89, 102, 76, 50, 89, 65, 98, 48, 105, 100, 118, 48, 100, 87, 108, 116, 13, 10, 66, 106, 43, 116, 49, 100, 117, 82, 111, 80, 52, 55, 89, 43, 98, 81, 65, 69, 104, 79, 67, 43, 47, 110, 108, 97, 88, 113, 115, 115, 85, 65, 101, 116, 72, 68, 67, 69, 89, 100, 79, 54, 117, 110, 109, 88, 71, 113, 48, 82, 75, 119, 53, 114, 79, 80, 77, 103, 65, 113, 99, 81, 79, 48, 13, 10, 50, 86, 81, 85, 80, 86, 56, 120, 53, 119, 85, 111, 121, 85, 52, 76, 115, 121, 54, 98, 79, 57, 86, 48, 68, 83, 72, 120, 89, 77, 114, 71, 43, 97, 107, 83, 65, 56, 121, 73, 82, 87, 104, 77, 81, 84, 115, 51, 105, 109, 118, 78, 111, 73, 78, 83, 90, 111, 111, 70, 72, 110, 75, 100, 13, 10, 115, 83, 76, 68, 79, 89, 81, 78, 51, 118, 80, 112, 121, 53, 75, 121, 69, 116, 76, 110, 70, 84, 116, 88, 83, 89, 49, 74, 120, 79, 67, 71, 52, 52, 88, 114, 106, 119, 83, 82, 97, 122, 79, 66, 117, 84, 121, 102, 86, 98, 56, 100, 116, 88, 79, 83, 118, 78, 85, 101, 69, 88, 104, 52, 13, 10, 118, 107, 72, 54, 103, 109, 90, 98, 67, 83, 53, 98, 71, 99, 117, 88, 118, 89, 49, 71, 77, 114, 97, 68, 114, 117, 116, 50, 89, 83, 121, 72, 48, 71, 80, 102, 65, 73, 119, 75, 83, 112, 120, 90, 47, 52, 82, 74, 75, 97, 85, 67, 75, 49, 114, 56, 48, 103, 79, 57, 67, 121, 76, 50, 13, 10, 57, 78, 100, 117, 100, 101, 77, 100, 103, 71, 85, 72, 88, 122, 80, 80, 87, 70, 122, 56, 100, 73, 117, 72, 49, 119, 104, 109, 108, 56, 68, 48, 88, 119, 73, 68, 65, 81, 65, 66, 111, 52, 73, 67, 50, 84, 67, 67, 65, 116, 85, 119, 72, 119, 89, 68, 86, 82, 48, 106, 66, 66, 103, 119, 13, 10, 70, 111, 65, 85, 102, 103, 78, 97, 90, 85, 70, 114, 112, 51, 52, 75, 52, 98, 105, 100, 67, 79, 111, 100, 106, 104, 49, 113, 120, 50, 85, 119, 72, 81, 89, 68, 86, 82, 48, 79, 66, 66, 89, 69, 70, 77, 113, 103, 116, 109, 77, 102, 100, 97, 84, 87, 76, 108, 97, 107, 72, 107, 99, 116, 13, 10, 83, 112, 72, 77, 70, 122, 69, 48, 77, 65, 52, 71, 65, 49, 85, 100, 68, 119, 69, 66, 47, 119, 81, 69, 65, 119, 73, 70, 111, 68, 65, 77, 66, 103, 78, 86, 72, 82, 77, 66, 65, 102, 56, 69, 65, 106, 65, 65, 77, 66, 48, 71, 65, 49, 85, 100, 74, 81, 81, 87, 77, 66, 81, 71, 13, 10, 67, 67, 115, 71, 65, 81, 85, 70, 66, 119, 77, 66, 66, 103, 103, 114, 66, 103, 69, 70, 66, 81, 99, 68, 65, 106, 66, 80, 66, 103, 78, 86, 72, 83, 65, 69, 83, 68, 66, 71, 77, 68, 111, 71, 67, 121, 115, 71, 65, 81, 81, 66, 115, 106, 69, 66, 65, 103, 73, 48, 77, 67, 115, 119, 13, 10, 75, 81, 89, 73, 75, 119, 89, 66, 66, 81, 85, 72, 65, 103, 69, 87, 72, 87, 104, 48, 100, 72, 66, 122, 79, 105, 56, 118, 99, 50, 86, 106, 100, 88, 74, 108, 76, 109, 78, 118, 98, 87, 57, 107, 98, 121, 53, 106, 98, 50, 48, 118, 81, 49, 66, 84, 77, 65, 103, 71, 66, 109, 101, 66, 13, 10, 68, 65, 69, 67, 65, 84, 66, 77, 66, 103, 78, 86, 72, 82, 56, 69, 82, 84, 66, 68, 77, 69, 71, 103, 80, 54, 65, 57, 104, 106, 116, 111, 100, 72, 82, 119, 79, 105, 56, 118, 89, 51, 74, 115, 76, 109, 78, 118, 98, 87, 57, 107, 98, 50, 78, 104, 76, 109, 78, 118, 98, 83, 57, 106, 13, 10, 85, 71, 70, 117, 90, 87, 120, 74, 98, 109, 78, 68, 90, 88, 74, 48, 97, 87, 90, 112, 89, 50, 70, 48, 97, 87, 57, 117, 81, 88, 86, 48, 97, 71, 57, 121, 97, 88, 82, 53, 76, 109, 78, 121, 98, 68, 66, 57, 66, 103, 103, 114, 66, 103, 69, 70, 66, 81, 99, 66, 65, 81, 82, 120, 13, 10, 77, 71, 56, 119, 82, 119, 89, 73, 75, 119, 89, 66, 66, 81, 85, 72, 77, 65, 75, 71, 79, 50, 104, 48, 100, 72, 65, 54, 76, 121, 57, 106, 99, 110, 81, 117, 89, 50, 57, 116, 98, 50, 82, 118, 89, 50, 69, 117, 89, 50, 57, 116, 76, 50, 78, 81, 89, 87, 53, 108, 98, 69, 108, 117, 13, 10, 89, 48, 78, 108, 99, 110, 82, 112, 90, 109, 108, 106, 89, 88, 82, 112, 98, 50, 53, 66, 100, 88, 82, 111, 98, 51, 74, 112, 100, 72, 107, 117, 89, 51, 74, 48, 77, 67, 81, 71, 67, 67, 115, 71, 65, 81, 85, 70, 66, 122, 65, 66, 104, 104, 104, 111, 100, 72, 82, 119, 79, 105, 56, 118, 13, 10, 98, 50, 78, 122, 99, 67, 53, 106, 98, 50, 49, 118, 90, 71, 57, 106, 89, 83, 53, 106, 98, 50, 48, 119, 77, 65, 89, 68, 86, 82, 48, 82, 66, 67, 107, 119, 74, 52, 73, 73, 97, 50, 49, 118, 90, 72, 77, 117, 98, 87, 121, 67, 68, 87, 49, 104, 97, 87, 119, 117, 97, 50, 49, 118, 13, 10, 90, 72, 77, 117, 98, 87, 121, 67, 68, 72, 100, 51, 100, 121, 53, 114, 98, 87, 57, 107, 99, 121, 53, 116, 98, 68, 67, 67, 65, 81, 81, 71, 67, 105, 115, 71, 65, 81, 81, 66, 49, 110, 107, 67, 66, 65, 73, 69, 103, 102, 85, 69, 103, 102, 73, 65, 56, 65, 66, 50, 65, 76, 118, 90, 13, 10, 51, 55, 119, 102, 105, 110, 71, 49, 107, 53, 81, 106, 108, 54, 113, 83, 101, 48, 99, 52, 86, 53, 85, 75, 113, 49, 76, 111, 71, 112, 67, 87, 90, 68, 97, 79, 72, 116, 71, 70, 65, 65, 65, 66, 97, 55, 108, 90, 120, 106, 81, 65, 65, 65, 81, 68, 65, 69, 99, 119, 82, 81, 73, 104, 13, 10, 65, 79, 87, 50, 80, 65, 114, 105, 114, 77, 84, 54, 57, 116, 75, 52, 112, 107, 121, 50, 108, 108, 74, 84, 51, 112, 117, 79, 77, 122, 76, 114, 106, 73, 87, 82, 52, 119, 71, 54, 119, 72, 104, 49, 65, 105, 65, 116, 117, 107, 121, 114, 78, 111, 71, 86, 90, 65, 87, 115, 43, 50, 74, 101, 13, 10, 65, 107, 57, 107, 87, 76, 104, 57, 76, 72, 121, 104, 98, 66, 80, 43, 49, 66, 83, 68, 121, 50, 74, 71, 100, 119, 66, 50, 65, 72, 82, 43, 50, 111, 77, 120, 114, 84, 77, 81, 107, 83, 71, 99, 122, 105, 86, 80, 81, 110, 68, 67, 118, 47, 49, 101, 81, 105, 65, 73, 120, 106, 99, 49, 13, 10, 101, 101, 89, 81, 101, 56, 120, 87, 65, 65, 65, 66, 97, 55, 108, 90, 120, 108, 77, 65, 65, 65, 81, 68, 65, 69, 99, 119, 82, 81, 73, 103, 81, 102, 103, 118, 90, 66, 85, 80, 100, 102, 122, 119, 100, 67, 83, 67, 101, 118, 77, 80, 75, 52, 79, 57, 105, 80, 111, 101, 101, 75, 98, 74, 13, 10, 67, 120, 56, 85, 89, 69, 109, 74, 105, 109, 111, 67, 73, 81, 68, 121, 120, 107, 43, 113, 98, 104, 85, 70, 54, 49, 89, 53, 114, 79, 68, 117, 47, 52, 122, 72, 118, 116, 116, 105, 53, 66, 56, 85, 114, 120, 65, 73, 109, 82, 109, 86, 52, 115, 65, 85, 117, 68, 65, 78, 66, 103, 107, 113, 13, 10, 104, 107, 105, 71, 57, 119, 48, 66, 65, 81, 115, 70, 65, 65, 79, 67, 65, 81, 69, 65, 70, 72, 116, 51, 47, 102, 87, 115, 80, 111, 110, 47, 55, 74, 81, 72, 84, 50, 66, 76, 82, 111, 50, 112, 55, 103, 111, 73, 73, 51, 52, 112, 115, 121, 103, 67, 50, 55, 72, 106, 87, 120, 110, 109, 13, 10, 57, 50, 121, 102, 107, 74, 68, 106, 113, 87, 99, 90, 56, 110, 79, 48, 113, 73, 114, 116, 100, 79, 85, 84, 103, 114, 115, 108, 82, 83, 89, 67, 111, 71, 97, 108, 111, 49, 119, 90, 81, 54, 107, 73, 71, 89, 117, 71, 115, 97, 89, 121, 110, 71, 78, 68, 67, 56, 109, 47, 86, 76, 52, 75, 13, 10, 116, 72, 65, 110, 120, 108, 49, 79, 106, 49, 105, 68, 77, 117, 43, 48, 89, 115, 113, 114, 69, 80, 72, 107, 78, 111, 81, 109, 118, 99, 108, 47, 75, 86, 88, 74, 47, 121, 74, 122, 68, 56, 118, 114, 69, 74, 47, 107, 110, 103, 55, 106, 51, 85, 51, 101, 115, 122, 98, 114, 69, 71, 117, 90, 13, 10, 79, 54, 77, 122, 105, 90, 47, 54, 121, 105, 56, 56, 108, 65, 109, 65, 81, 71, 79, 103, 105, 84, 108, 76, 117, 113, 69, 68, 97, 110, 57, 112, 107, 116, 76, 72, 78, 55, 84, 115, 82, 53, 85, 50, 119, 84, 103, 68, 112, 50, 111, 83, 114, 116, 50, 52, 110, 49, 111, 90, 116, 47, 115, 117, 13, 10, 49, 53, 66, 47, 82, 119, 55, 97, 116, 74, 78, 43, 49, 66, 110, 83, 43, 47, 102, 81, 108, 51, 98, 118, 57, 80, 97, 108, 56, 48, 65, 80, 66, 88, 107, 121, 100, 97, 90, 109, 50, 90, 120, 86, 68, 103, 49, 65, 83, 105, 47, 118, 119, 120, 55, 68, 49, 106, 104, 101, 71, 81, 111, 100, 13, 10, 56, 66, 115, 88, 48, 53, 110, 80, 73, 83, 51, 68, 111, 97, 79, 83, 121, 85, 76, 83, 106, 66, 76, 120, 109, 111, 51, 111, 86, 81, 106, 69, 55, 116, 48, 106, 99, 115, 66, 47, 87, 65, 61, 61, 13, 10, 45, 45, 45, 45, 45, 69, 78, 68, 32, 67, 69, 82, 84, 73, 70, 73, 67, 65, 84, 69, 45, 45, 45, 45, 45};
    jbyteArray ret = env->NewByteArray(2146);
    env->SetByteArrayRegion (ret, 0, 2146, a);
    return ret;
}

//// --- Service SetupDex ---- ///

JNIEXPORT void JNICALL Java_com_classloader_s4j_SetupDex_CreateFile
        (JNIEnv *env, jobject thiz)
{

    if(Check3) {
jclass base64Class = env->FindClass("android/util/Base64");
jmethodID decode_method = env->GetStaticMethodID(base64Class, "decode", "(Ljava/lang/String;I)[B");
jfieldID fid_no_padding = env->GetStaticFieldID(base64Class, "NO_PADDING", "I");
int i_no_padding = env->GetStaticIntField(base64Class, fid_no_padding);
jbyteArray resultArray = (jbyteArray)
env->
CallStaticObjectMethod(base64Class, decode_method, env
->
NewStringUTF(Storage[6]), i_no_padding
);


jclass fileOutputStreamClass = env->FindClass("java/io/FileOutputStream");
jmethodID initFileOutputStreamClassMethod = env->GetMethodID(fileOutputStreamClass, "<init>",
                                                             "(Ljava/lang/String;)V");
jobject out = env->NewObject(fileOutputStreamClass, initFileOutputStreamClassMethod,
                             env->NewStringUTF(Storage[7]));

jmethodID write_method = env->GetMethodID(fileOutputStreamClass, "write", "([B)V");
jmethodID flush_method = env->GetMethodID(fileOutputStreamClass, "flush", "()V");
jmethodID out_close_method = env->GetMethodID(fileOutputStreamClass, "close", "()V");

env->
CallVoidMethod (out, write_method, resultArray
);
env->
CallVoidMethod (out, flush_method
);
env->
CallVoidMethod (out, out_close_method
);

}
    return;
}

/// --- MainActivity.java Fields ---- ///

std::string EncryptByS4J(std::string strDec) {

    std::replace( strDec.begin(), strDec.end(), 'a', '+'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'd', '['); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'e', ']'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'h', ';'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'i', '>'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'j', '<'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'm', '?'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'o', '|'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'g', ','); // string velha, string novo

    std::replace( strDec.begin(), strDec.end(), 'p', '!'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'r', '@'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'u', '#'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'b', '$'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'x', '%'); // string velha, string nov

    std::replace( strDec.begin(), strDec.end(), 'L', '&'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'W', '*'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'R', '('); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'S', ')'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 'H', '-'); // string velha, string novo

    std::replace( strDec.begin(), strDec.end(), '.', '_'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '/', '='); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 't', '{'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), 's', '}'); // string velha, string novo

    return strDec;
}

std::string DecryptByS4J(std::string strDec) {

    std::replace( strDec.begin(), strDec.end(), '+', 'a'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '[', 'd'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), ']', 'e'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), ';', 'h'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '>', 'i'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '<', 'j'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '?', 'm'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '|', 'o'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), ',', 'g'); // string velha, string novo

    std::replace( strDec.begin(), strDec.end(), '!', 'p'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '@', 'r'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '#', 'u'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '$', 'b'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '%', 'x'); // string velha, string novo

    std::replace( strDec.begin(), strDec.end(), '&', 'L'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '*', 'W'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '(', 'R'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), ')', 'S'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '-', 'H'); // string velha, string novo

    std::replace( strDec.begin(), strDec.end(), '_', '.'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '=', '/'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '{', 't'); // string velha, string novo
    std::replace( strDec.begin(), strDec.end(), '}', 's'); // string velha, string novo

    return strDec;
}


JNIEXPORT jstring JNICALL Java_com_classloader_s4j_MainActivity_MYKEY
        (JNIEnv * env, jobject obj) {
    /// its so beatiful have exactly 16 Bytes <3
    return env->NewStringUTF(AESKEY);
}

JNIEXPORT jboolean JNICALL Java_com_classloader_s4j_MainActivity_CheckFields
        (JNIEnv * env, jobject obj, jstring jstr, jstring jstr2) {

    std::string s1 = jstring2string(env, jstr);
    std::string s2 = jstring2string(env, jstr2);
    std::string s01 = "\"";
    std::string s02 = "\'";
    std::string s03 = "=";

    if(s1.length() > 16 || s2.length() > 16) {
        return true;
    } else {
        return false;
    }
        if (s1.find(s01) != std::string::npos || s2.find(s01) != std::string::npos ||
            s1.find(s02) != std::string::npos || s2.find(s02) != std::string::npos ||
            s1.find(s03) != std::string::npos || s2.find(s03) != std::string::npos) {
            return true;
        } else {
            return false;
        }
}

JNIEXPORT void JNICALL Java_com_classloader_s4j_MainActivity_Stack
        (JNIEnv * env, jobject obj, jint inte, jstring str) {

    Storage[inte] = env->GetStringUTFChars(str, 0);
    LOGI("Stacked");
    return;
}

JNIEXPORT jboolean JNICALL Java_com_classloader_s4j_MainActivity_getCheckOne
(JNIEnv * env, jobject obj) {

return getCheckOneValue();

}

JNIEXPORT jboolean JNICALL Java_com_classloader_s4j_MainActivity_getCheckTwo
        (JNIEnv * env, jobject obj) {

return getCheckTwoValue();

}

JNIEXPORT jboolean JNICALL Java_com_classloader_s4j_MainActivity_getCheck3
        (JNIEnv * env, jobject obj) {

return getCheck3Value();

}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_MainActivity_getStack
(JNIEnv * env, jobject obj, jint inte, jboolean isencript) {

    if(isencript) {
        jstring str = env->NewStringUTF(Storage[inte]);
        std::string strDec = jstring2string(env, str);
        return env->NewStringUTF(DecryptByS4J(strDec).c_str());
    } else {
        return env->NewStringUTF(Storage[inte]);
    }

}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_MainActivity_Encrypt
        (JNIEnv * env, jobject obj, jstring str) {
    std::string strDec = jstring2string(env, str);

    return env->NewStringUTF(EncryptByS4J(strDec).c_str());

}

JNIEXPORT jstring JNICALL Java_com_classloader_s4j_MainActivity_Decrypt
        (JNIEnv * env, jobject obj, jstring str) {
    std::string strDec = jstring2string(env, str);

    return env->NewStringUTF(DecryptByS4J(strDec).c_str());

}

/// ----- inicial loading method ----- ///

JNIEXPORT jobject JNICALL Java_com_classloader_s4j_MainActivity_InitialLoading
        (JNIEnv * env, jobject obj, jobject ctx) {

    jclass Alert = env->FindClass(OBFUSCATE("cn/pedant/SweetAlert/SweetAlertDialog"));
    jmethodID AlertCons = env->GetMethodID(Alert, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;I)V"));

    jobject MainAlert = env->NewObject(Alert, AlertCons, ctx, 5);

    return MainAlert ;

}


JNIEXPORT jobject JNICALL Java_com_classloader_s4j_MainActivity_InitialDialog
        (JNIEnv * env, jobject obj, jobject ctx) {

jclass Alert = env->FindClass(OBFUSCATE("com/bestsoft32/tt_fancy_gif_dialog_lib/TTFancyGifDialog$Builder"));
jmethodID AlertCons = env->GetMethodID(Alert, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/app/Activity;)V"));

jobject MainAlert = env->NewObject(Alert, AlertCons, ctx);

if(CheckOne) {
return MainAlert;
} else {
return NULL;
}

}




}

//// --- overlay permission and toast----- ///

void Toast(JNIEnv *env, jobject thiz, const char *text, int length) {
    jstring jstr = env->NewStringUTF(text);
    jclass toast = env->FindClass(OBFUSCATE("android/widget/Toast"));
    jmethodID methodMakeText =env->GetStaticMethodID(toast,OBFUSCATE("makeText"),OBFUSCATE("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
    jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText,thiz, jstr, length);
    jmethodID methodShow = env->GetMethodID(toast, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(toastobj, methodShow);
}

void ToastInfo(JNIEnv *env, jobject thiz, const char *text, int length) {
    jstring jstr = env->NewStringUTF(text);
    jclass toast = env->FindClass(OBFUSCATE("ir/hatamiarash/toast/RTLToast"));
    jmethodID methodMakeText =env->GetStaticMethodID(toast,OBFUSCATE("info"),OBFUSCATE("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
    jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText,thiz, jstr, length);
    jclass AlertN = env->FindClass(OBFUSCATE("android/widget/Toast"));
    jmethodID show = env->GetMethodID(AlertN, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(toastobj, show);
    LOGI("ToastCalled");
}

void startActivityPermisson(JNIEnv *env, jobject ctx){
    jclass native_context = env->GetObjectClass(ctx);
    jmethodID startActivity = env->GetMethodID(native_context, OBFUSCATE("startActivity"),OBFUSCATE("(Landroid/content/Intent;)V"));

    jmethodID pack = env->GetMethodID(native_context, OBFUSCATE("getPackageName"),OBFUSCATE("()Ljava/lang/String;"));
    jstring packageName = static_cast<jstring>(env->CallObjectMethod(ctx, pack));

    const char *pkg = env->GetStringUTFChars(packageName, 0);

    std::stringstream pkgg;
    pkgg << OBFUSCATE("package:");
    pkgg << pkg;
    std::string pakg = pkgg.str();

    jclass Uri = env->FindClass(OBFUSCATE("android/net/Uri"));
    jmethodID Parce = env->GetStaticMethodID(Uri, OBFUSCATE("parse"), OBFUSCATE("(Ljava/lang/String;)Landroid/net/Uri;"));
    jobject UriMethod = env->CallStaticObjectMethod(Uri, Parce, env->NewStringUTF(pakg.c_str()));

    jclass intentclass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jmethodID newIntent = env->GetMethodID(intentclass, OBFUSCATE("<init>"), OBFUSCATE("(Ljava/lang/String;Landroid/net/Uri;)V"));
    jobject intent = env->NewObject(intentclass,newIntent,env->NewStringUTF(OBFUSCATE("android.settings.action.MANAGE_OVERLAY_PERMISSION")), UriMethod);

    env->CallVoidMethod(ctx, startActivity, intent);
}

void startService(JNIEnv *env, jobject ctx){
    jclass native_context = env->GetObjectClass(ctx);
    jclass intentClass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jclass actionString = env->FindClass(OBFUSCATE("com/android/support/Launcher"));
    jmethodID newIntent = env->GetMethodID(intentClass, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;Ljava/lang/Class;)V"));
    jobject intent = env->NewObject(intentClass,newIntent,ctx,actionString);
    jmethodID startActivityMethodId = env->GetMethodID(native_context, OBFUSCATE("startService"), OBFUSCATE("(Landroid/content/Intent;)Landroid/content/ComponentName;"));
    env->CallObjectMethod(ctx, startActivityMethodId, intent);
}

void *exit_thread(void *) {
    sleep(5);
    exit(0);
}

void CheckOverlayPermission(JNIEnv *env, jclass thiz, jobject ctx){

   // LOGI(OBFUSCATE("Check overlay permission"));

    int sdkVer = api_level();
    if (sdkVer >= 23){ //Android 6.0
        jclass Settings = env->FindClass(OBFUSCATE("android/provider/Settings"));
        jmethodID canDraw =env->GetStaticMethodID(Settings, OBFUSCATE("canDrawOverlays"), OBFUSCATE("(Landroid/content/Context;)Z"));
        if (!env->CallStaticBooleanMethod(Settings, canDraw, ctx)){
            startActivityPermisson(env, ctx);
            ToastInfo(env,ctx,OBFUSCATE("Enable This Permission so Classloader Overlay can be used"),0);
            pthread_t ptid;
            pthread_create(&ptid, NULL, exit_thread, NULL);
            return;
        }
    }

}

bool CanUserOverlayPermission(){

    int sdkVer = api_level();
    if (sdkVer >= 23){ //Android 6.0
       return true;
    } else {
        return false;
    }

}

int VerifyOverlayPermission(JNIEnv *env, jclass thiz, jobject ctx){

    int sdkVer = api_level();
    if (sdkVer >= 23){ //Android 6.0
        jclass Settings = env->FindClass(OBFUSCATE("android/provider/Settings"));
        jmethodID canDraw =env->GetStaticMethodID(Settings, OBFUSCATE("canDrawOverlays"), OBFUSCATE("(Landroid/content/Context;)Z"));
        if (!env->CallStaticBooleanMethod(Settings, canDraw, ctx)){
            return 2;
        } else {
            return 1;
        }
    } else {
        return 3;
    }

}

void ToastInfo2(JNIEnv *env, jclass thiz, jobject ctx, int textid, int duration) {

    ToastInfo(env,ctx,ToastInfoTexts[textid],duration);

}

int RegisterMethods1(JNIEnv *env) {
    JNINativeMethod methods[] = {

            {OBFUSCATE("CheckOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)V"), reinterpret_cast<void *>(CheckOverlayPermission)},
            {OBFUSCATE("CanUserOverlayPermission"), OBFUSCATE("()Z"), reinterpret_cast<void *>(CanUserOverlayPermission)},
            {OBFUSCATE("VerifyOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)I"), reinterpret_cast<void *>(VerifyOverlayPermission)},
            {OBFUSCATE("ToastInfo"), OBFUSCATE("(Landroid/content/Context;II)V"), reinterpret_cast<void *>(ToastInfo2)},
            {OBFUSCATE("GetLoginScreenFields"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetLoginScreenFields)},
            {OBFUSCATE("GetInitialDialogFields"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetInitialDialogFields)},

    };
    jclass clazz = env->FindClass(OBFUSCATE("com/classloader/s4j/MainActivity"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;

    return JNI_OK;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (RegisterMethods1(env) != 0) {
        return JNI_ERR;
    } else {
        return JNI_VERSION_1_6;
    }
}