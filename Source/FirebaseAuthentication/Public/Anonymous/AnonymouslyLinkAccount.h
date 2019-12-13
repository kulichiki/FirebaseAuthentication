#pragma once

#include "FirebaseResultCode.h"
#include "AnonymouslyLinkAccount.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAnonymouslyLinkAccount : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymouslyLinkAccount* AnonymouslyLinkAccount(FString Email, FString Password);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
	
	FString Email;
	FString Password;
};
