#include "FirebaseAuthentication.h"

#define LOCTEXT_NAMESPACE "FFirebaseAuthenticationModule"

void FFirebaseAuthenticationModule::StartupModule() {}
void FFirebaseAuthenticationModule::ShutdownModule() {}

/* Google */
void FFirebaseAuthenticationModule::BindGoogleDelegate(UGoogleAuthentication* BindTo) { GoogleDelegate = &BindTo->OnResult; }
void FFirebaseAuthenticationModule::BroadcastGoogleDelegate(const EGoogleAuthenticationResult Result, const FString ServerAuthCode)
{
	if (GoogleDelegate == nullptr) return;
	GoogleDelegate->Broadcast(Result, ServerAuthCode);

	// Clear
	GoogleDelegate = nullptr;
}

FFirebaseAuthenticationModule* FFirebaseAuthenticationModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FFirebaseAuthenticationModule>("FirebaseAuthentication");
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FFirebaseAuthenticationModule, FirebaseAuthentication)