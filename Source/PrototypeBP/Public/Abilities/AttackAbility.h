// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/D3DAbility.h"
#include "AttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UAttackAbility : public UD3DAbility
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	float AttackDelay = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	float CoolDownTime = 0.0f;

public:
	virtual void ActivateAbility() override;
	UFUNCTION(BlueprintNativeEvent = "Abilities")
	void OnStartAttack();
	void OnEndAttack();

protected:
	FTimerHandle AttackTimerHandle;
};
