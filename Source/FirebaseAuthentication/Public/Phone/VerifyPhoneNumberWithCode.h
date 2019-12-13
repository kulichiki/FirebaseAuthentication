#pragma once

#include "FirebaseResultCode.h"
#include "VerifyPhoneNumberWithCode.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UVerifyPhoneNumberWithCode : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UVerifyPhoneNumberWithCode* VerifyPhoneNumberWithCode(FString Code);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString Code;
};
