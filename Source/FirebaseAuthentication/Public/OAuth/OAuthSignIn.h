#pragma once

#include "FirebaseResultCode.h"
#include "OAuthSignIn.generated.h"

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
class FIREBASEAUTHENTICATION_API UOAuthSignIn : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UOAuthSignIn* OAuthSignIn(EOAuthProvider OAuthProvider);
	void Activate() override;

private:
	void FirebaseResultCode(int StatusCode) override;
	EOAuthProvider OAuthProvider;
};
