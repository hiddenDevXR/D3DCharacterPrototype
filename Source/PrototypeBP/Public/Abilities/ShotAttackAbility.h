// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/AttackAbility.h"
#include "ShotAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UShotAttackAbility : public UAttackAbility
{
	GENERATED_BODY()
	
public:

	virtual void OnActivateAbility_Implementation() override;
	virtual void OnStartAttack_Implementation() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	UAnimMontage* PrimaryAttackMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	float PrimaryAttackDamage = 10;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	float MaxPrimaryAttackDistance = 100;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	TSubclassOf<UDamageType> PrimaryAttackDamageTypeClass;

	void EndAbilityCoolDown();
};
