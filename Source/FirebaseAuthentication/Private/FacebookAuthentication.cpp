#include "FacebookAuthentication.h"
#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UFacebookAuthentication* UFacebookAuthentication::FacebookSignIn()
{
#if PLATFORM_ANDROID
	UAuthenticationLibrary::CallVoidMethod("AndroidThunkJava_FacebookSignIn", "()V");
#endif
	return NewObject<UFacebookAuthentication>();
}

void UFacebookAuthentication::Activate()
{
#if PLATFORM_ANDROID
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BindFacebookDelegate(this);
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_thegetaway_firebaseauthentication_FacebookAuthentication_NativeFacebookResult(JNIEnv* jenv, jobject thiz, jint Result)
{
	if (FFirebaseAuthenticationModule* Module = FFirebaseAuthenticationModule::GetModule())
		Module->BroadcastFacebookDelegate(EFacebookAuthenticationResult(Result));
}
#endif