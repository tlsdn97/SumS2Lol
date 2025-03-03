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
}

FMyStatData UMyGameInstance::GetStat_Level(int32 level)
{
	FString rowName = "Level_" + FString::FromInt(level);

	auto row = _statTable->FindRow<FMyStatData>(*rowName, TEXT(""));


	return *row;
}
