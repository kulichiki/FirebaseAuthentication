#pragma once

#include "ResultCode.h"
#include "AnonymouslyLinkAccount.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymouslyLinkAccount : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymouslyLinkAccount* AnonymouslyLinkAccount(FString Email, FString Password);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;
	
	FString Email;
	FString Password;
};
