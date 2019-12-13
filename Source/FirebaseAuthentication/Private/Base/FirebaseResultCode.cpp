#include "FirebaseResultCode.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UFirebaseResultCode::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->ResultCode.Clear();
		Module->ResultCode.AddUObject(this, &UFirebaseResultCode::FirebaseResultCode);
	}
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeFirebaseResultCode(JNIEnv* jenv, jobject thiz, jint StatusCode)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->ResultCode.Broadcast(StatusCode);
		Module->ResultCode.Clear();
	}
}
#endif