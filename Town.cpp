// Fill out your copyright notice in the Description page of Project Settings.
#include "Town.h"
#include "Components/StaticMeshComponent.h"
#include "Gate.h"
#include "Shack.h"
#include "Placeholder.h"
#include "Manufacture.h"
#include "Plantation.h"
#include "Forge.h"
#include "Papermill.h"
#include "Lightworks.h"
#include "TitanExtractor.h"
#include "Inventory.h"
#include "MarketInventory.h"
#include "Warehouse.h"
#include "ResourceFieldBase.h"

// Sets default values
ATown::ATown()
{
	marketInventory = CreateDefaultSubobject<UMarketInventory>("storage");

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	faction = EFactionEnum::Loyalists;


	// set spawn parameters for buildings
	buildingSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	buildingSpawnParameters.bNoFail = true;
	buildingSpawnParameters.Owner = this;
	

	spawnIndex = 0;
	numProductions = 0;
	numWarehouses = 0;

	// set array of spawnTransforms (positions and rotations of buildings)
	int total_layer_num = 0;
	int num_transforms = 15;
	int num_layers = 3;
	total_layer_num += num_layers;
	int layer_distance = 150;

	// make shack layers
	for (int i = 1; i < num_layers + 1; i++) {
		FTransform transform;
		float distance = 30;

		for (int j = 0; j < num_transforms; j++) {
			if ((j % (num_transforms / 3)) != 0) {
				float value = (((2 * PI) / num_transforms)*j);

				FVector location{ FMath::FRand() * 3 + float(i) * distance * FMath::Sin(value) + layer_distance * FMath::Sin(value), FMath::FRand() * 3 + float(i) * distance * FMath::Cos(value) + layer_distance * FMath::Cos(value),0 };
				transform.SetLocation(location);

				FVector rot = { FMath::Sin(value * FMath::FRand() * 2.f),FMath::Cos(value * FMath::FRand() * 2.f),0 };
				FVector rotation{ rot.X,rot.Y,0 };
				transform.SetRotation(rotation.ToOrientationQuat());

				FVector Scalar{ 1.3f-(i*0.05f),1.3f - (i*0.05f),FMath::FRand() / 4 };
				transform.SetScale3D(Scalar);

				shackSpawnTransform.Add(transform);
			}
		}
		num_transforms += i*4;
		layer_distance += distance;
	}

	num_transforms = 15;
	num_layers = 2;
	total_layer_num += num_layers;

	// make building layer 1
	for (int i = 1; i < num_layers + 1; i++) {
		FTransform transform;
		float distance = 270;

		for (int j = 0; j < num_transforms; j++) {
			if ((j % (num_transforms / 3)) != 0) {
				float value = (((2 * PI) / num_transforms)*j);

				FVector location{ float(i) * distance * FMath::Sin(value) + layer_distance * FMath::Sin(value), float(i) * distance * FMath::Cos(value) + layer_distance * FMath::Cos(value),0 };
				transform.SetLocation(location);

				FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
				FVector rotation{ rot.X,rot.Y,0 };
				transform.SetRotation(rotation.ToOrientationQuat());

				FVector Scalar{ float(i / 3) + 1,float(i / 3) + 1,0.2 };
				transform.SetScale3D(Scalar);
				buildingSpawnTransforms.Add(transform);
			}
		}
		num_transforms += 6;
	}
}

// Called when the game starts or when spawned
void ATown::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATown::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATown::setFaction(TEnumAsByte<EFactionEnum> value)
{
	faction = value;
}

TEnumAsByte<EFactionEnum> ATown::getFaction()
{
	return faction;
}

TEnumAsByte<ETownNames> ATown::getName()
{
	return town_name;
}


