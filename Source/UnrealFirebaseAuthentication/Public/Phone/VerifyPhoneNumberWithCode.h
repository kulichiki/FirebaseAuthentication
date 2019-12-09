#pragma once

#include "CoreMinimal.h"
#include "ResultCode.h"
#include "VerifyPhoneNumberWithCode.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UVerifyPhoneNumberWithCode : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UVerifyPhoneNumberWithCode* VerifyPhoneNumberWithCode(FString Code);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString Code;
};
