#pragma once

#include "FirebaseResult.h"
#include "GoogleSignOut.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleSignOut : public UFirebaseResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignOut* GoogleSignOut();
	void Activate() override;

private:
	void FirebaseResult() override;
};
