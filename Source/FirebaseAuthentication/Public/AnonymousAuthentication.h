#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "AnonymousAuthentication.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnonymousAuthenticationResult, int, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UAnonymousAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAnonymousAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|AnonymousAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousAuthentication* AnonymousSignIn();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|AnonymousAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousAuthentication* AnonymousLinkAccount(FString Email, FString Password);
};
