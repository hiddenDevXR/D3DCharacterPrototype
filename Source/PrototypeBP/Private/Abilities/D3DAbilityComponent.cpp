// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/D3DAbilityComponent.h"
#include "Abilities/D3DAbility.h"

// Sets default values for this component's properties
UD3DAbilityComponent::UD3DAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UD3DAbilityComponent::AddAbility(TSubclassOf<UD3DAbility> AbilityClass)
{
	UD3DAbility* NewAbility = NewObject<UD3DAbility>(this, AbilityClass);
	
	if (ensure(NewAbility))
	{
		Abilities.Add(NewAbility);
	}
}

bool UD3DAbilityComponent::TryActiveAbilityByName(FName AbilityName)
{
	for (auto Ability : Abilities)
	{
		if (Ability && Ability->AbilityName == AbilityName)
		{
			if (Ability->CanActivateAbility())
			{
				Ability->ActivateAbility();
				return true;
			}
		}
	}

	return false;
}
