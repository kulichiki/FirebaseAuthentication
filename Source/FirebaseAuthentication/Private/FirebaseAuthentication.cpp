#include "FirebaseAuthentication.h"

#define LOCTEXT_NAMESPACE "FFirebaseAuthenticationModule"

void FFirebaseAuthenticationModule::StartupModule() {}
void FFirebaseAuthenticationModule::ShutdownModule() {}

FFirebaseAuthenticationModule* FFirebaseAuthenticationModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FFirebaseAuthenticationModule>("FirebaseAuthentication");
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFirebaseAuthenticationModule, FirebaseAuthentication)