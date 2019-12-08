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