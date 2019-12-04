#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealFirebaseAuthenticationLibrary.generated.h"

UCLASS()
class UUnrealFirebaseAuthenticationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void GoogleSignIn();
};
