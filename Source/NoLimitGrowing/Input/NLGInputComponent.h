// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "NLGInputComponent.generated.h"

/**
 * 
 */
UCLASS(Config = Input)
class NOLIMITGROWING_API UNLGInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	UNLGInputComponent(const FObjectInitializer& ObjectInitializer);
};
