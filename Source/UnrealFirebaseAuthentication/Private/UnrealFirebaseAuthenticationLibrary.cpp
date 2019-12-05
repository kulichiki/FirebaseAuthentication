#include "UnrealFirebaseAuthenticationLibrary.h"
#include "Engine.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UUnrealFirebaseAuthenticationLibrary::GoogleSignIn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleSignIn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID);
	}
#endif
}

void UUnrealFirebaseAuthenticationLibrary::Print(int Code)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(Code));
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_NativeGoogleSignInResult(JNIEnv* jenv, jobject thiz, jint StatusCode)
{
	int Code = StatusCode;
	UUnrealFirebaseAuthenticationLibrary::Print(Code);
}
#endif