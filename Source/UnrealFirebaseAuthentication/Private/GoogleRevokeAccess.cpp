#include "GoogleRevokeAccess.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleRevokeAccess* UGoogleRevokeAccess::GoogleRevokeAccess()
{
	UGoogleRevokeAccess* BlueprintNode = NewObject<UGoogleRevokeAccess>();
	return BlueprintNode;
}

void UGoogleRevokeAccess::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleRevokeAccess", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UGoogleRevokeAccess::SignOutResult()
{
	OnSuccess.Broadcast();
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeGoogleRevokeAccessResult(JNIEnv* jenv, jobject thiz)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->SignOutResult.Broadcast();
		Module->SignOutResult.Clear();
	}
}
#endif