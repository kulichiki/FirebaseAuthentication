#pragma once

#include "CoreMinimal.h"
#include "SignOutBase.h"
#include "GoogleSignOut.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGoogleSignOutResult);

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleSignOut : public USignOutBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleSignOut* GoogleSignOut();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGoogleSignOutResult OnSuccess;

private:
	void SignOutResult() override;
};
