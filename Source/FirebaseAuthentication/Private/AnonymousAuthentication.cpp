#include "AnonymousAuthentication.h"
#include "AuthenticationLibrary.h"

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