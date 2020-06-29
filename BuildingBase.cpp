// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingBase.h"
#include "Inventory.h"
#include "Warehouse.h"
#include "Engine/World.h"

// Sets default values
ABuildingBase::ABuildingBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	inventory = CreateDefaultSubobject<UInventory>("inventory");
	production_difference = 0;
	updated_raw_material_need = 0;

	refitting_option_1 = EResourceEnum::None;
	refitting_option_2 = EResourceEnum::None;
	refitting_option_3 = EResourceEnum::None;
}

// Called when the game starts or when spawned
void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();
}

UInventory * ABuildingBase::getInventory()
{
	return inventory;
}

bool ABuildingBase::getUpdateRenderState()
{
	return updateRenderState;
}

void ABuildingBase::setUpdateRenderState(bool state)
{
	updateRenderState = state;
}

bool ABuildingBase::getCurrentRenderState()
{
	return currentRenderState;
}

void ABuildingBase::setCurrentRenderState(bool state)
{
	currentRenderState = state;
}

bool ABuildingBase::produce(AWarehouse * warehouse)
{
	return false;
}

void ABuildingBase::updateLabour(AWarehouse * warehouse)
{
}

bool ABuildingBase::refit(AWarehouse * warehouse, TEnumAsByte<EResourceEnum> resource)
{
	return false;
}

int ABuildingBase::getProduction()
{
	return production;
}

int ABuildingBase::getRawMaterialNeed()
{
	return updated_raw_material_need;
}

TEnumAsByte<EResourceEnum> ABuildingBase::getRawMaterialType()
{
	return raw_material_type;
}

FString ABuildingBase::getBuildingName()
{
	return building_name;
}

int ABuildingBase::getMaxLabour()
{
	return max_workers;
}

TEnumAsByte<EResourceEnum> ABuildingBase::getProductionType()
{
	return production_type;
}

int ABuildingBase::getTitanCost()
{
	return titan_cost;
}

int ABuildingBase::getEquipmentRefittingCost()
{
	return equipment_refitting_cost;
}

void ABuildingBase::decrementRefitting()
{
	refitting--;
}

int ABuildingBase::getRefitting()
{
	return refitting;
}

int ABuildingBase::getProductionTitanCost()
{
	return productionTitanCost;
}

int ABuildingBase::getProductionPowerCost()
{
	return productionPowerCost;
}

TEnumAsByte<EResourceEnum> ABuildingBase::getRefittingOption1()
{
	return refitting_option_1;
}

TEnumAsByte<EResourceEnum> ABuildingBase::getRefittingOption2()
{
	return refitting_option_2;
}

TEnumAsByte<EResourceEnum> ABuildingBase::getRefittingOption3()
{
	return refitting_option_3;
}
