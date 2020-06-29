// Fill out your copyright notice in the Description page of Project Settings.

#include "Placeholder.h"

// Sets default values
APlaceholder::APlaceholder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlaceholder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlaceholder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlaceholder::setType(int _type)
{
	type = _type;
}

int APlaceholder::getType()
{
	return type;
}

