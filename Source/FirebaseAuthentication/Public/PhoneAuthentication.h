#pragma once

#include "FirebaseResultCode.h"
#include "PhoneAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UPhoneAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* StartPhoneNumberVerification(FString PhoneNumber, int Timeout);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* ResendVerificationCode(FString PhoneNumber, int Timeout);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* VerifyPhoneNumberWithCode(FString Code);

private:
	void FirebaseResultCode(int StatusCode) override;
};
