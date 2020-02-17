#include "EmailPasswordAuthentication.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UEmailPasswordAuthentication* UEmailPasswordAuthentication::EmailPasswordSignIn(FString Email, FString Password)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_EmailPasswordSignIn", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JEmail, JPassword);

		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif

	return NewObject<UEmailPasswordAuthentication>();
}

UEmailPasswordAuthentication* UEmailPasswordAuthentication::CreateAccount(FString Email, FString Password)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CreateAccount", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JEmail, JPassword);

		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif

	return NewObject<UEmailPasswordAuthentication>();
}

UEmailPasswordAuthentication* UEmailPasswordAuthentication::SendEmailVerification()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SendEmailVerification", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif

	return NewObject<UEmailPasswordAuthentication>();
}