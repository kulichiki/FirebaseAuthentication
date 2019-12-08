#pragma once

#include "Result.h"
#include "GoogleSignOut.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignOut : public UResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignOut* GoogleSignOut();
	void Activate() override;

private:
	void Result() override;
};
