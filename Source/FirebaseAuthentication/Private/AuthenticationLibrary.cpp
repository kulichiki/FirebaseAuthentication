#include "AuthenticationLibrary.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
#endif

void UAuthenticationLibrary::CallVoidMethod(const char* Name, const char* Signature, ...)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		// Get Arguments list
		va_list Arguments;
		va_start(Arguments, Signature);

		// Call Java method
		jmethodID JMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, Name, Signature, false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, JMethod, Arguments);
		
		va_end(Arguments);
	}
#endif
}

FString UAuthenticationLibrary::GoogleGetServerAuthCode()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jmethodID MethodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GoogleGetServerAuthCode", "()Ljava/lang/String;", false);
		jstring String = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, MethodID);
		
		const char* Chars = Env->GetStringUTFChars(String, 0);
		const FString ServerAuthCode = FString(Chars);

		Env->ReleaseStringUTFChars(String, Chars);
		Env->DeleteLocalRef(String);

		return ServerAuthCode;
	}
#endif
	return "";
}
