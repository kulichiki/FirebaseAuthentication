#pragma once

#include "Base/FirebaseResultCode.h"
#include "FacebookSignIn.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UFacebookSignIn : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFacebookSignIn* FacebookSignIn();
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
};
