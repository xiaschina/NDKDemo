#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_bjhl_plugins_ndk_util_NativeUtil_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

//返回一个m x m的二维数组
extern "C" JNIEXPORT jobjectArray JNICALL
Java_com_bjhl_plugins_ndk_util_NativeUtil_intArrayFromJNI(
        JNIEnv *env,
        jobject, jint m) {
    jclass intArrayClass = env->FindClass("[I");
    jobjectArray intObjectArray = env->NewObjectArray(m, intArrayClass, NULL);
    for (int i = 0; i < m; i++) {
        jintArray intArray = env->NewIntArray(m);
        jint temp[10];
        for (int j = 0; j < m; j++) {
            temp[j] = i + j;
        }
        env->SetIntArrayRegion(intArray, 0, m, temp);
        env->SetObjectArrayElement(intObjectArray, i, intArray);
        env->DeleteLocalRef(intArray);
    }
    return intObjectArray;
}

//返回一个对象
extern "C" JNIEXPORT jobject JNICALL
Java_com_bjhl_plugins_ndk_util_NativeUtil_getUserFromJNI(JNIEnv *env,
                                                         jobject) {
    jclass user = env->FindClass("com/bjhl/plugins/ndk/bean/User");
    if (user == NULL)
        return NULL;

    jmethodID methodID = env->GetMethodID(user, "<init>",
                                          "(Ljava/lang/String;ILjava/lang/String;)V");
    if (methodID == NULL)
        return NULL;

    jstring name = env->NewStringUTF("XIAS");
    jstring avatar = env->NewStringUTF("http://......");
    return env->NewObject(user, methodID, name, 1, avatar);
}

//修改对象的值
extern "C" JNIEXPORT void JNICALL
Java_com_bjhl_plugins_ndk_util_NativeUtil_setUserFromJNI(JNIEnv *env,
                                                         jobject, jobject obj) {
    jclass user = env->GetObjectClass(obj);
    if (user == NULL)
        return;

    jmethodID name = env->GetMethodID(user, "setName", "(Ljava/lang/String;)V");
    if (name == NULL)
        return;

    jstring temp = env->NewStringUTF("XIASTEST");
    env->CallVoidMethod(obj, name, temp);
}

//返回一个指定长度的列表
extern "C" JNIEXPORT jobject JNICALL
Java_com_bjhl_plugins_ndk_util_NativeUtil_getUsersFromJNI(JNIEnv *env,
                                                          jobject, int len) {
    jclass arrObject = env->FindClass("java/util/ArrayList");
    if (arrObject == NULL) return NULL;
    jmethodID arrID = env->GetMethodID(arrObject, "<init>", "()V");
    jobject arrayList = env->NewObject(arrObject, arrID);
    jmethodID arrayAdd = env->GetMethodID(arrObject, "add", "(Ljava/lang/Object;)Z");
    jclass user = env->FindClass("com/bjhl/plugins/ndk/bean/User");
    if (user == NULL) return NULL;
    jmethodID methodID = env->GetMethodID(user, "<init>",
                                          "(Ljava/lang/String;ILjava/lang/String;)V");
    if (methodID == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        jstring name = env->NewStringUTF("XIAS" + i);
        jstring avatar = env->NewStringUTF("http://......" + i);
        env->CallBooleanMethod(arrayList, arrayAdd,
                               env->NewObject(user, methodID, name, i, avatar));
    }
    return arrayList;
}


