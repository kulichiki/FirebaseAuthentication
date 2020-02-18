#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "AnonymousAuthentication.generated.h"

UENUM(BlueprintType)
enum class EAnonymousAuthenticationResult : uint8
{
	Success,
	Failed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnonymousAuthenticationResult, EAnonymousAuthenticationResult, Result);

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
