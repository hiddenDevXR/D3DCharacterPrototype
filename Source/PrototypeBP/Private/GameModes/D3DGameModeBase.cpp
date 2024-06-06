// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/D3DGameModeBase.h"
#include "Controllers/D3DPlayerController.h"
#include "Characters/D3DCharacterBase.h"

AD3DGameModeBase::AD3DGameModeBase()
{
	PlayerControllerClass = AD3DPlayerController::StaticClass();
	DefaultPawnClass = AD3DCharacterBase::StaticClass();

}