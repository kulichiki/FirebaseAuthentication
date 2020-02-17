#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "EmailPasswordAuthentication.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmailPasswordAuthenticationResult, int, Result);

UCLASS()
class FIREBASEAUTHENTICATION_API UEmailPasswordAuthentication : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FEmailPasswordAuthenticationResult OnResult;

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* EmailPasswordSignIn(FString Email, FString Password);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* CreateAccount(FString Email, FString Password);

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication", meta = (BlueprintInternalUseOnly = "true"))
	static UEmailPasswordAuthentication* SendEmailVerification();
};
