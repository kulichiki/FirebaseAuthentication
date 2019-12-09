#include "ResendVerificationCode.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UResendVerificationCode* UResendVerificationCode::ResendVerificationCode(FString PhoneNumber, int Timeout)
{
	UResendVerificationCode* BlueprintNode = NewObject<UResendVerificationCode>();
	BlueprintNode->PhoneNumber = PhoneNumber;
	BlueprintNode->Timeout = Timeout;
	return BlueprintNode;
}

void UResendVerificationCode::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JPhoneNumber = Env->NewStringUTF(TCHAR_TO_UTF8(*PhoneNumber));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ResendVerificationCode", "(Ljava/lang/String;I)V", false);
		int StatusCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, Timeout);

		Env->DeleteLocalRef(JPhoneNumber);
	}
#endif
}

void UResendVerificationCode::ResultCode(int StatusCode)
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