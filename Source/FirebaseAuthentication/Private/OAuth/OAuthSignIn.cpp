#include "OAuthSignIn.h"
#include "FirebaseAuthentication.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

UOAuthSignIn* UOAuthSignIn::OAuthSignIn(EOAuthProvider OAuthProvider)
{
	UOAuthSignIn* BlueprintNode = NewObject<UOAuthSignIn>();
	BlueprintNode->OAuthProvider = OAuthProvider;
	return BlueprintNode;
}

void UOAuthSignIn::Activate()
{
	Super::Activate();

#if PLATFORM_ANDROID	
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring JProviderURL;
		switch (OAuthProvider)
		{
		case EOAuthProvider::Apple:
			JProviderURL = Env->NewStringUTF("apple.com");
		case EOAuthProvider::Github:
			JProviderURL = Env->NewStringUTF("github.com");
		case EOAuthProvider::Microsoft:
			JProviderURL = Env->NewStringUTF("microsoft.com");
		case EOAuthProvider::Yahoo:
			JProviderURL = Env->NewStringUTF("yahoo.com");
		case EOAuthProvider::Twitter:
			JProviderURL = Env->NewStringUTF("twitter.com");
		}
		
		static jmethodID JMethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_OAuthSignIn", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethodID, JProviderURL);

		Env->DeleteLocalRef(JProviderURL);
	}
#endif
}

void UOAuthSignIn::FirebaseResultCode(int StatusCode)
{
	ECommonStatusCode Code = ECommonStatusCode(StatusCode);
	if (StatusCode == 12500)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_FAILED);
	else if (StatusCode == 12501)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_CANCELLED);
	else if (StatusCode == 12502)
		OnResult.Broadcast(ECommonStatusCode::SIGN_IN_CURRENTLY_IN_PROGRESS);
	else
		OnResult.Broadcast(Code);
}