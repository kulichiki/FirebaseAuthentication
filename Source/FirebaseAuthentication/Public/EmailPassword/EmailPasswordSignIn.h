#pragma once

#include "FirebaseResultCode.h"
#include "EmailPasswordSignIn.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UEmailPasswordSignIn : public UFirebaseResultCode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordSignIn* EmailPasswordSignIn(FString Email, FString Password);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
