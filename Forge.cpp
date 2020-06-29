// Fill out your copyright notice in the Description page of Project Settings.

#include "Forge.h"
#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"

AForge::AForge() {
	raw_material_type = EResourceEnum::None;
	production_type = EResourceEnum::None;
	output_per_worker = 0;
	max_workers = 15;
	raw_material_need_per_production = 0;
	power_need_per_labour = 0;
	building_name = "FORGE";

	// cost and refitting
	titan_cost = costs.forge_cost;
	equipment_refitting_cost = costs.refitting_forge_cost;
	refitting_time = 60;
	refitting = 0;

	refitting_option_1 = EResourceEnum::Weapons;
	refitting_option_2 = EResourceEnum::TitanCoils;
}

bool AForge::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	// update production
	warehouse->getStorage()->addTitan(-costs.refitting_forge_cost, 0);
	production_type = resource;
	refitting = 20;

	if (resource == EResourceEnum::Weapons) {
		raw_material_type = EResourceEnum::None;
		raw_material_need_per_production = 0;
		output_per_worker = 1.0;
		titan_need_per_labour = 4;
		power_need_per_labour = 2;
	}
	else if (resource == EResourceEnum::TitanCoils) {
		raw_material_type = EResourceEnum::None;
		raw_material_need_per_production = 0;
		output_per_worker = 0.2;
		titan_need_per_labour = 7;
		power_need_per_labour = 4;
	}

	return true;
}

void AForge::updateLabour(AWarehouse * warehouse)
{
	float labour = inventory->getLabour();
	float updated_production = (output_per_worker * labour);
	float production_increase = updated_production - previous_production;

	// titan cost and power cost
	productionTitanCost = labour * titan_need_per_labour;
	productionPowerCost = labour * power_need_per_labour;
	float productionTitanCostIncrease = productionTitanCost - previousProductionTitanCost;
	float productionPowerCostIncrease = productionPowerCost - previousProductionPowerCost;

	if (production_type == EResourceEnum::Weapons) {
		warehouse->getStorage()->addWeaponsProduction(production_increase, 0);
	}
	else if (production_type == EResourceEnum::TitanCoils) {
		warehouse->getStorage()->addTitanCoilsProduction(production_increase, 0);
	}
	warehouse->getPlayerProxy()->addTitanDemand(productionTitanCostIncrease);
	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);


	previous_production = updated_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
