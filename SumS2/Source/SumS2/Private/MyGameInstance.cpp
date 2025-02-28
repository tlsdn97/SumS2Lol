// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "MyStatComponent.h"
#include "Engine/DataTable.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> dataTble(TEXT("/Script/Engine.DataTable'/Game/Data/MyStatTable.MyStatTable'"));

	if (dataTble.Succeeded())
	{
		_statTable = dataTble.Object;
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	FString rowName = "Level_3";

	auto row = _statTable->FindRow<FMyStatData>(*rowName, TEXT(""));

	UE_LOG(LogTemp, Error, TEXT("Level : %d, hp : %d, ATK : %d"), row->level, row->hp, row->atk);
}
