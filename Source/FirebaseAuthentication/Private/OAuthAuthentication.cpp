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