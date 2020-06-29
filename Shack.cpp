// Fill out your copyright notice in the Description page of Project Settings.

#include "Shack.h"

// Sets default values
AShack::AShack()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShack::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

