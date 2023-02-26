// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NLGPawnData.generated.h"


class UNLGInputConfig;
/**
 * 
 */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "NLG Pawn Data", ShortTooltip = "Data asset used to define a Pawn."))
class NOLIMITGROWING_API UNLGPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UNLGPawnData(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NLG|Input")
	TObjectPtr<UNLGInputConfig> InputConfig;
};
