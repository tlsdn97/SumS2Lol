// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UCLASS()
class SUMS2_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void PostInitializeComponents() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void ItemDrop(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const struct FHitResult& SweepResult);

private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;


	// UPROPERTY(VisibleAnywhere, Category = "Mesh")
	// UStaticMeshComponent* _mesh;
	// 
	// UPROPERTY(VisibleAnywhere, Category = "Collision")
	// UStaticMeshComponent* _collision;
};
