#include "VerifyPhoneNumberWithCode.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UVerifyPhoneNumberWithCode* UVerifyPhoneNumberWithCode::VerifyPhoneNumberWithCode(FString Code)
{
	UVerifyPhoneNumberWithCode* BlueprintNode = NewObject<UVerifyPhoneNumberWithCode>();
	BlueprintNode->Code = Code;
	return BlueprintNode;
}

void UVerifyPhoneNumberWithCode::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JCode = Env->NewStringUTF(TCHAR_TO_UTF8(*Code));

		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_VerifyPhoneNumberWithCode", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JCode);

		Env->DeleteLocalRef(JCode);
	}
#endif
}

void UVerifyPhoneNumberWithCode::ResultCode(int StatusCode)
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