#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "FirebaseResult.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFirebaseResult);

UCLASS()
class FIREBASEAUTHENTICATION_API UFirebaseResult : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FFirebaseResult OnResult;

private:
	virtual void FirebaseResult() {};
};
