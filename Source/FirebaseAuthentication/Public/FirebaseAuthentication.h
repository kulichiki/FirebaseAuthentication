#pragma once

#include "Engine.h"

#include "EmailPasswordAuthentication.h"
#include "AnonymousAuthentication.h"
#include "FacebookAuthentication.h"
#include "GoogleAuthentication.h"
#include "OAuthAuthentication.h"
#include "PhoneAuthentication.h"

class FFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;

	// Email/Password
	void BindEmailPasswordDelegate(UEmailPasswordAuthentication* BindTo);
	void BroadcastEmailPasswordDelegate(EEmailPasswordAuthenticationResult Result);

	// Anonymous
	void BindAnonymousDelegate(UAnonymousAuthentication* BindTo);
	void BroadcastAnonymousDelegate(EAnonymousAuthenticationResult Result);

	// Facebook
	void BindFacebookDelegate(UFacebookAuthentication* BindTo);
	void BroadcastFacebookDelegate(EFacebookAuthenticationResult Result);

	// Google
	void BindGoogleDelegate(UGoogleAuthentication* BindTo);
	void BroadcastGoogleDelegate(EGoogleAuthenticationResult Result);

	// OAuth
	void BindOAuthDelegate(UOAuthAuthentication* BindTo);
	void BroadcastOAuthDelegate(EOAuthAuthenticationResult Result);

	// Phone
	void BindPhoneDelegate(UPhoneAuthentication* BindTo);
	void BroadcastPhoneDelegate(EPhoneAuthenticationResult Result);

	static FFirebaseAuthenticationModule* GetModule();

private:
	// Delegates
	FEmailPasswordAuthenticationResult* EmailPasswordDelegate;
	FAnonymousAuthenticationResult* AnonymousDelegate;
	FFacebookAuthenticationResult* FacebookDelegate;
	FGoogleAuthenticationResult* GoogleDelegate;
	FOAuthAuthenticationResult* OAuthDelegate;
	FPhoneAuthenticationResult* PhoneDelegate;
};