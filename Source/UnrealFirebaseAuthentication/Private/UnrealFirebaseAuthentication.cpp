#include "UnrealFirebaseAuthentication.h"

#define LOCTEXT_NAMESPACE "FUnrealFirebaseAuthenticationModule"

void FUnrealFirebaseAuthenticationModule::StartupModule() {}
void FUnrealFirebaseAuthenticationModule::ShutdownModule() {}

FUnrealFirebaseAuthenticationModule* FUnrealFirebaseAuthenticationModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FUnrealFirebaseAuthenticationModule>("UnrealFirebaseAuthentication");
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealFirebaseAuthenticationModule, UnrealFirebaseAuthentication)