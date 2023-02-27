// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NLGExperienceDefinition.generated.h"

class UNLGPawnData;
class UNLGExperienceActionSet;

/**
 * Definition of an experience
 */
UCLASS(BlueprintType, Const)
class UNLGExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UNLGExperienceDefinition();

public:

	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TObjectPtr<const UNLGPawnData> DefaultPawnData;
};
