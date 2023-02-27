// Fill out your copyright notice in the Description page of Project Settings.


#include "NLGInputComponent.h"
#include "Player/NLGLocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "Settings/NLGSettingsLocal.h"


UNLGInputComponent::UNLGInputComponent(const FObjectInitializer& ObjectInitializer)
{

}

void UNLGInputComponent::AddInputMappings(const UNLGInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	UNLGLocalPlayer* LocalPlayer = InputSubsystem->GetLocalPlayer<UNLGLocalPlayer>();
	check(LocalPlayer);

	// Add any registered input mappings from the settings!
	if (UNLGSettingsLocal* LocalSettings = UNLGSettingsLocal::Get())
	{
		// Tell enhanced input about any custom keymappings that the player may have customized
		for (const TPair<FName, FKey>& Pair : LocalSettings->GetCustomPlayerInputConfig())
		{
			if (Pair.Key != NAME_None && Pair.Value.IsValid())
			{
				InputSubsystem->AddPlayerMappedKey(Pair.Key, Pair.Value);
			}
		}
	}
}
