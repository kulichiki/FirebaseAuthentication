#pragma once

#include "FirebaseResultCode.h"
#include "AnonymousLinkAccount.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAnonymousLinkAccount : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousLinkAccount* AnonymousLinkAccount(FString Email, FString Password);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
	
	FString Email;
	FString Password;
};
