// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// FRotator rot = FRotator(0, 1, 0);
	// AddActorWorldRotation(rot * _rotSpeed * DeltaTime);

	if (GetAttachParentActor() == nullptr)
	{
		FVector curLocation = GetActorLocation();
		FVector destLocation = curLocation + FVector(_moveSpeed, 0, 0) * DeltaTime;
		SetActorLocation(destLocation);

		FRotator rot = FRotator(0, 1, 0);
		AddActorWorldRotation(rot * _rotSpeed * DeltaTime);

	}
	else
	{
		FVector parentV = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation();

		FRotator rot = UKismetMathLibrary::FindLookAtRotation(myV, parentV);
		SetActorRotation(rot);
	}
}

