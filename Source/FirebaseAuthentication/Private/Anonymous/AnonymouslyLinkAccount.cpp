#include "AnonymouslyLinkAccount.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UAnonymouslyLinkAccount* UAnonymouslyLinkAccount::AnonymouslyLinkAccount(FString Email, FString Password)
{
	UAnonymouslyLinkAccount* BlueprintNode = NewObject<UAnonymouslyLinkAccount>();
	BlueprintNode->Email = Email;
	BlueprintNode->Password = Password;
	return BlueprintNode;
}

void UAnonymouslyLinkAccount::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JEmail = Env->NewStringUTF(TCHAR_TO_UTF8(*Email));
		jstring JPassword = Env->NewStringUTF(TCHAR_TO_UTF8(*Password));
		
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AnonymouslyLinkAccount", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JEmail, JPassword);

		Env->DeleteLocalRef(JEmail);
		Env->DeleteLocalRef(JPassword);
	}
#endif
}

void UAnonymouslyLinkAccount::FirebaseResultCode(int StatusCode)
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