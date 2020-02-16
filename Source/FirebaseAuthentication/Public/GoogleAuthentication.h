#pragma once

#include "FirebaseResultCode.h"
#include "GoogleAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UGoogleAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleSignIn();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleSignOut();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleAuthentication* GoogleRevokeAccess();

private:
	void FirebaseResultCode(int StatusCode) override;
};
