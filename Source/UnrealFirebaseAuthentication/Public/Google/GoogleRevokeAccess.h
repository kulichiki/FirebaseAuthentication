#pragma once

#include "Result.h"
#include "GoogleRevokeAccess.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleRevokeAccess : public UResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleRevokeAccess* GoogleRevokeAccess();
	void Activate() override;

private:
	void Result() override;
};
