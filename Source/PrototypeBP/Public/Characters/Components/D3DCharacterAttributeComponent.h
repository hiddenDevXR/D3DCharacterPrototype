// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "D3DCharacterAttributeComponent.generated.h"


DECLARE_DYNAMIC_DELEGATE_TwoParams(FHealthChangeSignature, float, CurrentValue, float, PrevValue);

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UD3DCharacterAttributeComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	FHealthChangeSignature OnHealthChanged;

	void SetHealth(float NewHealth);
	float GetHealth();
	void AddHealth(float Delta);

	void SetMaxHealth(float NewHealth);
	float GetMaxHealth();
	void AddMaxHealth(float Delta);

protected:

	float health = 100;

};
