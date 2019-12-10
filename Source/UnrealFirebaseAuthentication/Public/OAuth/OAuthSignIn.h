#pragma once

#include "ResultCode.h"
#include "OAuthSignIn.generated.h"

UENUM(BlueprintType)
enum class EProviderCode : uint8
{
	apple		= 0		UMETA(DisplayName = "Apple"),
	github		= 1		UMETA(DisplayName = "Github"),
	microsoft	= 2		UMETA(DisplayName = "Microsoft"),
	yahoo		= 3		UMETA(DisplayName = "Yahoo"),
	twitter		= 4		UMETA(DisplayName = "Twitter"),
};

UCLASS()
class ANALYTICSPROJECT_API UOAuthSignIn : public UResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UOAuthSignIn* OAuthSignIn(EProviderCode ProviderCode);
	void Activate() override;

private:
	void ResultCode(int StatusCode) override;
	EProviderCode ProviderCode;
};
