#include "OAuthAuthentication.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UOAuthAuthentication* UOAuthAuthentication::OAuthSignIn(EOAuthProvider OAuthProvider)
{
#if PLATFORM_ANDROID	
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JProviderURL;
		switch (OAuthProvider)
		{
		case EOAuthProvider::Apple:
			JProviderURL = Env->NewStringUTF("apple.com");
			break;
		case EOAuthProvider::Github:
			JProviderURL = Env->NewStringUTF("github.com");
			break;
		case EOAuthProvider::Microsoft:
			JProviderURL = Env->NewStringUTF("microsoft.com");
			break;
		case EOAuthProvider::Yahoo:
			JProviderURL = Env->NewStringUTF("yahoo.com");
			break;
		case EOAuthProvider::Twitter:
			JProviderURL = Env->NewStringUTF("twitter.com");
			break;
		}

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_OAuthSignIn", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JProviderURL);

		Env->DeleteLocalRef(JProviderURL);
	}
#endif

	return NewObject<UOAuthAuthentication>();
}

void UOAuthAuthentication::FirebaseResultCode(int StatusCode)
{
	ECommonStatusCode Code = ECommonStatusCode(StatusCode);
	if (StatusCode == 12500)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_FAILED);
	else if (StatusCode == 12501)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_CANCELLED);
	else if (StatusCode == 12502)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_CURRENTLY_IN_PROGRESS);
	else
		OnResult.Broadcast(Code);
}