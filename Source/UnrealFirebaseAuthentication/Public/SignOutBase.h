#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SignOutBase.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API USignOutBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

private:
	virtual void SignOutResult() {};
};
