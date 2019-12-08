#pragma once

#include "CoreMinimal.h"
#include "SignInBase.h"
#include "UnrealFirebaseAuthentication.h"
#include "GoogleSignIn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleSignInResult, ECommonStatusCode, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignIn : public USignInBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignIn* GoogleSignIn();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGoogleSignInResult OnResult;

private:
	void SignInResult(int StatusCode) override;
};
