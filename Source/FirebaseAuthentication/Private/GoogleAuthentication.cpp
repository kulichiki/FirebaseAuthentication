#include "GoogleAuthentication.h"
#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleCodeResult* UGoogleCodeResult::GoogleSignIn()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleSignIn", "()V");
	return NewObject<UGoogleCodeResult>();
#endif
	
	return nullptr;
}

UGoogleResult* UGoogleResult::GoogleSignOut()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleSignOut", "()V");
	return NewObject<UGoogleResult>();
#endif

	return nullptr;
}

UGoogleResult* UGoogleResult::GoogleRevokeAccess()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_GoogleRevokeAccess", "()V");
	return NewObject<UGoogleResult>();
#endif

	return nullptr;
}

void UGoogleCodeResult::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->BindGoogleCodeResult(this);
	}
#endif
}

void UGoogleResult::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->BindGoogleResult(this);
	}
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_kulichin_firebaseauthentication_GoogleAuthentication_NativeGoogleResult(JNIEnv* jenv, jobject thiz)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->BroadcastGoogleResult();
	}
}

JNI_METHOD void Java_com_kulichin_firebaseauthentication_GoogleAuthentication_NativeGoogleCodeResult(JNIEnv* jenv, jobject thiz, jint Code)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
	{
		Module->BroadcastGoogleCodeResult(EGoogleAuthenticationResult(Code));
	}
}
#endif