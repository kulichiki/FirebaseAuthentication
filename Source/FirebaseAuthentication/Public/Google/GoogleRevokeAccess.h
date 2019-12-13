#pragma once

#include "FirebaseResult.h"
#include "GoogleRevokeAccess.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleRevokeAccess : public UFirebaseResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleRevokeAccess* GoogleRevokeAccess();
	void Activate() override;

private:
	void FirebaseResult() override;
};
