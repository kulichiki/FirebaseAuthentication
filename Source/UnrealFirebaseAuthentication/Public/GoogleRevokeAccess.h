#pragma once

#include "CoreMinimal.h"
#include "SignOutBase.h"
#include "GoogleSignOut.h"
#include "GoogleRevokeAccess.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UGoogleRevokeAccess : public USignOutBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGoogleRevokeAccess* GoogleRevokeAccess();
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGoogleSignOutResult OnSuccess;

private:
	void SignOutResult() override;
};
