// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/D3DAbility.h"
#include "Abilities/D3DAbilityComponent.h"

void UD3DAbility::ActivateAbility()
{
	if (bIsActivated) {
		return;
	}

	bIsActivated = true;
	OnActivateAbility();
}

void UD3DAbility::EndAbility()
{
	ensureAlways(bIsActivated);

	OnEndAbility();
	bIsActivated = false;
}

UD3DAbilityComponent* UD3DAbility::GetOwningComponent() const
{
	return CastChecked<UD3DAbilityComponent>(GetOuter());
}

AActor* UD3DAbility::GetOwningActor() const
{
	return GetOwningComponent()->GetOwner();
}

void UD3DAbility::OnActivateAbility_Implementation()
{
}

void UD3DAbility::OnEndAbility_Implementation()
{
}

bool UD3DAbility::CanActivateAbility() const {
	return !bIsActivated;
}

