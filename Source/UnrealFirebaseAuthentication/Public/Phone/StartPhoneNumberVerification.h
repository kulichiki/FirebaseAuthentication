#pragma once

#include "CoreMinimal.h"
#include "ResultCode.h"
#include "StartPhoneNumberVerification.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UStartPhoneNumberVerification : public UResultCode
{
	GENERATED_BODY()

public:
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UStartPhoneNumberVerification* StartPhoneNumberVerification(FString PhoneNumber, int Timeout);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString PhoneNumber;
	int Timeout;
};
