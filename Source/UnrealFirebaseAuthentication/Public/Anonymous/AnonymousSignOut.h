#pragma once

#include "CoreMinimal.h"
#include "Result.h"
#include "AnonymousSignOut.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnonymousSignOutResult);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UAnonymousSignOut : public UResult
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousSignOut* AnonymousSignOut();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FAnonymousSignOutResult OnSuccess;

private:
	void Result() override;
};
