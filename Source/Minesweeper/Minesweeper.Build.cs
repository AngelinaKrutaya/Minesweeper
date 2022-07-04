// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Minesweeper : ModuleRules
{
	public Minesweeper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Json", "WebSockets", "SlateCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "WebSockets", "InputCore","Slate","SlateCore"});
	}
}
