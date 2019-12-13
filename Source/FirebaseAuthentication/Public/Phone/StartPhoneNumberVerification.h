#pragma once

#include "FirebaseResultCode.h"
#include "StartPhoneNumberVerification.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UStartPhoneNumberVerification : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UStartPhoneNumberVerification* StartPhoneNumberVerification(FString PhoneNumber, int Timeout);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString PhoneNumber;
	int Timeout;
};
