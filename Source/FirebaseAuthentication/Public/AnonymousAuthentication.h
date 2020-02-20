#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "AnonymousAuthentication.generated.h"

UENUM(BlueprintType)
enum class EAnonymousAuthenticationResult : uint8
{
	SUCCESS			= 0 UMETA(DisplayName = "Success"),
	UNKNOWN_ERROR	= 1 UMETA(DisplayName = "Unknown Error")
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

	void Activate() override;
};