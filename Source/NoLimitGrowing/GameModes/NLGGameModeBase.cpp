// Fill out your copyright notice in the Description page of Project Settings.


#include "NLGGameModeBase.h"
#include "Player/NLGPlayerState.h"
#include "Player/NLGPlayerController.h"
#include "Character/NLGCharacter.h"

ANLGGameModeBase::ANLGGameModeBase(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)
{
	//GameStateClass = 
    PlayerControllerClass = ANLGPlayerController::StaticClass();
	PlayerStateClass = ANLGPlayerState::StaticClass();
	DefaultPawnClass = ANLGCharacter::StaticClass();
}
                                