#include "GoogleSignOut.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleSignOut* UGoogleSignOut::GoogleSignOut()
{
	return NewObject<UGoogleSignOut>();
}

void UGoogleSignOut::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UGoogleSignOut::Result()
{
	OnSuccess.Broadcast();
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeGoogleSignOutResult(JNIEnv* jenv, jobject thiz)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->Result.Broadcast();
		Module->Result.Clear();
	}
}
#endif