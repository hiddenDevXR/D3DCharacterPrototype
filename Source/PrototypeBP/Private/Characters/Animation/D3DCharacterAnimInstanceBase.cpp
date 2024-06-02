// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Animation/D3DCharacterAnimInstanceBase.h"
#include "KismetAnimationLibrary.h"
#include "D3DCharacterBase.h"

void UD3DCharacterAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();


	Character = Cast<AD3DCharacterBase>(GetOwningActor());

}

void UD3DCharacterAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!Character) return;

	Speed = Character->GetVelocity().Size();
	Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
	DeathCause = Character->GetDeathCause();
	isAlive = Character->IsAlive();
	


}