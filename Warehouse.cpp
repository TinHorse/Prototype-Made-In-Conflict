// Fill out your copyright notice in the Description page of Project Settings.

#include "Warehouse.h"
#include "AdvancedInventory.h"
#include "Human_Controller_BP.h"

AWarehouse::AWarehouse() {
	inventory = nullptr;
	storage = CreateDefaultSubobject<UAdvancedInventory>("storage");
	warehouseCounter = 0;
	warehouseProductionCounter = 120;
	productionDivisor = 20;
	building_name = "WAREHOUSE";
}

TArray<ABuildingBase*>& AWarehouse::getBuildings()
{
	return buildings;
}


void AWarehouse::addBuildingToArray(ABuildingBase * building)
{
	buildings.Add(building);
	player_proxy->modifyTitan(-building->getTitanCost(),0);
}

void AWarehouse::count()
{
	warehouseCounter++;
	if (warehouseCounter % warehouseProductionCounter == 0) {
		/*
		for (auto building : buildings) {
			if (building->getRefitting()) {
				building->decrementRefitting();
			}
		}
		*/

		// PRODUCTION: raw material availibility

		float titan_availibility = 0;
		float total_titan = player_proxy->getTitanProduction() + player_proxy->getTitan();
		if (total_titan) {
			titan_availibility = (total_titan / player_proxy->getTitanDemand());
		}
		titan_availibility = FMath::Clamp(titan_availibility, 0.f, 1.f);


		float power_availibility = 0;
		float total_power = storage->getPowerProduction() + storage->getPower();
		if (total_power) {
			power_availibility = (total_power / storage->getPowerDemand());
		}
		power_availibility = FMath::Clamp(power_availibility, 0.f, 1.f);


		float light_availibility = 0;
		float total_light = storage->getLightProduction() + storage->getLight();
		if (total_light) {
			light_availibility = (total_light / storage->getLightDemand());
		}
		light_availibility = FMath::Clamp(light_availibility, 0.f, 1.f);


		float lumber_availibility = 0;
		float total_lumber = storage->getLumberProduction() + storage->getLumber();
		if (total_lumber) {
			lumber_availibility = (total_lumber / storage->getLumberDemand());
		}
		lumber_availibility = FMath::Clamp(lumber_availibility, 0.f, 1.f);

		

		// PRODUCTION

		float production = 0;
		float factor = 1;

		// power
		production = storage->getPowerProduction() / productionDivisor;

		factor = titan_availibility;
		if (light_availibility < factor) { factor = light_availibility; }
		
		storage->addPower(((production * factor) - (storage->getPowerDemand() / productionDivisor)), 0);

		// commodities
		production = storage->getCommoditiesProduction() / productionDivisor;
		factor = power_availibility;
		if (titan_availibility < factor) { factor = titan_availibility; }
		if (lumber_availibility < factor) { factor = lumber_availibility; }

		storage->addCommodities(((production * factor) - (storage->getCommoditiesDemand() / productionDivisor)), 0);

		// weapons
		production = storage->getWeaponsProduction() / productionDivisor;
		factor = power_availibility;
		if (titan_availibility < factor) { factor = titan_availibility; }

		storage->addWeapons(((production * factor) - (storage->getWeaponsDemand() / productionDivisor)), 0);

		// lumber
		production = storage->getLumberProduction() / productionDivisor;
		factor = power_availibility; 
		if (titan_availibility < factor) { factor = titan_availibility; }
		
		storage->addLumber(((production * factor) - (storage->getLumberDemand() / productionDivisor)), 0);

		// light
		production = storage->getLightProduction() / productionDivisor;
		factor = titan_availibility;
		UE_LOG(LogTemp, Warning, TEXT("%f storage->getLightProduction()"), storage->getLightProduction());
		UE_LOG(LogTemp, Warning, TEXT("%f productionDivisor"), productionDivisor);
		UE_LOG(LogTemp, Warning, TEXT("%f production"), production);
		UE_LOG(LogTemp, Warning, TEXT("%f factor"), factor);
		UE_LOG(LogTemp, Warning, TEXT("%f storage->getLightDemand()"), storage->getLightDemand());
		storage->addLight(((production * factor) - (storage->getLightDemand() / productionDivisor)), 0);
	
		// titan coils
		production = storage->getTitanCoilsProduction() / productionDivisor;
		factor = power_availibility;
		if (titan_availibility < factor) { factor = titan_availibility; }

		storage->addTitanCoils(((production * factor) - (storage->getTitanCoilsDemand() / productionDivisor)), 0);
		
		// loyalist literature
		production = storage->getLoyalistLiteratureProduction() / productionDivisor;
		factor = power_availibility;
		if (titan_availibility < factor) { factor = titan_availibility; }

		storage->addLoyalistLiterature(((production * factor) - (storage->getLoyalistLiteratureDemand() / productionDivisor)), 0);

		// separatist literature
		production = storage->getSeparatistLiteratureProduction() / productionDivisor;
		factor = power_availibility;
		if (titan_availibility < factor) { factor = titan_availibility; }

		storage->addSeparatistLiterature(((production * factor) - (storage->getSeparatistLiteratureDemand() / productionDivisor)), 0);
	}
}

UAdvancedInventory * AWarehouse::getStorage()
{
	return storage;
}

void AWarehouse::setPlayerProxy(AHuman_Controller_BP* control)
{
	player_proxy = control;
}

AHuman_Controller_BP* AWarehouse::getPlayerProxy()
{
	return player_proxy;
}
