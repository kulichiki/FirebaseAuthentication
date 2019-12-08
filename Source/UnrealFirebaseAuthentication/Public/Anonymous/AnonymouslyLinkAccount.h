#pragma once

#include "CoreMinimal.h"
#include "ResultCode.h"
#include "UnrealFirebaseAuthentication.h"
#include "AnonymouslyLinkAccount.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnonymouslyLinkAccountResult, ECommonStatusCode, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymouslyLinkAccount : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymouslyLinkAccount* AnonymouslyLinkAccount(FString Email, FString Password);
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FAnonymouslyLinkAccountResult OnResult;

private:
	void ResultCode(int StatusCode) override;
	
	FString Email;
	FString Password;
};
