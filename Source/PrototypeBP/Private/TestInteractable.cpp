// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInteractable.h"
#include "UObject/Object.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ATestInteractable::ATestInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneComponent;

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	Widget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	Sphere->InitSphereRadius(5.0f);
	Sphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATestInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

