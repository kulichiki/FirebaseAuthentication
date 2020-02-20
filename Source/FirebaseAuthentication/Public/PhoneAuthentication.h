#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "PhoneAuthentication.generated.h"

UENUM(BlueprintType)
enum class EPhoneAuthenticationResult : uint8
{
	SUCCESS					= 0 UMETA(DisplayName = "Success"),
	INVALID_PHONE_NUMBER	= 1 UMETA(DisplayName = "Invalid Phone Number"),
	SMS_QUOTA				= 2 UMETA(DisplayName = "SMS Quota"),
	RESEND_TOKEN_NOT_VALID	= 3 UMETA(DisplayName = "Resend Token Not Valid"),
	INVALID_CODE			= 4 UMETA(DisplayName = "Invalid Code"),
	UNKNOWN_ERROR			= 5 UMETA(DisplayName = "Unknown Error")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPhoneAuthenticationResult, EPhoneAuthenticationResult, Result);

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

	void Activate() override;
};