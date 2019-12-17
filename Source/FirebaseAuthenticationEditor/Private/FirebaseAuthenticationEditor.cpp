#include "FirebaseAuthenticationEditor.h"
#include "ISettingsModule.h"
#include "FirebaseSettings.h"

#define LOCTEXT_NAMESPACE "FFirebaseAuthenticationEditorModule"

void FFirebaseAuthenticationEditorModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(TEXT("Project"), 
			TEXT("Firebase Authentication"), 
			TEXT("Facebook"),
			LOCTEXT("Facebook", "Facebook"),
			LOCTEXT("Facebook", "Settings for Facebook Authentication"),
			GetMutableDefault<UFirebaseSettings>());
	}
}

void FFirebaseAuthenticationEditorModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings(TEXT("Project"),
			TEXT("Firebase Authentication"),
			TEXT("Facebook"));
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFirebaseAuthenticationEditorModule, FirebaseAuthenticationEditor)