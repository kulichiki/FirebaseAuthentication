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

private:
	static FFirebaseAuthenticationModule* GetModule();

	// Delegates
	FEmailPasswordAuthenticationResult EmailPasswordResult;
	FAnonymousAuthenticationResult AnonymousResult;
	FFacebookAuthenticationResult FacebookResult;
	FGoogleAuthenticationResult GoogleResult;
	FOAuthAuthenticationResult OAuthResult;
	FPhoneAuthenticationResult PhoneResult;
};