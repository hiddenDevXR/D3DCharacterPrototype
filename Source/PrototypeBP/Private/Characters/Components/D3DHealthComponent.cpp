// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/D3DHealthComponent.h"
#include "Characters/D3DCharacterBase.h"
#include "Characters/Components/D3DCharacterAttributeComponent.h"

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

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UD3DHealthComponent::HandleAnyDamage);
}

void UD3DHealthComponent::HandleAnyDamage(AActor* DamagedActor, float damage, const UDamageType* DamageType, AController* InstidatedBy, AActor* DamageCauser) {
	UE_LOG(LogTemp, Warning, TEXT("Damage"));
	CharacterBase->GetAttributes()->Health.AddToBaseValue(-damage);
	
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

