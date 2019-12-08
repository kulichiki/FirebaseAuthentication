#pragma once

#include "CoreMinimal.h"
#include "SignInBase.h"
#include "UnrealFirebaseAuthentication.h"
#include "AnonymousSignIn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnonymousSignInResult, ECommonStatusCode, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymousSignIn : public USignInBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousSignIn* AnonymousSignIn();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FAnonymousSignInResult OnResult;

private:
	void SignInResult(int StatusCode) override;
};
