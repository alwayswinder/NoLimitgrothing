// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "NLGWorldSettings.generated.h"


class UNLGExperienceDefinition;


UCLASS()
class NOLIMITGROWING_API ANLGWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	ANLGWorldSettings(const FObjectInitializer& ObjectInitializer);

	FPrimaryAssetId GetDefaultGameplayExperience() const;

protected:
	// The default experience to use when a server opens this map if it is not overridden by the user-facing experience
	UPROPERTY(EditDefaultsOnly, Category = GameMode)
	TSoftClassPtr<UNLGExperienceDefinition> DefaultGameplayExperience;

};
