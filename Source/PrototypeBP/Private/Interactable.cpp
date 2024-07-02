// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Widget->SetWidgetSpace(EWidgetSpace::Screen);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(100.0f);
	Sphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


let cells = [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0,
             0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0];
let on_Color;
let off_Color;
let y = 0;
let w = 10;
let length = 0;

function setup() {
  createCanvas(400, 800);
  on_Color = color(200, 0, 255);
  off_Color = color(4, 251, 241);
  length = cells.length;
}
//color(i*10, 100, 200)
function draw() {
  //background(30);
  
  for (let i = 0; i < cells.length; i++)
  {
    if(cells[i] == 1)
      fill(on_Color);
    else
      fill(off_Color);
    circle(i * w, y * w, w);
  }
  
  for (let i = 0; i < cells.length; i++)
  {
    let l_cell = cells[(i - 1 + length)%length];
    let c_cell = cells[i];
    let r_cell = cells[(i + 1 + length)%length];
    
    cells[i] = GetNextGeneration(l_cell, c_cell, r_cell);
  }
  y++;  
}

EUTkr9tM
Yapoos2024

function GetNextGeneration(l, c, r) {
  
  if(l == 0 && c == 0 && r == 0) return 0;
  if(l == 0 && c == 0 && r == 1) return 1;
  if(l == 0 && c == 1 && r == 0) return 1;
  if(l == 0 && c == 1 && r == 1) return 0;
  if(l == 1 && c == 0 && r == 0) return 1;
  if(l == 1 && c == 0 && r == 1) return 1;
  if(l == 1 && c == 1 && r == 0) return 0;
  if(l == 1 && c == 1 && r == 1) return 0;
}

