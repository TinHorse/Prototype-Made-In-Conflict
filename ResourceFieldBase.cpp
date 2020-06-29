// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceFieldBase.h"
#include "GameFramework/Pawn.h"
#include "Engine.h"
#include "ResourceObject.h"

// Sets default values
AResourceFieldBase::AResourceFieldBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AResourceFieldBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResourceFieldBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AResourceFieldBase::makeResourceObjects()
{
	FActorSpawnParameters objectSpawnParams;
	objectSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	objectSpawnParams.bNoFail = true;
	objectSpawnParams.Owner = this;

	if (!resourceClass2) {
		for (int i = 0; i < NumResourceObjects; i++) {

			FVector location = { FMath::FRandRange(-boundsX,boundsX), FMath::FRandRange(-boundsY,boundsY),0 };
			FVector rot = { FMath::Sin(FMath::FRand() * 2.f),FMath::Cos(FMath::FRand() * 2.f),0 };
			FVector rotation{ rot.X,rot.Y,0 };

			FTransform transform;
			transform.SetRotation(rotation.ToOrientationQuat());
			transform.SetLocation(location + GetActorLocation());

			AResourceObject* resObject = GetWorld()->SpawnActor<AResourceObject>(resourceClass, transform, objectSpawnParams);
			resourceObjects.Add(resObject);
		}
	}
	else {
		for (int i = 0; i < NumResourceObjects; i++) {

			FVector location = { FMath::FRandRange(-boundsX,boundsX), FMath::FRandRange(-boundsY,boundsY),0 };
			FVector rot = { FMath::Sin(FMath::FRand() * 2.f),FMath::Cos(FMath::FRand() * 2.f),0 };
			FVector rotation{ rot.X,rot.Y,0 };

			FTransform transform;
			transform.SetRotation(rotation.ToOrientationQuat());
			transform.SetLocation(location + GetActorLocation());

			TSubclassOf<AResourceObject> resource_class;
			float ran = FMath::FRandRange(0, 4);
			if (ran < 1) {
				resource_class = resourceClass;
			}
			else if (ran < 2) {
				resource_class = resourceClass2;
			}
			else if (ran < 3) {
				resource_class = resourceClass3;
			}
			else {
				resource_class = resourceClass4;
			}

			AResourceObject* resObject = GetWorld()->SpawnActor<AResourceObject>(resource_class, transform, objectSpawnParams);
			resourceObjects.Add(resObject);
		}
	}
}

void AResourceFieldBase::setBoundsX(float targetBounds)
{
	boundsX = targetBounds;
}

void AResourceFieldBase::setBoundsY(float targetBounds)
{
	boundsY = targetBounds;
}

void AResourceFieldBase::setNumObjects(float targetNumObjects)
{
	NumResourceObjects = targetNumObjects;
}

void AResourceFieldBase::scaleObjects()
{
	for (auto resObject : resourceObjects) {
		float scaleXY = 1.f + FMath::FRand() * 1.5;
		float scaleZ = 1.f + FMath::FRand() * 2;
		//float scaleZ = FMath::FRand() / 4;
		FVector scale = { scaleXY, scaleXY, scaleZ };
		resObject->SetActorScale3D(scale);
	}
}

