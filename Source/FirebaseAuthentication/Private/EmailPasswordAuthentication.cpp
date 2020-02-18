#include "EmailPasswordAuthentication.h"
#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UEmailPasswordAuthentication* UEmailPasswordAuthentication::EmailPasswordSignIn(FString Email, FString Password)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Init Java strings
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_EmailPasswordSignIn", "(Ljava/lang/String;Ljava/lang/String;)V", JEmail, JPassword);

		// Remove Java references
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
		// Init Java strings
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_CreateAccount", "(Ljava/lang/String;Ljava/lang/String;)V", JEmail, JPassword);

		// Remove Java references
		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif
	return NewObject<UEmailPasswordAuthentication>();
}

UEmailPasswordAuthentication* UEmailPasswordAuthentication::SendEmailVerification()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_SendEmailVerification", "()V");
#endif
	return NewObject<UEmailPasswordAuthentication>();
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_thegetaway_firebaseauthentication_EmailPasswordAuthentication_NativeEmailPasswordResult(JNIEnv* jenv, jobject thiz, jint Result)
{
}
#endif