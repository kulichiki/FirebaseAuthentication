#pragma once

#include "Result.h"
#include "AnonymousSignOut.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymousSignOut : public UResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousSignOut* AnonymousSignOut();
	void Activate() override;

private:
	void Result() override;
};
