#include "PhoneAuthentication.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UPhoneAuthentication* UPhoneAuthentication::StartPhoneNumberVerification(FString PhoneNumber, int Timeout)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JPhoneNumber = Env->NewStringUTF(TCHAR_TO_UTF8(*PhoneNumber));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_StartPhoneNumberVerification", "(Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JPhoneNumber, Timeout);

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
		jstring JPhoneNumber = Env->NewStringUTF(TCHAR_TO_UTF8(*PhoneNumber));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ResendVerificationCode", "(Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JPhoneNumber, Timeout);

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
		jstring JCode = Env->NewStringUTF(TCHAR_TO_UTF8(*Code));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_VerifyPhoneNumberWithCode", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JCode);

		Env->DeleteLocalRef(JCode);
	}
#endif

	return NewObject<UPhoneAuthentication>();
}

void UPhoneAuthentication::FirebaseResultCode(int StatusCode)
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