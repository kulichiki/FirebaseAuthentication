#pragma once

#include "ResultCode.h"
#include "EmailPasswordSignIn.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UEmailPasswordSignIn : public UResultCode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordSignIn* EmailPasswordSignIn(FString Email, FString Password);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
