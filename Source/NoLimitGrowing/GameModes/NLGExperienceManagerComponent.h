// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LoadingProcessInterface.h"
#include "Components/GameStateComponent.h"
#include "NLGExperienceManagerComponent.generated.h"

class UNLGExperienceDefinition;


UCLASS()
class UNLGExperienceManagerComponent final : public UGameStateComponent, public ILoadingProcessInterface
{
	GENERATED_BODY()

public:
	UNLGExperienceManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#if WITH_SERVER_CODE
	void ServerSetCurrentExperience(FPrimaryAssetId ExperienceId);
#endif

	// Returns true if the experience is fully loaded
	bool IsExperienceLoaded() const;

	const UNLGExperienceDefinition* GetCurrentExperienceChecked() const;
private:
	UPROPERTY()
	TObjectPtr<const UNLGExperienceDefinition> CurrentExperience;

};