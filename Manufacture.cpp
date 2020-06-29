// Fill out your copyright notice in the Description page of Project Settings.

#include "Manufacture.h"
#include "Warehouse.h"
#include "Human_Controller_BP.h"
#include "AdvancedInventory.h"
AManufacture::AManufacture() {
	raw_material_type = EResourceEnum::None;
	production_type = EResourceEnum::None;
	output_per_worker = 0;
	max_workers = 30;
	raw_material_need_per_production = 0;
	power_need_per_labour = 0;
	building_name = "MANUFACTURE";

	// cost and refitting
	titan_cost = costs.manufacture_cost;
	equipment_refitting_cost = costs.refitting_manufacture_cost;
	refitting_time = 60;
	refitting = 0;

	refitting_option_1 = EResourceEnum::Commodities;
	refitting_option_2 = EResourceEnum::LoyalistLiterature;
	refitting_option_3 = EResourceEnum::SeparatistLiterature;
}

bool AManufacture::refit(AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource)
{
	// update production
	warehouse->getStorage()->addTitan(-equipment_refitting_cost, 0);
	production_type = resource;
	refitting = 20;

	if (resource == EResourceEnum::Commodities) {
		raw_material_type = EResourceEnum::Lumber;
		raw_material_need_per_production = 2.6;
		output_per_worker = 0.5;
		titan_need_per_labour = 1;
		power_need_per_labour = 0.7;
	}
	else if (resource == EResourceEnum::LoyalistLiterature) {
		raw_material_type = EResourceEnum::Lumber;
		raw_material_need_per_production = 2.6;
		output_per_worker = 0.2;
		titan_need_per_labour = 2;
		power_need_per_labour = 1.4;
	}
	else if (resource == EResourceEnum::SeparatistLiterature) {
		raw_material_type = EResourceEnum::Lumber;
		raw_material_need_per_production = 2.6;
		output_per_worker = 0.2;
		titan_need_per_labour = 2;
		power_need_per_labour = 1.4;
	}

	return true;
}

void AManufacture::updateLabour(AWarehouse * warehouse)
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

	if (production_type == EResourceEnum::Commodities) {
		warehouse->getStorage()->addLumberDemand(raw_material_need);
		warehouse->getStorage()->addCommoditiesProduction(production_increase, 0);
	}
	else if (production_type == EResourceEnum::LoyalistLiterature) {
		warehouse->getStorage()->addLumberDemand(raw_material_need);
		warehouse->getStorage()->addLoyalistLiteratureProduction(production_increase, 0);
	}
	else if (production_type == EResourceEnum::SeparatistLiterature) {
		warehouse->getStorage()->addLumberDemand(raw_material_need);
		warehouse->getStorage()->addSeparatistLiteratureProduction(production_increase, 0);
	}
	warehouse->getPlayerProxy()->addTitanDemand(productionTitanCostIncrease);
	warehouse->getStorage()->addPowerDemand(productionPowerCostIncrease);


	previous_production = updated_production;
	updated_raw_material_need = updated_production * raw_material_need_per_production;
	previousProductionTitanCost = productionTitanCost;
	previousProductionPowerCost = productionPowerCost;

	production = previous_production;
}
