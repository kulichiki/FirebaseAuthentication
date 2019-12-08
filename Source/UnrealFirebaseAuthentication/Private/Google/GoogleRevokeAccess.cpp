#include "GoogleRevokeAccess.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleRevokeAccess* UGoogleRevokeAccess::GoogleRevokeAccess()
{
	return NewObject<UGoogleRevokeAccess>();
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

void UGoogleRevokeAccess::Result()
{
	OnResult.Broadcast();
}