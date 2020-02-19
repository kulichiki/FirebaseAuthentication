#include "PhoneAuthentication.h"
#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UPhoneAuthentication* UPhoneAuthentication::StartPhoneNumberVerification(FString PhoneNumber, int Timeout)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Init Java string
		jstring JPhoneNumber = Env->NewStringUTF(TCHAR_TO_UTF8(*PhoneNumber));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_StartPhoneNumberVerification", "(Ljava/lang/String;I)V", JPhoneNumber, Timeout);

		// Remove Java reference
		Env->DeleteLocalRef(JPhoneNumber);
	}
#endif
	return NewObject<UPhoneAuthentication>();
}

UPhoneAuthentication* UPhoneAuthentication::ResendVerificationCode(FString PhoneNumber, int Timeout)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Init Java string
		jstring JPhoneNumber = Env->NewStringUTF(TCHAR_TO_UTF8(*PhoneNumber));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_ResendVerificationCode", "(Ljava/lang/String;I)V", JPhoneNumber, Timeout);

		// Remove Java reference
		Env->DeleteLocalRef(JPhoneNumber);
	}
#endif
	return NewObject<UPhoneAuthentication>();
}

UPhoneAuthentication* UPhoneAuthentication::VerifyPhoneNumberWithCode(FString Code)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Init Java string
		jstring JCode = Env->NewStringUTF(TCHAR_TO_UTF8(*Code));

		// Call Java method
		UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_VerifyPhoneNumberWithCode", "(Ljava/lang/String;)V", JCode);

		// Remove Java reference
		Env->DeleteLocalRef(JCode);
	}
#endif
	return NewObject<UPhoneAuthentication>();
}

void UPhoneAuthentication::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BindPhoneDelegate(this);
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_thegetaway_firebaseauthentication_PhoneAuthentication_NativePhoneResult(JNIEnv* jenv, jobject thiz, jint Result)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BroadcastPhoneDelegate(EPhoneAuthenticationResult(Result));
}
#endif