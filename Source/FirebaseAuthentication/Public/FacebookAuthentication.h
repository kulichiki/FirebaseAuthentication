#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "FacebookAuthentication.generated.h"

UENUM(BlueprintType)
enum class EFacebookAuthenticationResult : uint8
{
	SUCCESS			= 0 UMETA(DisplayName = "Success"),
	UNKNOWN_ERROR	= 1 UMETA(DisplayName = "Unknown Error")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFacebookAuthenticationResult, EFacebookAuthenticationResult, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UFacebookAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FFacebookAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|FacebookAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookAuthentication* FacebookSignIn();

	void Activate() override;
};