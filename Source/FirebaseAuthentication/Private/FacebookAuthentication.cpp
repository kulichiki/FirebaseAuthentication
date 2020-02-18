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