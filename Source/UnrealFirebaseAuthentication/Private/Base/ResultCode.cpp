#include "ResultCode.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UResultCode::Activate()
{
#if PLATFORM_ANDROID
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->ResultCode.Clear();
		Module->ResultCode.AddUObject(this, &UResultCode::ResultCode);
	}
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeResultCode(JNIEnv* jenv, jobject thiz, jint StatusCode)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->ResultCode.Broadcast(StatusCode);
		Module->ResultCode.Clear();
	}
}
#endif