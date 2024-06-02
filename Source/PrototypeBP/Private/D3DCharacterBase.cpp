// Fill out your copyright notice in the Description page of Project Settings.

#include "D3DHealthComponent.h"
#include "D3DCharacterBase.h"
#include "D3DPlayerController.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AD3DCharacterBase::AD3DCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UD3DHealthComponent>(TEXT("Health"));
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

AD3DPlayerController* AD3DCharacterBase::GetPlayerController()
{
	return Cast<AD3DPlayerController>(GetController());
}

