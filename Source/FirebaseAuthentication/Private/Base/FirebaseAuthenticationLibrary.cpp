#include "FirebaseAuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UFirebaseAuthenticationLibrary::AnonymousSignOut()
{
	FirebaseSignOut();
}

void UFirebaseAuthenticationLibrary::EmailPasswordSignOut()
{
	FirebaseSignOut();
}

void UFirebaseAuthenticationLibrary::PhoneSignOut()
{
	FirebaseSignOut();
}

void UFirebaseAuthenticationLibrary::OAuthSignOut()
{
	FirebaseSignOut();
}

void UFirebaseAuthenticationLibrary::FacebookSignOut()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_FacebookSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UFirebaseAuthenticationLibrary::FirebaseSignOut()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_FirebaseAccountSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}
