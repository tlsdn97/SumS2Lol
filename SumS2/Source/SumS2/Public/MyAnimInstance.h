// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
 // AMyActor : A...Actor
// UMyAnim : U... Actor�� �ƴ� �� => UObject

// void(void)
DECLARE_DELEGATE(AnimDelegateTest);

// 0. Delegate�� �������� �ݹ� �Լ� ������
// 1.�̱� ĳ��Ʈ Delegate
// 2.��Ƽ ĳ��Ʈ Delegate
// 3. Dynamic Delegate


// Dynamic Delegate�� UFUNCTION �� ��������

// �̱۰Խ�Ʈ Delegate
// int(int)
DECLARE_DELEGATE_RetVal_TwoParams(int32, AnimDelegateTest2, int32, int32);

// ��Ƽĳ��Ʈ ���̳��� Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimDelegateTest3);

// Delegate�� �Լ��� �Ѱܼ� ���������� ���߿� �(���� Ÿ���� �𸣴� ����) ��ü�� ȣ���Ҽ� �ְ� ���ִ� ���

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

