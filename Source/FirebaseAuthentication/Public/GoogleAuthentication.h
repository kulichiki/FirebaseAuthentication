#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "GoogleAuthentication.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleAuthenticationResult, int, Result);

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
