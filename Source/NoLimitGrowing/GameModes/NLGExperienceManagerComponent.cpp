// Copyright Epic Games, Inc. All Rights Reserved.

#include "NLGExperienceManagerComponent.h"
#include "System/NLGAssetManager.h"
#include "NLGExperienceDefinition.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NLGExperienceManagerComponent)

UNLGExperienceManagerComponent::UNLGExperienceManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}


void UNLGExperienceManagerComponent::ServerSetCurrentExperience(FPrimaryAssetId ExperienceId)
{
	UNLGAssetManager& AssetManager = UNLGAssetManager::Get();
	FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(ExperienceId);
	TSubclassOf<UNLGExperienceDefinition> AssetClass = Cast<UClass>(AssetPath.TryLoad());
	check(AssetClass);
	const UNLGExperienceDefinition* Experience = GetDefault<UNLGExperienceDefinition>(AssetClass);

	check(Experience != nullptr);
	check(CurrentExperience == nullptr);
	CurrentExperience = Experience;
	//StartExperienceLoad();
}

bool UNLGExperienceManagerComponent::IsExperienceLoaded() const
{
	//return (LoadState == ELyraExperienceLoadState::Loaded) && (CurrentExperience != nullptr);
	return CurrentExperience != nullptr;
}

const UNLGExperienceDefinition* UNLGExperienceManagerComponent::GetCurrentExperienceChecked() const
{
	//check(LoadState == ELyraExperienceLoadState::Loaded);
	check(CurrentExperience != nullptr);
	return CurrentExperience;
}

