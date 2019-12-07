#pragma once

#include "CoreMinimal.h"
#include "SignInBase.h"
#include "GoogleSignIn.generated.h"

UENUM(BlueprintType)
enum class EStatusCode : uint8
{
	Success
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleSignInResult, int, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignIn : public USignInBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignIn* GoogleSignIn();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGoogleSignInResult OnSuccess;
	
	UPROPERTY(BlueprintAssignable)
	FGoogleSignInResult OnFailure;

private:
	void SignInResult(int StatusCode) override;
};
