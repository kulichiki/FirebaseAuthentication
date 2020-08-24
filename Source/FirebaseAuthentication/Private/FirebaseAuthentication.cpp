#include "FirebaseAuthentication.h"

#define LOCTEXT_NAMESPACE "FFirebaseAuthenticationModule"

void FFirebaseAuthenticationModule::StartupModule() {}
void FFirebaseAuthenticationModule::ShutdownModule() {}

FFirebaseAuthenticationModule* FFirebaseAuthenticationModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FFirebaseAuthenticationModule>("FirebaseAuthentication");
}

void FFirebaseAuthenticationModule::BindGoogleResult(UGoogleResult* GoogleResult)
{
	GoogleResultDelegate = MakeShareable(&GoogleResult->OnResult);
}

void FFirebaseAuthenticationModule::BindGoogleCodeResult(UGoogleCodeResult* GoogleCodeResult)
{
	GoogleCodeResultDelegate = MakeShareable(&GoogleCodeResult->OnResult);
}

void FFirebaseAuthenticationModule::BroadcastGoogleResult()
{
	if (GoogleResultDelegate)
	{
		GoogleResultDelegate->Broadcast();
		GoogleResultDelegate.Reset();
	}
}

void FFirebaseAuthenticationModule::BroadcastGoogleCodeResult(const EGoogleAuthenticationResult Code)
{
	if (GoogleCodeResultDelegate)
	{
		GoogleCodeResultDelegate->Broadcast(Code);
		GoogleCodeResultDelegate.Reset();
	}
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FFirebaseAuthenticationModule, FirebaseAuthentication)