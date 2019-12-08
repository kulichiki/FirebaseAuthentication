#pragma once

#include "ResultCode.h"
#include "AnonymousSignIn.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymousSignIn : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousSignIn* AnonymousSignIn();
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;
};
