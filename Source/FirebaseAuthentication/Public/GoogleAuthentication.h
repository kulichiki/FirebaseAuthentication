#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "GoogleAuthentication.generated.h"

UENUM(BlueprintType)
enum class EGoogleAuthenticationResult : uint8
{
	Success,
	Failed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleAuthenticationResult, EGoogleAuthenticationResult, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGoogleAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleSignIn();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|GoogleAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleRevokeAccess();
};
