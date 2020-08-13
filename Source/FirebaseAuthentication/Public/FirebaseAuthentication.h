#pragma once

#include "Engine.h"

#include "GoogleAuthentication.h"

class FFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;

	// Google
	void BindGoogleDelegate(UGoogleAuthentication* BindTo);
	void BroadcastGoogleDelegate(const EGoogleAuthenticationResult Result, const FString ServerAuthCode);

	static FFirebaseAuthenticationModule* GetModule();

private:
	// Delegates
	FGoogleAuthenticationResult* GoogleDelegate;
};