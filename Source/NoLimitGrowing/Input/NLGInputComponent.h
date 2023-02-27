// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "NLGInputConfig.h"
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

	void AddInputMappings(const UNLGInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const;

	template<class UserClass, typename FuncType>
	void BindNativeAction(const UNLGInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound);

};

template<class UserClass, typename FuncType>
void UNLGInputComponent::BindNativeAction(const UNLGInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound)
{
	check(InputConfig);
	if (const UInputAction* IA = InputConfig->FindNativeInputActionForTag(InputTag, bLogIfNotFound))
	{
		BindAction(IA, TriggerEvent, Object, Func);
	}
}
