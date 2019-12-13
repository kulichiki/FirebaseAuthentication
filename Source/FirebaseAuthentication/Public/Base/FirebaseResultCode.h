#pragma once

#include "FirebaseAuthentication.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FirebaseResultCode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFirebaseResultCode, ECommonStatusCode, StatusCode);

UCLASS()
class FIREBASEAUTHENTICATION_API UFirebaseResultCode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FFirebaseResultCode OnResult;

private:
	virtual void FirebaseResultCode(int StatusCode) {};
};