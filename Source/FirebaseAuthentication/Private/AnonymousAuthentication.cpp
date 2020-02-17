#include "AnonymousAuthentication.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UAnonymousAuthentication* UAnonymousAuthentication::AnonymousSignIn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AnonymouslySignIn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif

	return NewObject<UAnonymousAuthentication>();
}

UAnonymousAuthentication* UAnonymousAuthentication::AnonymousLinkAccount(FString Email, FString Password)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AnonymouslyLinkAccount", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JEmail, JPassword);

		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif

	return NewObject<UAnonymousAuthentication>();
}