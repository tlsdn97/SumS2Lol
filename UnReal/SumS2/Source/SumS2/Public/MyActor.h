// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

// 1. �޸�
// 2. ���÷���(reflectio)
UCLASS() // UObject�� ��� �޴� Ŭ����
class SUMS2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//actor�� ���忡�� �����Ϸ��� transform
	// ���� ���Ϸ���
	// 1. mesh �� �־���Ѵ�.
	// ���� ĥ�ҷ��� 
	// 2. marterial��  �־���Ѵ�
	// 3. transform(4x4 ���)

	

};
