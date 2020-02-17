#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "FacebookAuthentication.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFacebookAuthenticationResult, int, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UFacebookAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FFacebookAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|FacebookAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookAuthentication* FacebookSignIn();
};
