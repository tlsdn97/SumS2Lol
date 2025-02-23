// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

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

	UE_LOG(LogTemp, Warning, TEXT("Constructor!!!"));
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Begin!!"));
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// �Է�
	// - Action : �ݹ��Լ��� ����(�ñ״��ĸ� ���缭)
	// - MappingContext

	// Pawn : _moveAction
	// Controller : _mappingContext
	// Pawn�� Controller�� ���� => Gamemodebase

	// => Pawn�� GameModeBase�� ������� Controller�� '����'(Posses)�Ǽ� ������ �� �ִ�.

	UEnhancedInputComponent* enhancedInputCompnent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputCompnent)
	{
		enhancedInputCompnent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
	}
}

void AMyPawn::Temp()
{
	UE_LOG(LogTemp, Error, TEXT("Temp Func is Called"));
}

void AMyPawn::Move(const FInputActionValue& value)
{
	FVector2D moveVector = value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		if (moveVector.Length() > 0.01f)
		{
			UE_LOG(LogTemp, Error, TEXT("Y : %f"), moveVector.Y);
			UE_LOG(LogTemp, Error, TEXT("X : %f"), moveVector.X);

			FVector forWard = GetActorForwardVector() * moveVector.Y * 10.0f;
			FVector right = GetActorRightVector() * moveVector.X * 10.0f;
			FVector newLocation = GetActorLocation() + forWard + right;
			SetActorLocation(newLocation);
		}
		//AddMovementInput(GetActorForwardVector(), moveVector.Y * 100.0f);
		//AddMovementInput(GetActorRightVector(), moveVector.X * 100.0f);
	}
}

