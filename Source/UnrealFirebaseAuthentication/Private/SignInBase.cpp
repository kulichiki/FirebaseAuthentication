#include "SignInBase.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void USignInBase::Activate()
{
#if PLATFORM_ANDROID
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->SignInResult.Clear();
		Module->SignInResult.AddUObject(this, &USignInBase::SignInResult);
	}
#endif
}