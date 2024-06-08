// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/InteractAbility.h"
#include "PrimaryAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UPrimaryAbility : public UInteractAbility
{
	GENERATED_BODY()
	
public:

	virtual void OnActivateAbility_Implementation() override;
	virtual void OnStartInteraction_Implementation() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	UAnimMontage* PrimaryInteractionMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	float MaxPrimaryInteractionDistance = 1000;

	void EndAbilityCoolDown();
};
