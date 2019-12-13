#pragma once

#include "FirebaseResultCode.h"
#include "AnonymousSignIn.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAnonymousSignIn : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousSignIn* AnonymousSignIn();
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
};
