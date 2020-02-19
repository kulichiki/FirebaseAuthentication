#include "FirebaseAuthentication.h"

#define LOCTEXT_NAMESPACE "FFirebaseAuthenticationModule"

void FFirebaseAuthenticationModule::StartupModule() {}
void FFirebaseAuthenticationModule::ShutdownModule() {}

/* Email/Password */
void FFirebaseAuthenticationModule::BindEmailPasswordDelegate(UEmailPasswordAuthentication* BindTo) { EmailPasswordDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastEmailPasswordDelegate(EEmailPasswordAuthenticationResult Result)
{
	EmailPasswordDelegate->Broadcast(Result);
	EmailPasswordDelegate = nullptr;
}

/* Anonymous */
void FFirebaseAuthenticationModule::BindAnonymousDelegate(UAnonymousAuthentication* BindTo) { AnonymousDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastAnonymousDelegate(EAnonymousAuthenticationResult Result)
{
	AnonymousDelegate->Broadcast(Result);
	AnonymousDelegate = nullptr;
}

/* Facebook */
void FFirebaseAuthenticationModule::BindFacebookDelegate(UFacebookAuthentication* BindTo) { FacebookDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastFacebookDelegate(EFacebookAuthenticationResult Result)
{
	FacebookDelegate->Broadcast(Result);
	FacebookDelegate = nullptr;
}

/* Google */
void FFirebaseAuthenticationModule::BindGoogleDelegate(UGoogleAuthentication* BindTo) { GoogleDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastGoogleDelegate(EGoogleAuthenticationResult Result)
{
	GoogleDelegate->Broadcast(Result);
	GoogleDelegate = nullptr;
}

/* OAuth */
void FFirebaseAuthenticationModule::BindOAuthDelegate(UOAuthAuthentication* BindTo) { OAuthDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastOAuthDelegate(EOAuthAuthenticationResult Result)
{
	OAuthDelegate->Broadcast(Result);
	OAuthDelegate = nullptr;
}

/* Phone */
void FFirebaseAuthenticationModule::BindPhoneDelegate(UPhoneAuthentication* BindTo) { PhoneDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastPhoneDelegate(EPhoneAuthenticationResult Result)
{
	PhoneDelegate->Broadcast(Result);
	PhoneDelegate = nullptr;
}

FFirebaseAuthenticationModule* FFirebaseAuthenticationModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FFirebaseAuthenticationModule>("FirebaseAuthentication");
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FFirebaseAuthenticationModule, FirebaseAuthentication)