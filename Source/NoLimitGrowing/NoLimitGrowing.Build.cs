// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NoLimitGrowing : ModuleRules
{
	public NoLimitGrowing(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(
			new string[]
			{
				"NoLimitGrowing",
			});
	
		PublicDependencyModuleNames.AddRange(
			new string[] { 
				"Core", 
				"CoreUObject",
				"Engine",
				"InputCore",
				"ModularGameplay",
				"GameplayTags",
				"CommonLoadingScreen",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"EnhancedInput",
                "CommonGame",
                "CommonUser",
            });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
