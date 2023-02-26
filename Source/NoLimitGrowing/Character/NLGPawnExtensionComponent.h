// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "NLGPawnExtensionComponent.generated.h"


class UNLGPawnData;
/**
 * 
 */
UCLASS()
class NOLIMITGROWING_API UNLGPawnExtensionComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "NLG|Pawn")
	static UNLGPawnExtensionComponent* FindPawnExtensionComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UNLGPawnExtensionComponent>() : nullptr); }

	template <class T>
	const T* GetPawnData() const { return Cast<T>(PawnData); }

	void SetPawnData(const UNLGPawnData* InPawnData);
protected:

	UFUNCTION()
	void OnRep_PawnData();


	UPROPERTY(EditInstanceOnly, ReplicatedUsing = OnRep_PawnData, Category = "NLG|Pawn")
	TObjectPtr<const UNLGPawnData> PawnData;
};
