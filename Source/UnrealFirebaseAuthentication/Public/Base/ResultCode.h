#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ResultCode.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UResultCode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

private:
	virtual void ResultCode(int StatusCode) {};
};