#pragma once

#include "FirebaseResultCode.h"
#include "AnonymousAuthentication.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAnonymousAuthentication : public UFirebaseResultCode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousAuthentication* AnonymousSignIn();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAnonymousAuthentication* AnonymousLinkAccount(FString Email, FString Password);

private:
	void FirebaseResultCode(int StatusCode) override;
};
