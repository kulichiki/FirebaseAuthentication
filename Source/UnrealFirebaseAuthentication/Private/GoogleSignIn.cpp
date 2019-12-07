#include "GoogleSignIn.h"
#include "UnrealFirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UGoogleSignIn* UGoogleSignIn::GoogleSignIn()
{
	UGoogleSignIn* BlueprintNode = NewObject<UGoogleSignIn>();
	return BlueprintNode;
}

void UGoogleSignIn::Activate()
{
	Super::Activate();
	
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleSignIn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UGoogleSignIn::SignInResult(int StatusCode)
{
	OnSuccess.Broadcast(StatusCode);
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeGoogleSignInResult(JNIEnv* jenv, jobject thiz, jint StatusCode)
{
	if (FUnrealFirebaseAuthenticationModule* Module = FUnrealFirebaseAuthenticationModule::GetModule())
	{
		Module->SignInResult.Broadcast(StatusCode);
		Module->SignInResult.Clear();
	}
}
#endif