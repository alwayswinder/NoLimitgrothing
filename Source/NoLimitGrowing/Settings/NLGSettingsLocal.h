// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "UObject/UObjectGlobals.h"
#include "GameFramework/GameUserSettings.h"

#include "NLGSettingsLocal.generated.h"


UCLASS()
class UNLGSettingsLocal : public UGameUserSettings
{
	GENERATED_BODY()

public:

	UNLGSettingsLocal();

	static UNLGSettingsLocal* Get();

	//~UGameUserSettings interface
	virtual void SetToDefaults() override;
	//~End of UGameUserSettings interface

	const TMap<FName, FKey>& GetCustomPlayerInputConfig() const { return CustomKeyboardConfig; }

private:
	UPROPERTY(Config)
	TMap<FName, FKey> CustomKeyboardConfig;
};