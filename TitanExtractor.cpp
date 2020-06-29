// Fill out your copyright notice in the Description page of Project Settings.

#include "TitanExtractor.h"

#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"

ATitanExtractor::ATitanExtractor() {
	raw_material_type = EResourceEnum::None;
	production_type = EResourceEnum::Titan;
	output_per_worker = 9;
	max_workers = 15;
	raw_material_need_per_production = 0;
	power_need_per_labour = 2;
	building_name = "TITAN EXTRACTOR";

	// cost and refitting
	titan_cost = costs.titanextractor_cost;
	equipment_refitting_cost = costs.refitting_titanextractor_cost;
	refitting_time = 60;
	refitting = 0;
}

bool ATitanExtractor::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	return true;
}

void ATitanExtractor::updateLabour(AWarehouse * warehouse)
{
	float labour = inventory->getLabour();
	float updated_production = (output_per_worker * labour);
	float production_increase = updated_production - previous_production;

	// titan cost
	productionTitanCost = labour * titan_need_per_labour;
	productionPowerCost = labour * power_need_per_labour;
	float productionTitanCostIncrease = productionTitanCost - previousProductionTitanCost;
	float productionPowerCostIncrease = productionPowerCost - previousProductionPowerCost;

	warehouse->getPlayerProxy()->addTitanProduction(production_increase, 0);

	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);


	previous_production = updated_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
