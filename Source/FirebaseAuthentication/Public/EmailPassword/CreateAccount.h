#pragma once

#include "FirebaseResultCode.h"
#include "CreateAccount.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UCreateAccount : public UFirebaseResultCode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UCreateAccount* CreateAccount(FString Email, FString Password);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;

	FString Email;
	FString Password;
};
