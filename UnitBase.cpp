// Fill out your copyright notice in the Description page of Project Settings.

#include "UnitBase.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnitBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AUnitBase::getUpdateRenderState()
{
	return updateRenderState;
}

void AUnitBase::setUpdateRenderState(bool state)
{
	updateRenderState = state;
}

bool AUnitBase::getCurrentRenderState()
{
	return currentRenderState;
}

void AUnitBase::setCurrentRenderState(bool state)
{
	currentRenderState = state;
}