// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FMyInputMapping
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input System")
	TObjectPtr<class UInputMappingContext> InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input System")
	int Priority = 0;
};

class UInputAction;

USTRUCT(BlueprintType)
struct FMyInputActions
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputFire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputLook;
};

UCLASS()
class PROTOTYPEBP_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input System")
	TArray<FMyInputMapping> InputMappingList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input System")
	FMyInputActions InputActions;

	virtual void SetupInputComponent() override;
};
