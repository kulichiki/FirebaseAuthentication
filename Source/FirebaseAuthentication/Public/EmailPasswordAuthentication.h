#pragma once

#include "FirebaseResultCode.h"
#include "EmailPasswordAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UEmailPasswordAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* EmailPasswordSignIn(FString Email, FString Password);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* CreateAccount(FString Email, FString Password);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* SendEmailVerification();

private:
	void FirebaseResultCode(int StatusCode) override;
};
