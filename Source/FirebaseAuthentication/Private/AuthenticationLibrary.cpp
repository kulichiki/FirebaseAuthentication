#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UAuthenticationLibrary::AnonymousSignOut()
{
	FirebaseSignOut();
}

void UAuthenticationLibrary::EmailPasswordSignOut()
{
	FirebaseSignOut();
}

void UAuthenticationLibrary::PhoneSignOut()
{
	FirebaseSignOut();
}

void UAuthenticationLibrary::OAuthSignOut()
{
	FirebaseSignOut();
}

void UAuthenticationLibrary::FacebookSignOut()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_FacebookSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UAuthenticationLibrary::FirebaseSignOut()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_FirebaseAccountSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}
