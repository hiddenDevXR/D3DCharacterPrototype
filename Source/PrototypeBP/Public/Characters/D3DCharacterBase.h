// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "D3DCharacterBase.generated.h"


class UD3DCharacterAttributeComponent;

UENUM(BlueprintType)
enum class ED3DDeathCause : uint8
{
	None,
	Shoot,
	Explotion
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDie, ED3DDeathCause, Cause);

UCLASS()
class PROTOTYPEBP_API AD3DCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	

	// Sets default values for this character's properties
	AD3DCharacterBase();

	virtual void Fire();
	virtual void Jump() override;

	
	virtual void PrimaryInteraction();
	virtual void PrimaryAttack();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay")
	ED3DDeathCause DeathCause = ED3DDeathCause::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UD3DHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UD3DCharacterAttributeComponent* CharacterAttributesComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UD3DAbilityComponent> AbilityComponent;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	UAnimMontage* PrimaryInteractionMontage;



	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PrimaryInteraction")
	float MaxPrimaryInteractionDistance = 500;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	

	UPROPERTY(BlueprintAssignable, Category = "Gameplay")
	FOnDie OnDie;

	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ED3DDeathCause GetDeathCause() { return DeathCause; }

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool IsAlive() { return DeathCause == ED3DDeathCause::None; }

	//virtual void CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult) override;


	void Die(ED3DDeathCause Cause);

	UFUNCTION(BlueprintCallable)
	UD3DCharacterAttributeComponent* GetAttributes() const {
		return CharacterAttributesComponent;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	struct FGameplayTagContainer CharacterTags;

	UFUNCTION(BlueprintCallable, Category = "Tags")
	bool HasCharacterTag(FGameplayTag Tag) const;


	FGameplayTag AttackTag;
	FGameplayTag InteractionTag;

protected:

	UFUNCTION(BlueprintCallable)
	class AD3DPlayerController* GetPlayerController() const;

	
};
