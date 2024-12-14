// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_BlutilityGameMode.h"
#include "UTHUB_BlutilityCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_BlutilityGameMode::AUTHUB_BlutilityGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
