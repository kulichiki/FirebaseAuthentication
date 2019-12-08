#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Result.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UResult : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

private:
	virtual void Result() {};
};
