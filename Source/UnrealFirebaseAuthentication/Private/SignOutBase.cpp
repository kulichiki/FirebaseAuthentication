#include "SignOutBase.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void USignOutBase::Activate()
{
#if PLATFORM_ANDROID
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->SignOutResult.Clear();
		Module->SignOutResult.AddUObject(this, &USignOutBase::SignOutResult);
	}
#endif
}