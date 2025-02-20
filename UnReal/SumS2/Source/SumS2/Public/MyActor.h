// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

// 1. 메모리
// 2. 리플렉션(reflectio)
UCLASS() // UObject를 상속 받는 클래스
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

	//actor가 월드에서 존재하려면 transform
	// 눈에 보일려면
	// 1. mesh 가 있어야한다.
	// 색을 칠할려면 
	// 2. marterial이  있어야한다
	// 3. transform(4x4 행렬)

	

};
