#pragma once

#include "Engine.h"

#include "GoogleAuthentication.h"

class FFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
	static FFirebaseAuthenticationModule* GetModule();

	// Google
	void BindGoogleResult(UGoogleResult* GoogleResult);
	void BindGoogleCodeResult(UGoogleCodeResult* GoogleCodeResult);
	void BroadcastGoogleResult();
	void BroadcastGoogleCodeResult(const EGoogleAuthenticationResult Code);

private:
	// Delegates
	TSharedPtr<FGoogleAuthenticationResult> GoogleResultDelegate;
	TSharedPtr<FGoogleAuthenticationCodeResult> GoogleCodeResultDelegate;
};