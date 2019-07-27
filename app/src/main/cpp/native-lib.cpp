#include <jni.h>
#include <string>
#include <android/log.h>

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
     int len = env->GetStringLength(str);
    return len;
}

extern "C"
JNIEXPORT jint JNICALL Java_com_example_mrw_myapplication_MainActivity_getStringLengthNonStatic
  (JNIEnv *env, jobject obj, jstring str)
{
//	return env->GetStringLength(str);
    char arr[]="LLLLL";
    jint length=strlen(arr);//获取字符串长度
	return strlen(arr);
}

extern "C"
JNIEXPORT jint JNICALL Java_com_example_mrw_myapplication_MainActivity_exportArray(JNIEnv *env,jobject,jcharArray char_array){
//     unsigned short *obj =env->GetCharArrayElements(char_array,0);
//    for(int i=0; i < env->GetArrayLength(obj);i++){
//        LOGI("dayin?");
//    }
    return 0;
}




