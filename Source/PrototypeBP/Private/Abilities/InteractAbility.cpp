// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/InteractAbility.h"

void UInteractAbility::ActivateAbility()
{
	Super::ActivateAbility();

	if (InteractDelay > 0.0f) {
		GetWorld()->GetTimerManager().SetTimer(InteractTimerHandle, this, &UInteractAbility::OnStartInteraction, InteractDelay, false);
	}
}

void UInteractAbility::OnStartInteraction_Implementation()
{
}
