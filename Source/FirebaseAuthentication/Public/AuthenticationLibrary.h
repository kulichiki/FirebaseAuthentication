#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FirebaseAuthentication.h"
#include "AuthenticationLibrary.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAuthenticationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	static void AnonymousSignOut();

	UFUNCTION(BlueprintCallable)
	static void EmailPasswordSignOut();

	UFUNCTION(BlueprintCallable)
	static void PhoneSignOut();

	UFUNCTION(BlueprintCallable)
	static void OAuthSignOut();

	UFUNCTION(BlueprintCallable)
	static void FacebookSignOut();

private:
	static void FirebaseSignOut();
};
