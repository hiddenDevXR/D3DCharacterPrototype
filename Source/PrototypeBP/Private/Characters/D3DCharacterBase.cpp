// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Components/D3DHealthComponent.h"
#include "Characters/D3DCharacterBase.h"
#include "Controllers/D3DPlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Gameplay/Interactable.h"
#include "Characters/Components/D3DCharacterAttributeComponent.h"

// Sets default values
AD3DCharacterBase::AD3DCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UD3DHealthComponent>(TEXT("Health"));
	CharacterAttributesComponent = CreateDefaultSubobject<UD3DCharacterAttributeComponent>(TEXT("Attributes"));
}

// Called when the game starts or when spawned
void AD3DCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD3DCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AD3DCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AD3DCharacterBase::Fire() 
{

}

void AD3DCharacterBase::Jump() {
	Super::Jump();
}

void AD3DCharacterBase::PrimaryInteraction() {

	PlayAnimMontage(PrimaryInteractionMontage);

	FRotator CameraRotation;
	FVector CameraLocation;

	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector EndLocation = CameraLocation + CameraRotation.Vector() * MaxPrimaryInteractionDistance;


	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, QueryParams);

	if (bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetName()));
		
		AInteractable* interactable = Cast<AInteractable>(HitResult.GetActor());

		if (interactable)
		{
			interactable->OnInteraction();
		}
	}
}

void AD3DCharacterBase::Die(ED3DDeathCause cause)
{
	if (DeathCause != ED3DDeathCause::None) return;

	DeathCause = cause;

	AD3DPlayerController* PC = GetPlayerController();

	if (PC)
	{
		PC->DisableInput(PC);
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	OnDie.Broadcast(cause);
}

AD3DPlayerController* AD3DCharacterBase::GetPlayerController() const
{
	return Cast<AD3DPlayerController>(GetController());
}

