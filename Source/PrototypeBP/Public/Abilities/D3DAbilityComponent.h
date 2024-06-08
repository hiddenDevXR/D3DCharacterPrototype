// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "D3DAbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOTYPEBP_API UD3DAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UD3DAbilityComponent();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Abilities")
	TArray<class UD3DAbility*> Abilities;

public:	

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void AddAbility(TSubclassOf<class UD3DAbility> AbilityClass);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool TryActiveAbilityByName(FName AbilityName);
};
