#pragma once

#include "FirebaseResultCode.h"
#include "ResendVerificationCode.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UResendVerificationCode : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UResendVerificationCode* ResendVerificationCode(FString PhoneNumber, int Timeout);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString PhoneNumber;
	int Timeout;
};
