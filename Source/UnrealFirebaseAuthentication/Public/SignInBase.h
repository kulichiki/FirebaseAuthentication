#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SignInBase.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API USignInBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

private:
	virtual void SignInResult(int StatusCode) {};
};