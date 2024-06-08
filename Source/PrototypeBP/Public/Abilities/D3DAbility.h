// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "D3DAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, EditInLineNew, ClassGroup = (Abilities))
class PROTOTYPEBP_API UD3DAbility : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	FName AbilityName;

	virtual void ActivateAbility();
	virtual bool CanActivateAbility() const;

	virtual void EndAbility();

	UFUNCTION(BlueprintNativeEvent, Category = "Abilities")
	void OnActivateAbility();
	UFUNCTION(BlueprintNativeEvent, Category = "Abilities")
	void OnEndAbility();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	class UD3DAbilityComponent* GetOwningComponent() const;
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	AActor* GetOwningActor() const;

protected:

	bool bIsActivated = false;

};
