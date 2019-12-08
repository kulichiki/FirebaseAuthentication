#include "Result.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UResult::Activate()
{
#if PLATFORM_ANDROID
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->Result.Clear();
		Module->Result.AddUObject(this, &UResult::Result);
	}
#endif
}