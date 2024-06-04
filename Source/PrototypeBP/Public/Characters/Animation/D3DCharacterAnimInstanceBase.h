// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "D3DCharacterAnimInstanceBase.generated.h"


enum class ED3DDeathCause : uint8;

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UD3DCharacterAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
	

public:

	//virtual void NativeBeginPlay() override;
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AD3DCharacterBase* Character;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float Speed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float Direction = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Death")
	ED3DDeathCause DeathCause;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Death")
	bool isAlive = 0.0f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category = "Idle Wait")
	float IdleElapsedTime = 0.0f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category = "Idle Wait")
	bool IdleAnimStart = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Idle Wait")
	float IdleWaitTime = 15.0f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Idle Wait")
	int IdleWaitAnimation = 0;

	UFUNCTION(BlueprintCallable)
	bool IsAccelerating();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category = "Movement")
	bool bIsAccelerating = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category = "Movement")
	bool bIsOnAir = false;
		
};
