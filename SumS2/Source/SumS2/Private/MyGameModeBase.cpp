// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMyPawn> pawn(TEXT("/Script/Engine.Blueprint'/Game/BluePrint/BP_MyPawn.BP_MyPawn_C'"));

	if (pawn.Succeeded())
	{
		DefaultPawnClass = AMyPawn::StaticClass();
	}
}
