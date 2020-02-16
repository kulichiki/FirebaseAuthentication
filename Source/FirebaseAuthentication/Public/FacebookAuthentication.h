#pragma once

#include "Base/FirebaseResultCode.h"
#include "FacebookAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UFacebookAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|FacebookAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookAuthentication* FacebookSignIn();

private:
	void FirebaseResultCode(int StatusCode) override;
};
