#include "AnonymousAuthentication.h"
#include "AuthenticationLibrary.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UAnonymousAuthentication* UAnonymousAuthentication::AnonymousSignIn()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_AnonymouslySignIn", "()V");
#endif
	return NewObject<UAnonymousAuthentication>();
}

UAnonymousAuthentication* UAnonymousAuthentication::AnonymousLinkAccount(FString Email, FString Password)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Init Java strings
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_AnonymouslyLinkAccount", "(Ljava/lang/String;Ljava/lang/String;)V", JEmail, JPassword);

		// Remove Java references
		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif
	return NewObject<UAnonymousAuthentication>();
}

void UAnonymousAuthentication::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BindAnonymousDelegate(this);
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_thegetaway_firebaseauthentication_AnonymousAuthentication_NativeAnonymousResult(JNIEnv* jenv, jobject thiz, jint Result)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BroadcastAnonymousDelegate(EAnonymousAuthenticationResult(Result));
}
#endif