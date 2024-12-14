// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UTHUB_Blutility : ModuleRules
{
	public UTHUB_Blutility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
