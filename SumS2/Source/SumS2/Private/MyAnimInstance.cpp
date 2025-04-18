// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "MyCharacter.h"

#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	auto pawn = TryGetPawnOwner();
	AMyCharacter* character = Cast<AMyCharacter>(pawn); // dynamicCast

	// Movement가 Pawn에도 있다.
	// _ <
	// 이름이 범용적이라 겹치면 안될거 같아서 

	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();
		_isFalling = character->GetMovementComponent()->IsFalling();
		_vertical = character->My_Vertical();
		_horizontal = character->My_Horizontal();
	}
}

void UMyAnimInstance::PlayAnimMontage()
{
	if (_animMontage == nullptr)
		return;

	if (!Montage_IsPlaying(_animMontage))
	{
		//Attack Delegate 실행
		//_attackStart.Execute();
		//_attackStart2.Execute(1,2);
		//_attackStart3.Broadcast(); // 멀티캐스트

		Montage_Play(_animMontage);
	}
}

void UMyAnimInstance::AnimNotify_Attack_Hit()
{
	// 나를 갖고 있는 캐릭터의 AttackHit 
	_hitEvent.Broadcast();
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	// Section1,Section2,Section3 설정
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));
	Montage_JumpToSection(sectionName, _animMontage);
}
