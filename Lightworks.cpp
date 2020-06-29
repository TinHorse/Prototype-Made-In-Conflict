// Fill out your copyright notice in the Description page of Project Settings.

#include "Lightworks.h"

#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"
ALightworks::ALightworks() {
	raw_material_type = EResourceEnum::None;
	production_type = EResourceEnum::Light;
	output_per_worker = 1.5;
	max_workers = 60;
	raw_material_need_per_production = 0;
	power_need_per_labour = 0;
	titan_need_per_labour = 1;
	building_name = "LIGHTWORKS";

	// cost and refitting
	titan_cost = costs.lightworks_cost;
	equipment_refitting_cost = costs.refitting_lightworks_cost;
	refitting_time = 60;
	refitting = 0;
}

bool ALightworks::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	return true;
}

void ALightworks::updateLabour(AWarehouse * warehouse)
{
	float labour = inventory->getLabour();
	float updated_production = (output_per_worker * labour);
	float production_increase = updated_production - previous_production;

	// titan cost
	productionTitanCost = labour * titan_need_per_labour;
	productionPowerCost = labour * power_need_per_labour;
	float productionTitanCostIncrease = productionTitanCost - previousProductionTitanCost;
	float productionPowerCostIncrease = productionPowerCost - previousProductionPowerCost;

	warehouse->getStorage()->addLightProduction(production_increase, 0);

	warehouse->getPlayerProxy()->addTitanDemand(productionTitanCostIncrease);
	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);


	previous_production = updated_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
