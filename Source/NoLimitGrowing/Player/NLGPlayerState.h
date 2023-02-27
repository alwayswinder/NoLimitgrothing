// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NLGPlayerState.generated.h"


class UNLGPawnData;

/**
 * 
 */
UCLASS()
class NOLIMITGROWING_API ANLGPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	ANLGPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	template <class T>
	const T* GetPawnData() const { return Cast<T>(PawnData); }

	void SetPawnData(const UNLGPawnData* InPawnData);

protected:
	UPROPERTY()
	TObjectPtr<const UNLGPawnData> PawnData;

};
