#pragma once

#include "UnrealFirebaseAuthentication.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ResultCode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResultCodeDelegate, ECommonStatusCode, StatusCode);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UResultCode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FResultCodeDelegate OnResult;

private:
	virtual void ResultCode(int StatusCode) {};
};