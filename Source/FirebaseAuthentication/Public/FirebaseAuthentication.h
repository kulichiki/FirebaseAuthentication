#pragma once

#include "Engine.h"

class FFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;

private:
	static FFirebaseAuthenticationModule* GetModule();
};