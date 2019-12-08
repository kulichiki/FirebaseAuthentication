#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

UENUM(BlueprintType)
enum class ECommonStatusCode : uint8
{
	SUCCESS							= 0		UMETA(DisplayName = "Success"),
	SERVICE_VERSION_UPDATE_REQUIRED = 2		UMETA(DisplayName = "Service Version Update Required"),
	SERVICE_DISABLED				= 3		UMETA(DisplayName = "Service Disabled"),
	SIGN_IN_REQUIRED				= 4		UMETA(DisplayName = "Sign In Required"),
	INVALID_ACCOUNT					= 5		UMETA(DisplayName = "Invalid Account"),
	RESOLUTION_REQUIRED				= 6		UMETA(DisplayName = "Resolution Required"),
	NETWORK_ERROR					= 7		UMETA(DisplayName = "Network Error"),
	INTERNAL_ERROR					= 8		UMETA(DisplayName = "Internal Error"),
	DEVELOPER_ERROR					= 10	UMETA(DisplayName = "Developer Error"),
	ERROR							= 13	UMETA(DisplayName = "Error"),
	INTERRUPTED						= 14	UMETA(DisplayName = "Interrupted"),
	TIMEOUT							= 15	UMETA(DisplayName = "Timeout"),
	CANCELED						= 16	UMETA(DisplayName = "Canceled"),
	API_NOT_CONNECTED				= 17	UMETA(DisplayName = "API Not Connected"),
	
	// Additional
	SIGN_IN_CANCELLED				= 20	UMETA(DisplayName = "Sign In Cancelled"),
	SIGN_IN_CURRENTLY_IN_PROGRESS	= 21	UMETA(DisplayName = "Sign In Currently In Progress"),
	SIGN_IN_FAILED					= 22	UMETA(DisplayName = "Sign In Failed")
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOtherResult, int);
DECLARE_MULTICAST_DELEGATE_OneParam(FSignInResult, int);
DECLARE_MULTICAST_DELEGATE(FSignOutResult);

class FUnrealFirebaseAuthenticationModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
	static FUnrealFirebaseAuthenticationModule* GetModule();

	FOtherResult OtherResult;
	FSignInResult SignInResult;
	FSignOutResult SignOutResult;
};