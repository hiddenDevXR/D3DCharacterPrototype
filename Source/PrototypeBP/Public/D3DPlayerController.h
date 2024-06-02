// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "D3DPlayerController.generated.h"


/**
 * 
 */

USTRUCT(BlueprintType)
struct FInputMapping
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input")
	TObjectPtr<class UInputMappingContext> InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input")
	int Priority = 0;
};

class UInputAction;

USTRUCT(BlueprintType)
struct FInputActions 
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputLook;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	//TObjectPtr<UInputAction> InputJump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputFire;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	//TObjectPtr<UInputAction> InputUse;
};


UCLASS()
class PROTOTYPEBP_API AD3DPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input")
	TArray<FInputMapping> InputMappingList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input")
	FInputActions InputActions;

	virtual void SetupInputComponent() override;

protected:

	void MoveInputAction(const struct FInputActionValue& InputActionValue);
	void LookInputAction(const struct FInputActionValue& InputActionValue);
	void FireInputAction();

	class AD3DCharacterBase* GetCharacter();
};
