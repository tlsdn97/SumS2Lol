// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SUMS2_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

	// 언리얼의 싱글턴

public:

	UMyGameInstance();

	virtual void Init() override;

private:
	UPROPERTY()
		class UDataTable* _statTable;
	
};
