// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestInteractable.generated.h"

UCLASS()
class PROTOTYPEBP_API ATestInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestInteractable();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Widget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* DefaultSceneComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
