// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/PrimaryAbility.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/D3DCharacterBase.h"
#include "Gameplay/Interactable.h"

void UPrimaryAbility::OnActivateAbility_Implementation() {
	Super::OnActivateAbility_Implementation();

	ACharacter* Character = Cast<ACharacter>(GetOwningActor());

	if (Character)
	{
		Character->PlayAnimMontage(PrimaryInteractionMontage);
	}
}

void UPrimaryAbility::OnStartInteraction_Implementation()
{
	Super::OnStartInteraction_Implementation();

	FRotator CameraRotation;
	FVector CameraLocation;
	APawn* Pawn = Cast<APawn>(GetOwningActor());

	if (!Pawn) return;

	Pawn->GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector EndLocation = CameraLocation + CameraRotation.Vector() * MaxPrimaryInteractionDistance;


	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Pawn);
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, QueryParams);

	if (bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetName()));

		AInteractable* interactable = Cast<AInteractable>(HitResult.GetActor());

		if (interactable)
		{
			AD3DCharacterBase* Character = Cast<AD3DCharacterBase>(GetOwningActor());
			interactable->OnInteraction(Character);
		}
	}

	GetWorld()->GetTimerManager().SetTimer(InteractTimerHandle, this, &UPrimaryAbility::EndAbilityCoolDown, CoolDownTime, false);
}

void UPrimaryAbility::EndAbilityCoolDown()
{
	AD3DCharacterBase* Character = Cast<AD3DCharacterBase>(GetOwningActor());
	Character->CharacterTags.RemoveTag(Character->InteractionTag);
	if (!Character->HasCharacterTag(Character->InteractionTag))
		UE_LOG(LogTemp, Warning, TEXT("I have NO tag"));

	EndAbility();
}