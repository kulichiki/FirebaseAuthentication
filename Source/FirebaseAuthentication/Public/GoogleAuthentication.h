#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "GoogleAuthentication.generated.h"

UENUM(BlueprintType)
enum class EGoogleAuthenticationResult : uint8
{
	SUCCESS			= 0 UMETA(DisplayName = "Success"),
	UNKNOWN_ERROR	= 1 UMETA(DisplayName = "Unknown Error")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGoogleAuthenticationResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleAuthenticationCodeResult, EGoogleAuthenticationResult, Code);

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleResult : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGoogleAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication | GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleResult* GoogleSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication | GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleResult* GoogleRevokeAccess();

	void Activate() override;
};

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleCodeResult : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGoogleAuthenticationCodeResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication | GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleCodeResult* GoogleSignIn();

	void Activate() override;
};
