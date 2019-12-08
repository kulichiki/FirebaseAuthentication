#include "AnonymousSignOut.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UAnonymousSignOut* UAnonymousSignOut::AnonymousSignOut()
{
	return NewObject<UAnonymousSignOut>();
}

void UAnonymousSignOut::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AnonymouslySignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UAnonymousSignOut::Result()
{
	OnSuccess.Broadcast();
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeAnonymouslySignOutResult(JNIEnv* jenv, jobject thiz)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->Result.Broadcast();
		Module->Result.Clear();
	}
}
#endif