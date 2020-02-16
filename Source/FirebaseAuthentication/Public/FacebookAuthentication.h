#pragma once

#include "Base/FirebaseResultCode.h"
#include "FacebookAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UFacebookAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookAuthentication* FacebookSignIn();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookAuthentication* FacebookSignOut();

private:
	void FirebaseResultCode(int StatusCode) override;
};
