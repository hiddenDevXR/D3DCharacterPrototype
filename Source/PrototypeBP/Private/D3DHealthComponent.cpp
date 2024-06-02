// Fill out your copyright notice in the Description page of Project Settings.


#include "D3DHealthComponent.h"
#include "D3DCharacterBase.h"

// Sets default values for this component's properties
UD3DHealthComponent::UD3DHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UD3DHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	if (!GetOwner()) return;

	CharacterBase = Cast<AD3DCharacterBase>(GetOwner());
}


// Called every frame
void UD3DHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (CharacterBase)
	{
		APlayerController* PC = Cast<APlayerController>(CharacterBase->GetController());

		if (PC && PC->WasInputKeyJustPressed("One"))
		{
			CharacterBase->Die(ED3DDeathCause::Shoot);
		}

		if (PC && PC->WasInputKeyJustPressed("Two"))
		{
			CharacterBase->Die(ED3DDeathCause::Explotion);
		}
	}
}