void ATown::setGatesAndPlaceholders()
{
	// Gates
	/*
	float distance = 340;
	for (int j = 1; j <= 3; j++) {
		float value = (((2 * PI) / 3) * j);
		FTransform anchor_transform;
		FVector location{ distance * FMath::Sin(value), distance * FMath::Cos(value),0 };
		anchor_transform.SetLocation(location + GetActorLocation());

		FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
		FVector rotation{ rot.X,rot.Y,0 };
		anchor_transform.SetRotation(rotation.ToOrientationQuat());

		AGate* anchor = GetWorld()->SpawnActor<AGate>(gateClass, anchor_transform, buildingSpawnParameters);
		gates.Add(anchor);
	}
	*/

	// Placeholders
	for (int i = 0; i < buildingSpawnTransforms.Num(); i++) {
		buildingSpawnTransforms[numProductions].SetLocation(buildingSpawnTransforms[numProductions].GetLocation() + GetActorLocation());

		buildingSpawnTransforms[numProductions].SetRotation(buildingSpawnTransforms[numProductions].GetRotation());
		APlaceholder* placeholder = GetWorld()->SpawnActor<APlaceholder>(placeholderClass, buildingSpawnTransforms[numProductions], buildingSpawnParameters);
		placeholder->setType(1);
		placeholders.Add(placeholder);

		numProductions++;
	}
	numProductions = 0;

	buildingSpawnTransforms.Empty();

	// make Resource Fields
	TArray<FVector> previous_locations; // stores locations of resource fields to stop them from spawning directly next to each other

	// Tree Resource Fields
	for (int j = 1; j <= numTreeResourceFields; j++) {
		float value = FMath::FRandRange(0,(2 * PI));
		float distance = FMath::FRandRange(1000, 2300);

		FVector location{ distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };

		// previous resource fields location check
		for (int i = 0; i < previous_locations.Num(); i++) {
			while (location.Dist(previous_locations[i], location) < 500) {
				distance *= 1.1;
				location = { distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };
				UE_LOG(LogTemp, Warning, TEXT("moving away, %f"), distance);
			}
		}
		previous_locations.Add(location);

		FVector rot = { FMath::Sin(FMath::FRand() * 2.f),FMath::Cos(FMath::FRand() * 2.f),0 };
		FVector rotation{ rot.X,rot.Y,0 };

		FTransform transform;
		transform.SetRotation(rotation.ToOrientationQuat());
		transform.SetLocation(location + GetActorLocation());

		AResourceFieldBase* field = GetWorld()->SpawnActor<AResourceFieldBase>(treeFieldClass, transform, buildingSpawnParameters);

		// placeholders
		distance = 250;
		for (int i = 1; i <= 3; i++) {
			float value = (((2 * PI) / 3) * i);
			FTransform transform;
			FVector placeholder_location{ distance * FMath::Sin(value), distance * FMath::Cos(value),0 };
			transform.SetLocation(placeholder_location + location + GetActorLocation());

			FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
			FVector rotation{ rot.X,rot.Y,0 };
			transform.SetRotation(rotation.ToOrientationQuat());

			APlaceholder* placeholder = GetWorld()->SpawnActor<APlaceholder>(placeholderClass, transform, buildingSpawnParameters);
			placeholder->setType(1);
			placeholders.Add(placeholder);

			numProductions++;
		}

	}

	// Titan Resource Fields
	for (int j = 1; j <= numTitanResourceFields; j++) {
		float value = FMath::FRandRange(0, (2 * PI));
		float distance = FMath::FRandRange(1200, 1800);

		FVector location{ distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };

		// previous resource fields location check
		for (int i = 0; i < previous_locations.Num(); i++) {
			while (location.Dist(previous_locations[i], location) < 500) {
				distance *= 1.1;
				location = { distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };
				UE_LOG(LogTemp, Warning, TEXT("moving away, %f"), distance);
			}
		}
		previous_locations.Add(location);

		FVector rot = { FMath::Sin(FMath::FRand() * 2.f),FMath::Cos(FMath::FRand() * 2.f),0 };
		FVector rotation{ rot.X,rot.Y,0 };

		FTransform transform;
		transform.SetRotation(rotation.ToOrientationQuat());
		transform.SetLocation(location + GetActorLocation());

		AResourceFieldBase* field = GetWorld()->SpawnActor<AResourceFieldBase>(titanFieldClass, transform, buildingSpawnParameters);

		// placeholders
		distance = 200;
		for (int i = 1; i <= 1; i++) {
			float value = FMath::FRandRange(0, 2*PI);
			FTransform transform;
			FVector placeholder_location{ distance * FMath::Sin(value), distance * FMath::Cos(value),0 };
			transform.SetLocation(placeholder_location + location + GetActorLocation());

			FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
			FVector rotation{ rot.X,rot.Y,0 };
			transform.SetRotation(rotation.ToOrientationQuat());

			APlaceholder* placeholder = GetWorld()->SpawnActor<APlaceholder>(placeholderClass, transform, buildingSpawnParameters);
			placeholder->setType(1);
			placeholders.Add(placeholder);

			numProductions++;
		}
	}

	// Light Resource Fields
	for (int j = 1; j <= numLightResourceFields; j++) {
		float value = FMath::FRandRange(0, (2 * PI));
		float distance = FMath::FRandRange(1200, 1800);

		FVector location{ distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };

		// previous resource fields location check
		for (int i = 0; i < previous_locations.Num(); i++) {
			UE_LOG(LogTemp, Warning, TEXT("previous locations num %d"), previous_locations.Num());
			while (location.Dist(previous_locations[i], location) < 500) {
				distance *= 1.1;
				location = { distance * FMath::Sin(value) + FMath::Sin(value), distance * FMath::Cos(value) + FMath::Cos(value),0 };
				UE_LOG(LogTemp, Warning, TEXT("moving away, %f"), distance);
			}
		}
		previous_locations.Add(location);

		FVector rot = { FMath::Sin(FMath::FRand() * 2.f),FMath::Cos(FMath::FRand() * 2.f),0 };
		FVector rotation{ rot.X,rot.Y,0 };

		FTransform transform;
		transform.SetRotation(rotation.ToOrientationQuat());
		transform.SetLocation(location + GetActorLocation());

		AResourceFieldBase* field = GetWorld()->SpawnActor<AResourceFieldBase>(lightFieldClass, transform, buildingSpawnParameters);

		// placeholders
		distance = 250;
		float randAngle = FMath::FRandRange(0,PI);
		for (int i = 1; i <= 2; i++) {
			float value = (PI * i) + randAngle;
			FTransform transform;
			FVector placeholder_location{ distance * FMath::Sin(value), distance * FMath::Cos(value),0 };
			transform.SetLocation(placeholder_location + location + GetActorLocation());

			FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
			FVector rotation{ rot.X,rot.Y,0 };
			transform.SetRotation(rotation.ToOrientationQuat());

			APlaceholder* placeholder = GetWorld()->SpawnActor<APlaceholder>(placeholderClass, transform, buildingSpawnParameters);
			placeholder->setType(1);
			placeholders.Add(placeholder);

			numProductions++;
		}
	}

}

