#pragma once

#include "Result.h"
#include "EmailPasswordSignOut.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UEmailPasswordSignOut : public UResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordSignOut* EmailPasswordSignOut();
	void Activate() override;

private:
	void Result() override;
};