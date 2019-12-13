#pragma once

#include "ResultCode.h"
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
class UNREALFIREBASEAUTHENTICATION_API UOAuthSignIn : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UOAuthSignIn* OAuthSignIn(EOAuthProvider OAuthProvider);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;
	EOAuthProvider OAuthProvider;
};
