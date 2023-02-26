// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "NLGHeroComponent.generated.h"


struct FInputActionValue;
/**
 * 
 */
UCLASS(Blueprintable, Meta=(BlueprintSpawnableComponent))
class NOLIMITGROWING_API UNLGHeroComponent : public UPawnComponent
{
	GENERATED_BODY()
public:
	UNLGHeroComponent(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void InitializePlayerInput(UInputComponent* PlayerInputComponent);
	void Input_Move(const FInputActionValue& InputActionValue);

protected:
};