void ATown::addShack()
{

	if (spawnIndex < shackSpawnTransform.Num()) {
		shackSpawnTransform[spawnIndex].SetLocation(shackSpawnTransform[spawnIndex].GetLocation() + GetActorLocation());
		shackSpawnTransform[spawnIndex].SetRotation(shackSpawnTransform[spawnIndex].GetRotation());


		AShack* building = GetWorld()->SpawnActor<AShack>(shackClass, shackSpawnTransform[spawnIndex], buildingSpawnParameters);
		shacks.Add(building);
		building->SetActorScale3D(shackSpawnTransform[spawnIndex].GetScale3D());

		spawnIndex++;
	}
	
}

AWarehouse * ATown::addWarehouse(FTransform transform, int ID)
{
	AWarehouse* building = GetWorld()->SpawnActor<AWarehouse>(warehouseClass, transform, buildingSpawnParameters);
	warehouses.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numWarehouses++;
	return building;
}

AManufacture* ATown::addManufacture(FTransform transform)
{
	AManufacture* building = GetWorld()->SpawnActor<AManufacture>(manufactureClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

APlantation* ATown::addPlantation(FTransform transform)
{
	APlantation* building = GetWorld()->SpawnActor<APlantation>(plantationClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

AForge * ATown::addForge(FTransform transform)
{
	AForge* building = GetWorld()->SpawnActor<AForge>(forgeClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

APapermill * ATown::addPapermill(FTransform transform)
{
	APapermill* building = GetWorld()->SpawnActor<APapermill>(papermillClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

ALightworks * ATown::addLightworks(FTransform transform)
{
	ALightworks* building = GetWorld()->SpawnActor<ALightworks>(lightworksClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

ATitanExtractor * ATown::addTitanExtractor(FTransform transform)
{
	ATitanExtractor* building = GetWorld()->SpawnActor<ATitanExtractor>(titanextractorClass, transform, buildingSpawnParameters);
	buildings.Add(building);
	building->SetActorScale3D(transform.GetScale3D());
	numProductions++;
	return building;
}

TArray<class APlaceholder*> ATown::getPlaceholders(int32 index)
{
	if (index == 1) {
		return placeholders;
	}
	else {
		return placeholders;
	}
}

TArray<ABuildingBase*>& ATown::getBuildings()
{
	return buildings;
}

TArray<AWarehouse*>& ATown::getWarehouses()
{
	return warehouses;
}

UMarketInventory * ATown::getMarketInventory()
{
	return marketInventory;
}

int ATown::getPopulation()
{
	return total_population;
}

int ATown::getManufactureCost()
{
	return costs.manufacture_cost;
}

int ATown::getForgeCost()
{
	return costs.forge_cost;
}

int ATown::getLumbermillCost()
{
	return costs.lumbermill_cost;
}

int ATown::getGeneratorCost()
{
	return costs.generator_cost;
}

int ATown::getLightworksCost()
{
	return costs.lightworks_cost;
}

int ATown::getTitanExtractorCost()
{
	return costs.titanextractor_cost;
}

int ATown::getWarehouseCost()
{
	return costs.warehouse_cost;
}

int ATown::getManufactureRefittingCost()
{
	return costs.refitting_manufacture_cost;
}

int ATown::getForgeRefittingCost()
{
	return costs.refitting_forge_cost;
}

int ATown::getLumbermillRefittingCost()
{
	return costs.refitting_lumbermill_cost;
}

int ATown::getGeneratorRefittingCost()
{
	return costs.refitting_generator_cost;
}

int ATown::getLightworksRefittingCost()
{
	return costs.refitting_lightworks_cost;
}

int ATown::getTitanExtractorRefittingCost()
{
	return costs.refitting_titanextractor_cost;
}



