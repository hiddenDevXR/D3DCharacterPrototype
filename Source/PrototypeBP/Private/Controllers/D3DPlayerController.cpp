// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/D3DPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/D3DCharacterBase.h"

void AD3DPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();

	if (InputSubsystem)
	{
		InputSubsystem->ClearAllMappings();

		for (const FInputMapping& InputMapping : InputMappingList)
		{
			InputSubsystem->AddMappingContext(InputMapping.InputMapping, InputMapping.Priority);
		}

		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
		EnhancedInputComponent->BindAction(InputActions.InputMove, ETriggerEvent::Triggered, this, &AD3DPlayerController::MoveInputAction);
		EnhancedInputComponent->BindAction(InputActions.InputLook, ETriggerEvent::Triggered, this, &AD3DPlayerController::LookInputAction);
		EnhancedInputComponent->BindAction(InputActions.InputFire, ETriggerEvent::Triggered, this, &AD3DPlayerController::FireInputAction);
		EnhancedInputComponent->BindAction(InputActions.InputJump, ETriggerEvent::Triggered, this, &AD3DPlayerController::JumpInputAction);
		EnhancedInputComponent->BindAction(InputActions.InputPrimaryInteraction, ETriggerEvent::Triggered, this, &AD3DPlayerController::PrimaryInteractionInputAction);
	}
}


void AD3DPlayerController::MoveInputAction(const FInputActionValue& InputActionValue)
{
	const FVector2D value = InputActionValue.Get<FVector2D>();
	if (ensureMsgf(GetPawn(), TEXT("Player Controller could not posses any pawn")))
	{
		FRotator LookRotation = GetControlRotation();
		//LookRotation.Pitch = 0.0f;
		FRotator MoveRotation(0.0f, LookRotation.Yaw, 0.0f);
		FVector RightVector = FRotationMatrix(MoveRotation).GetScaledAxis(EAxis::Y);
		GetPawn()->AddMovementInput(RightVector, value.X);

		FVector ForwardVector = LookRotation.Vector();
		GetPawn()->AddMovementInput(ForwardVector, value.Y);
	}
}

void AD3DPlayerController::LookInputAction(const FInputActionValue& InputActionValue)
{
	const FVector2D value = InputActionValue.Get<FVector2D>();
	AddYawInput(value.X);
	AddPitchInput(value.Y);
}

void AD3DPlayerController::PrimaryInteractionInputAction()
{
	AD3DCharacterBase* PlayerCharacter = GetCharacter();
	if (PlayerCharacter)
	{
		PlayerCharacter->PrimaryInteraction();
	}
}

void AD3DPlayerController::FireInputAction() 
{
	AD3DCharacterBase* PlayerCharacter = GetCharacter();
	if (PlayerCharacter)
	{
		PlayerCharacter->Fire();
	}
}

void AD3DPlayerController::JumpInputAction()
{
	AD3DCharacterBase* PlayerCharacter = GetCharacter();
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}
}
                                        
AD3DCharacterBase* AD3DPlayerController::GetCharacter()
{
	return Cast<AD3DCharacterBase>(GetPawn());
}