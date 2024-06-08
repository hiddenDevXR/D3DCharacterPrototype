// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/ShotAttackAbility.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/D3DCharacterBase.h"

void UShotAttackAbility::OnActivateAbility_Implementation() {
	Super::OnActivateAbility_Implementation();

	ACharacter* Character = Cast<ACharacter>(GetOwningActor());

	if (Character)
	{
		Character->PlayAnimMontage(PrimaryAttackMontage);
	}
}

void UShotAttackAbility::OnStartAttack_Implementation()
{
	Super::OnStartAttack_Implementation();

	FRotator CameraRotation;
	FVector CameraLocation;

	APawn* Pawn = Cast<APawn>(GetOwningActor());

	if (!Pawn) return;

	Pawn->GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector EndLocation = CameraLocation + CameraRotation.Vector() * MaxPrimaryAttackDistance;


	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Pawn);
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, QueryParams);

	if (bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetName()));

		AActor* Actor = HitResult.GetActor();

		if (!Actor) return;

		UGameplayStatics::ApplyDamage(Actor, 100, Pawn->GetController(), Pawn, PrimaryAttackDamageTypeClass);
	}

	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UShotAttackAbility::EndAbilityCoolDown, CoolDownTime, false);
}

void UShotAttackAbility::EndAbilityCoolDown()
{
	AD3DCharacterBase* Character = Cast<AD3DCharacterBase>(GetOwningActor());
	Character->CharacterTags.RemoveTag(Character->AttackTag);
	if (!Character->HasCharacterTag(Character->AttackTag))
		UE_LOG(LogTemp, Warning, TEXT("I have NO tag"));

	EndAbility();
}
