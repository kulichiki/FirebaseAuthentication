#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuthenticationLibrary.generated.h"

UCLASS()
class FIREBASEAUTHENTICATION_API UAuthenticationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "FirebaseAuthentication | GoogleAuthentication")
	static FString GoogleGetServerAuthCode();

	static void CallVoidMethod(const char* Name, const char* Signature, ...);
};