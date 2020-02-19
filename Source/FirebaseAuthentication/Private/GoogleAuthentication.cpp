#include "GoogleAuthentication.h"
#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleAuthentication* UGoogleAuthentication::GoogleSignIn()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleSignIn", "()V");
#endif
	return NewObject<UGoogleAuthentication>();
}

UGoogleAuthentication* UGoogleAuthentication::GoogleSignOut()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleSignOut", "()V");
#endif
	return NewObject<UGoogleAuthentication>();
}

UGoogleAuthentication* UGoogleAuthentication::GoogleRevokeAccess()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleRevokeAccess", "()V");
#endif
	return NewObject<UGoogleAuthentication>();
}

void UGoogleAuthentication::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BindGoogleDelegate(this);
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_thegetaway_firebaseauthentication_GoogleAuthentication_NativeGoogleResult(JNIEnv* jenv, jobject thiz, jint Result)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BroadcastGoogleDelegate(EGoogleAuthenticationResult(Result));
}
#endif