#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealFirebaseAuthentication.h"
#include "FirebaseAuthenticationLibrary.generated.h"

UCLASS()
class UNREALFIREBASEAUTHENTICATION_API UFirebaseAuthenticationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void AnonymousSignOut();

	UFUNCTION(BlueprintCallable)
	static void EmailPasswordSignOut();

	UFUNCTION(BlueprintCallable)
	static void PhoneSignOut();
};
