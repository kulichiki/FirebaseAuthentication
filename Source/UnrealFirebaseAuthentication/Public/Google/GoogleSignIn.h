#pragma once

#include "ResultCode.h"
#include "GoogleSignIn.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignIn : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignIn* GoogleSignIn();
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;
};
