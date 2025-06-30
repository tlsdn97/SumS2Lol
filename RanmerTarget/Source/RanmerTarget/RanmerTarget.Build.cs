// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RanmerTarget : ModuleRules
{
	public RanmerTarget(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
