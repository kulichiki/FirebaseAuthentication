#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FSignInResult, int);

class FUnrealFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
	static FUnrealFirebaseAuthenticationModule* GetModule();

	FSignInResult SignInResult;
};