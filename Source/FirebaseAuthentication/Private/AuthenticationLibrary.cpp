#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UAuthenticationLibrary::AnonymousSignOut() { FirebaseSignOut(); }
void UAuthenticationLibrary::EmailPasswordSignOut() { FirebaseSignOut(); }
void UAuthenticationLibrary::PhoneSignOut() { FirebaseSignOut(); }
void UAuthenticationLibrary::OAuthSignOut() { FirebaseSignOut(); }

void UAuthenticationLibrary::CallVoidMethod(const char* Name, const char* Signature, ...)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Get Arguments list
		va_list Arguments;
		va_start(Arguments, Signature);

		// Call Java method
		jmethodID JMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, Name, Signature, false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethod, Arguments);
		
		va_end(Arguments);
	}
#endif
}

void UAuthenticationLibrary::FacebookSignOut()
{
#if PLATFORM_ANDROID
	CallVoidMethod("AndroidThunkJava_FacebookSignOut", "()V");
#endif
}

void UAuthenticationLibrary::FirebaseSignOut()
{
#if PLATFORM_ANDROID
	CallVoidMethod("AndroidThunkJava_FirebaseSignOut", "()V");
#endif
}
