// Fill out your copyright notice in the Description page of Project Settings.


#include "D3DGameModeBase.h"
#include "D3DPlayerController.h"
#include "D3DCharacterBase.h"

AD3DGameModeBase::AD3DGameModeBase()
{
	PlayerControllerClass = AD3DPlayerController::StaticClass();
	DefaultPawnClass = AD3DCharacterBase::StaticClass();

}