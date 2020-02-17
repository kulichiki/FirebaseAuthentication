#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "PhoneAuthentication.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhoneAuthenticationResult, int, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UPhoneAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FPhoneAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* StartPhoneNumberVerification(FString PhoneNumber, int Timeout);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* ResendVerificationCode(FString PhoneNumber, int Timeout);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UPhoneAuthentication* VerifyPhoneNumberWithCode(FString Code);
};
