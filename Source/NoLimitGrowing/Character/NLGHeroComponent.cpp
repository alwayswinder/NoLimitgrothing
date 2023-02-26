// Fill out your copyright notice in the Description page of Project Settings.


#include "NLGHeroComponent.h"
#include "InputActionValue.h"
#include "Player/NLGLocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "NLGPawnExtensionComponent.h"
#include "NLGPawnData.h"
#include "Input/NLGInputComponent.h"
#include "NLGGameplayTags.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NLGHeroComponent)

UNLGHeroComponent::UNLGHeroComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void UNLGHeroComponent::InitializePlayerInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	const APawn* Pawn = GetPawn<APawn>();
	if (!Pawn)
	{
		return;
	}
	
	const APlayerController* PC = GetController<APlayerController>();
	check(PC);

	const UNLGLocalPlayer* LP = Cast<UNLGLocalPlayer>(PC->GetLocalPlayer());
	check(LP);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	
	if (const UNLGPawnExtensionComponent* PawnExtComp = UNLGPawnExtensionComponent::FindPawnExtensionComponent(Pawn))
	{
		if (const UNLGPawnData* PawnData = PawnExtComp->GetPawnData<UNLGPawnData>())
		{
			if (const UNLGInputConfig* InputConfig = PawnData->InputConfig)
			{
				const FNLGGameplayTags& GameplayTags = FNLGGameplayTags::Get();

				UNLGInputComponent* NLGIC = CastChecked<UNLGInputComponent>(PlayerInputComponent);
				NLGIC->AddInputMappings(InputConfig, Subsystem);

				NLGIC->BindNativeAction(InputConfig, GameplayTags.InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move,  false);
			}
		}
	}
}

void UNLGHeroComponent::Input_Move(const FInputActionValue& InputActionValue)
{
	APawn* Pawn = GetPawn<APawn>();
	AController* Controller = Pawn ? Pawn->GetController() : nullptr;

	if (Controller)
	{
		const FVector2D Value = InputActionValue.Get<FVector2D>();
		const FRotator MovementRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

		if (Value.X != 0.0f)
		{
			const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
			Pawn->AddMovementInput(MovementDirection, Value.X);
		}

		if (Value.Y != 0.0f)
		{
			const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
			Pawn->AddMovementInput(MovementDirection, Value.Y);
		}
	}
}
