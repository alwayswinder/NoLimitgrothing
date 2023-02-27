// Fill out your copyright notice in the Description page of Project Settings.


#include "NLGPlayerState.h"
#include "NLGLogChannels.h"
#include "Character/NLGPawnData.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NLGPlayerState)

ANLGPlayerState::ANLGPlayerState(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)

{
	//AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<ULyraAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
	//AbilitySystemComponent->SetIsReplicated(true);
	//AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//CreateDefaultSubobject<ULyraHealthSet>(TEXT("HealthSet"));
	//CreateDefaultSubobject<ULyraCombatSet>(TEXT("CombatSet"));

	//// AbilitySystemComponent needs to be updated at a high frequency.
	//NetUpdateFrequency = 100.0f;

	//MyTeamID = FGenericTeamId::NoTeam;
	//MySquadID = INDEX_NONE;
}

void ANLGPlayerState::SetPawnData(const UNLGPawnData* InPawnData)
{
	check(InPawnData);

	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	if (PawnData)
	{
		UE_LOG(LogNLG, Error, TEXT("Trying to set PawnData [%s] on player state [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(this), *GetNameSafe(PawnData));
		return;
	}

	PawnData = InPawnData;

	/*for (const ULyraAbilitySet* AbilitySet : PawnData->AbilitySets)
	{
		if (AbilitySet)
		{
			AbilitySet->GiveToAbilitySystem(AbilitySystemComponent, nullptr);
		}
	}

	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, NAME_LyraAbilityReady);*/

	ForceNetUpdate();
}
