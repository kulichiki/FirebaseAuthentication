#pragma once

#include "FirebaseResultCode.h"
#include "GoogleSignIn.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleSignIn : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignIn* GoogleSignIn();
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
};
