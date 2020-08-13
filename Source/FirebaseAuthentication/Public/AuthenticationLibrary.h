#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuthenticationLibrary.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAuthenticationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|AnonymousAuthentication")
	static void AnonymousSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|EmailPasswordAuthentication")
	static void EmailPasswordSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|PhoneAuthentication")
	static void PhoneSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|OAuthAuthentication")
	static void OAuthSignOut();

	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication|FacebookAuthentication")
	static void FacebookSignOut();

	static void CallVoidMethod(const char* Name, const char* Signature, ...);

private:
	static void FirebaseSignOut();
};