#pragma once

#include "ResultCode.h"
#include "SendEmailVerification.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API USendEmailVerification : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static USendEmailVerification* SendEmailVerification();
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
