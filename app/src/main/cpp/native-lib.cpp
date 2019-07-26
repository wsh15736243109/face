#include <jni.h>
#include <string>
#include<android/log.h>

#define TAG "wsh" //定义LOG tag值
#define LOGI(...) __android_log_print(ANDROID_LOG_DEBUG,TAG, __VA_ARGS__);//定义LOG类型 统一输出日志
extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_mrw_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string day = "";
    LOGI("劳资打印下----");
    jboolean jb=true;
    return jb;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_mrw_myapplication_MainActivity_getStrLength(JNIEnv* env,jstring str){
//    jsize len = (env)->GetStringUTFLength(str);	// 获取unicode字符串的长度
//    jsize len = str.len;	// 获取unicode字符串的长度
     int len = (*env)->GetStringLength(env, str);
    return len;
}




