// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NLGPawnExtensionComponent.h"
#include "NLGLogChannels.h"
#include "NLGPawnData.h"

void UNLGPawnExtensionComponent::SetPawnData(const UNLGPawnData* InPawnData)
{
	check(InPawnData);

	APawn* Pawn = GetPawnChecked<APawn>();

	if (PawnData)
	{
		UE_LOG(LogNLG, Error, TEXT("Trying to set PawnData [%s] on pawn [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(Pawn), *GetNameSafe(PawnData));
		return;
	}

	PawnData = InPawnData;

	Pawn->ForceNetUpdate();
}
