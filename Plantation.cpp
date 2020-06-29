// Fill out your copyright notice in the Description page of Project Settings.

#include "Plantation.h"
#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"

APlantation::APlantation() {
	raw_material_type = EResourceEnum::None;
	production_type = EResourceEnum::Lumber;
	output_per_worker = 2;
	max_workers = 30;
	raw_material_need_per_production = 0;
	power_need_per_labour = 0.3;
	titan_need_per_labour = 1;
	building_name = "LUMBERMILL";

	// cost and refitting
	titan_cost = costs.lumbermill_cost;
	equipment_refitting_cost = costs.refitting_lumbermill_cost;
	refitting_time = 60;
	refitting = 0;
}

bool APlantation::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	return true;
}

void APlantation::updateLabour(AWarehouse * warehouse)
{
	float labour = inventory->getLabour();
	float updated_production = (output_per_worker * labour);
	float production_increase = updated_production - previous_production;

	// titan cost
	productionTitanCost = labour * titan_need_per_labour;
	productionPowerCost = labour * power_need_per_labour;
	float productionTitanCostIncrease = productionTitanCost - previousProductionTitanCost;
	float productionPowerCostIncrease = productionPowerCost - previousProductionPowerCost;

	warehouse->getStorage()->addLumberProduction(production_increase, 0);

	warehouse->getPlayerProxy()->addTitanDemand(productionTitanCostIncrease);
	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);

	
	previous_production = updated_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
