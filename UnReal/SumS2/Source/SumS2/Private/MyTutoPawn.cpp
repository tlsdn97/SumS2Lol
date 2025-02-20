// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTutoPawn.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyTutoPawn::AMyTutoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = _mesh;

	// 생성자에서
	// sm에 해당 경로의 UStaticMesh, object를 갖고오는 방법
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm
	(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded())
	{
		_mesh->SetStaticMesh(sm.Object);
	}

	UE_LOG(LogTemp, Warning, TEXT("ConstVefer"));
}

// Called when the game starts or when spawned
void AMyTutoPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("Begin!!"));
}

// Called every frame
void AMyTutoPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Error, TEXT("DeltaTime : %f"), DeltaTime);

	// DeltaTime : 1번에 Update에 걸리는 시간

	if (GetAttachParentActor() == nullptr)
	{
		FVector curLocation = GetActorLocation();
		FVector destLocation = curLocation + FVector(0, 0, _moveSpeed) * DeltaTime;
		SetActorLocation(destLocation);

		FRotator rot = FRotator(0, 1, 0);
		AddActorLocalRotation(rot * _rotSpeed * DeltaTime);
		//SetActorRotation()
	}
	else
	{
		FVector parent = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation(); // worldLocation

		// 자전주기와 공전 주기 바꾸기
		
	}
	

	
	

}

// Called to bind functionality to input
void AMyTutoPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

