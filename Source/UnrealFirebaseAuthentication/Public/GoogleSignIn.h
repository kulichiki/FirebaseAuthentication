#pragma once

#include "CoreMinimal.h"
#include "SignInBase.h"
#include "GoogleSignIn.generated.h"

UENUM(BlueprintType)
enum class EStatusCode : uint8
{
	API_NOT_CONNECTED				= 17,
	CANCELED						= 16,
	DEVELOPER_ERROR					= 10,
	ERROR							= 13,
	INTERNAL_ERROR					= 8,
	INTERRUPTED						= 14,
	INVALID_ACCOUNT					= 5,
	NETWORK_ERROR					= 7,
	RESOLUTION_REQUIRED				= 6,
	SERVICE_DISABLED				= 3,
	SERVICE_VERSION_UPDATE_REQUIRED = 2,
	SIGN_IN_REQUIRED				= 4,
	SUCCESS							= 0,
	TIMEOUT							= 15
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGoogleSignInResult, EStatusCode, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignIn : public USignInBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignIn* GoogleSignIn();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGoogleSignInResult OnSuccess;
	
	UPROPERTY(BlueprintAssignable)
	FGoogleSignInResult OnFailure;

private:
	void SignInResult(int StatusCode) override;
};
