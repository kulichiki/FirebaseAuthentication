#pragma once

#include "ResultCode.h"
#include "ResendVerificationCode.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UResendVerificationCode : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UResendVerificationCode* ResendVerificationCode(FString PhoneNumber, int Timeout);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString PhoneNumber;
	int Timeout;
};
