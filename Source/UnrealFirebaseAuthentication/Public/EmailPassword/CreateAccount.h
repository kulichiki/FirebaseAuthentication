#pragma once

#include "ResultCode.h"
#include "CreateAccount.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UCreateAccount : public UResultCode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UCreateAccount* CreateAccount(FString Email, FString Password);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
