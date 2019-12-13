#pragma once

#include "FirebaseResultCode.h"
#include "SendEmailVerification.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API USendEmailVerification : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static USendEmailVerification* SendEmailVerification();
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
