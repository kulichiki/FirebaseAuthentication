#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "Result.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResultDelegate);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UResult : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FResultDelegate OnResult;

private:
	virtual void Result() {};
};
