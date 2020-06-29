// Fill out your copyright notice in the Description page of Project Settings.

#include "HumanPawn.h"

// Sets default values
AHumanPawn::AHumanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHumanPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

