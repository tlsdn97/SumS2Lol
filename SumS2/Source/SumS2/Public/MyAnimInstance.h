// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
 // AMyActor : A...Actor
// UMyAnim : U... Actor가 아닌 것 => UObject

// void(void)
DECLARE_DELEGATE(AnimDelegateTest);

// 0. Delegate란 무엇인지 콜백 함수 재조자
// 1.싱글 캐스트 Delegate
// 2.멀티 캐스트 Delegate
// 3. Dynamic Delegate


// Dynamic Delegate는 UFUNCTION 꼭 붙혀야함

// 싱글게스트 Delegate
// int(int)
DECLARE_DELEGATE_RetVal_TwoParams(int32, AnimDelegateTest2, int32, int32);

// 멀티캐스트 다이나믹 Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimDelegateTest3);

// Delegate란 함수를 넘겨서 간접적으로 나중에 어떤(서로 타입을 모르는 상태) 객체가 호출할수 있게 해주는 방법

DECLARE_MULTICAST_DELEGATE(AttackHitEvent);

UCLASS()
class SUMS2_API UMyAnimInstance : public UAnimInstance
{
		GENERATED_BODY()

public:
	UMyAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds);

	UFUNCTION()
	void PlayAnimMontage();

	UFUNCTION()
	void AnimNotify_Attack_Hit();

	void JumpToSection(int32 sectionIndex);

	AnimDelegateTest _attackStart;
	AnimDelegateTest2 _attackStart2;

	AttackHitEvent _hitEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	FAnimDelegateTest3 _attackStart3;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "pawn", meta = (AllowPrivateAccess = "true"))
	float _speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "pawn", meta = (AllowPrivateAccess = "true"))
	bool _isFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontate", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* _animMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontate", meta = (AllowPrivateAccess = "true"))
	float _vertical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontate", meta = (AllowPrivateAccess = "true"))
	float _horizontal;
};

