// Fill out your copyright notice in the Description page of Project Settings.

#include "Papermill.h"
#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"

APapermill::APapermill() {
	raw_material_type = EResourceEnum::Light;
	production_type = EResourceEnum::Power;
	output_per_worker = 1;
	max_workers = 45;
	raw_material_need_per_production = 1;
	power_need_per_labour = 0;
	titan_need_per_labour = 1;
	building_name = "GENERATOR";

	// cost and refitting
	titan_cost = costs.generator_cost;
	equipment_refitting_cost = costs.refitting_generator_cost;
	refitting_time = 60;
	refitting = 0;
}

bool APapermill::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	return true;
}

void APapermill::updateLabour(AWarehouse * warehouse)
{
	float labour = inventory->getLabour();
	float updated_production = (output_per_worker * labour);
	float production_increase = updated_production - previous_production;

	// titan cost
	productionTitanCost = labour * titan_need_per_labour;
	productionPowerCost = labour * power_need_per_labour;
	float productionTitanCostIncrease = productionTitanCost - previousProductionTitanCost;
	float productionPowerCostIncrease = productionPowerCost - previousProductionPowerCost;

	// input
	float raw_material_need = (updated_production - previous_production) * raw_material_need_per_production;

	warehouse->getStorage()->addLightDemand(raw_material_need);
	warehouse->getStorage()->addPowerProduction(production_increase, 0);

	warehouse->getPlayerProxy()->addTitanDemand(productionTitanCostIncrease);
	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);


	previous_production = updated_production;
	updated_raw_material_need = updated_production * raw_material_need_per_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
