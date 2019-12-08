#include "EmailPasswordSignOut.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UEmailPasswordSignOut* UEmailPasswordSignOut::EmailPasswordSignOut()
{
	return NewObject<UEmailPasswordSignOut>();
}

void UEmailPasswordSignOut::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_EmailPasswordSignOut", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UEmailPasswordSignOut::Result()
{
	OnResult.Broadcast();
}