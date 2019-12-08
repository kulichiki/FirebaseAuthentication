#include "GoogleSignIn.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleSignIn* UGoogleSignIn::GoogleSignIn()
{
	return NewObject<UGoogleSignIn>();
}

void UGoogleSignIn::Activate()
{
	Super::Activate();
	
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleSignIn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UGoogleSignIn::ResultCode(int StatusCode)
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

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeGoogleSignInResult(JNIEnv* jenv, jobject thiz, jint StatusCode)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->ResultCode.Broadcast(StatusCode);
		Module->ResultCode.Clear();
	}
}
#endif