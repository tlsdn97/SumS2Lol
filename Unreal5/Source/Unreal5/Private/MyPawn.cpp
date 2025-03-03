// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = _mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm
	(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	if (sm.Succeeded())
	{
		_mesh->SetStaticMesh(sm.Object);
	}


}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetAttachParentActor() == nullptr)
	{
		FVector curLocation = GetActorLocation();
		FVector destLocation = curLocation + FVector(_moveSpeed, 0, 0) * DeltaTime;
		SetActorLocation(destLocation);

		FRotator rot = FRotator(0, 1, 0);
		AddActorLocalRotation(rot * _rotSpeed * DeltaTime);
	}
	else
	{
		FVector parentV = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation();

		FRotator rot = UKismetMathLibrary::FindLookAtRotation(myV, parentV);
		SetActorRotation(rot);
	}

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputCompnent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputCompnent)
	{
		enhancedInputCompnent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
	}

}

void AMyPawn::Move(const FInputActionValue& value)
{

	FVector2D moveVector = value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		FVector forward = GetActorForwardVector() * moveVector.Y * 10.0f;
		FVector right = GetActorRightVector() * moveVector.X * 10.0f;
		FVector newLocation = GetActorLocation() + forward + right;
		SetActorLocation(newLocation);
	}
}

