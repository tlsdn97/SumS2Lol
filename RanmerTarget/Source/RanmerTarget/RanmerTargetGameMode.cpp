// Copyright Epic Games, Inc. All Rights Reserved.

#include "RanmerTargetGameMode.h"
#include "RanmerTargetCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARanmerTargetGameMode::ARanmerTargetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
