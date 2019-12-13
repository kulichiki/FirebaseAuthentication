#include "FirebaseResult.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UFirebaseResult::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->Result.Clear();
		Module->Result.AddUObject(this, &UFirebaseResult::FirebaseResult);
	}
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeFirebaseResult(JNIEnv* jenv, jobject thiz)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->Result.Broadcast();
		Module->Result.Clear();
	}
}
#endif