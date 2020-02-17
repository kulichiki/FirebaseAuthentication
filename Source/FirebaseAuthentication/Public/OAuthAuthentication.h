#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "OAuthAuthentication.generated.h"

UENUM(BlueprintType)
enum class EOAuthProvider : uint8
{
	Apple,
	Github,
	Microsoft,
	Yahoo,
	Twitter	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOAuthAuthenticationResult, int, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UOAuthAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOAuthAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|OAuthAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UOAuthAuthentication* OAuthSignIn(EOAuthProvider OAuthProvider);
};
