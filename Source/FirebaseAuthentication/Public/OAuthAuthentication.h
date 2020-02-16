#pragma once

#include "FirebaseResultCode.h"
#include "OAuthAuthentication.generated.h"

UENUM(BlueprintType)
enum class EOAuthProvider : uint8
{
	Apple,
	Github,
	Microsoft,
	Yahoo,
	Twitter	
};

UCLASS()
class FIREBASEAUTHENTICATION_API UOAuthAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|OAuthAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UOAuthAuthentication* OAuthSignIn(EOAuthProvider OAuthProvider);

private:
	void FirebaseResultCode(int StatusCode) override;
};
