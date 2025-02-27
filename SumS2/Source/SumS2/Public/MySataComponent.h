// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MySataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUMS2_API UMySataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMySataComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// int32 GetCurHp() { return _curHp; }
	// int32 GetMaxHp() { return _maxHp; }
	// int32 GetAtk() { return _atk; }
	// 
	// int32 AddCurHp(float amount);

private:
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "stat", meta = (AllowPrivateAccess = "true"))
	// uint32 _curHp;
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "stat", meta = (AllowPrivateAccess = "true"))
	// uint32 _maxHp;
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "stat", meta = (AllowPrivateAccess = "true"))
	// uint32 _atk;
};
