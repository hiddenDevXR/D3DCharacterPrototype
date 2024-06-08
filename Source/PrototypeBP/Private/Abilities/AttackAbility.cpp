// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AttackAbility.h"

void UAttackAbility::ActivateAbility()
{
	Super::ActivateAbility();

	if (AttackDelay > 0.0f) {
		GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UAttackAbility::OnStartAttack, AttackDelay, false);
	}
}

void UAttackAbility::OnStartAttack_Implementation()
{
}
