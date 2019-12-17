#pragma once

#include "Engine.h"

class FFirebaseAuthenticationEditorModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
};