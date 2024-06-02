// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "MyPlayerController.h"

void AMyPlayerController::SetupInputComponent() {
	
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	if (InputSubsystem) {

		InputSubsystem->ClearAllMappings();
	}
}