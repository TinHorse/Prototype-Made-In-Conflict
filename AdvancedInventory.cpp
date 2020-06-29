// Fill out your copyright notice in the Description page of Project Settings.

#include "AdvancedInventory.h"


// GET PRODUCTION
float UAdvancedInventory::getTitanProduction()
{
	return titan_production;
}

float UAdvancedInventory::getLabourProduction()
{
	return labour_production;
}

float UAdvancedInventory::getPowerProduction()
{
	return power_production;
}

float UAdvancedInventory::getLightProduction()
{
	return light_production;
}

float UAdvancedInventory::getCommoditiesProduction()
{
	return commodities_production;
}

float UAdvancedInventory::getWeaponsProduction()
{
	return weapons_production;
}

float UAdvancedInventory::getTitanCoilsProduction()
{
	return titan_coils_production;
}

float UAdvancedInventory::getLumberProduction()
{
	return lumber_production;
}

float UAdvancedInventory::getLoyalistLiteratureProduction()
{
	return loyalist_literature_production;
}

float UAdvancedInventory::getSeparatistLiteratureProduction()
{
	return separatist_literature_production;
}



// ADD PRODUCTION
void UAdvancedInventory::addTitanProduction(float amount, float diff)
{
	titan_production += amount;
}

void UAdvancedInventory::addLabourProduction(float amount, float diff)
{
	labour_production += amount;
}

void UAdvancedInventory::addPowerProduction(float amount, float diff)
{
	power_production += amount;
}

void UAdvancedInventory::addLightProduction(float amount, float diff)
{
	light_production += amount;
}

void UAdvancedInventory::addCommoditiesProduction(float amount, float diff)
{
	commodities_production += amount;
}

void UAdvancedInventory::addWeaponsProduction(float amount, float diff)
{
	weapons_production += amount;
}

void UAdvancedInventory::addTitanCoilsProduction(float amount, float diff)
{
	titan_coils_production += amount;
}

void UAdvancedInventory::addLumberProduction(float amount, float diff)
{
	lumber_production += amount;
}

void UAdvancedInventory::addLoyalistLiteratureProduction(float amount, float diff)
{
	loyalist_literature_production += amount;
}

void UAdvancedInventory::addSeparatistLiteratureProduction(float amount, float diff)
{
	separatist_literature_production += amount;
}



// GET DEMAND
float UAdvancedInventory::getTitanDemand()
{
	return titan_demand;
}

float UAdvancedInventory::getLabourDemand()
{
	return labour_demand;
}

float UAdvancedInventory::getPowerDemand()
{
	return power_demand;
}

float UAdvancedInventory::getLightDemand()
{
	return light_demand;
}

float UAdvancedInventory::getCommoditiesDemand()
{
	return commodities_demand;
}

float UAdvancedInventory::getWeaponsDemand()
{
	return weapons_demand;
}

float UAdvancedInventory::getTitanCoilsDemand()
{
	return titan_coils_demand;
}

float UAdvancedInventory::getLumberDemand()
{
	return lumber_demand;
}

float UAdvancedInventory::getLoyalistLiteratureDemand()
{
	return loyalist_literature_demand;
}

float UAdvancedInventory::getSeparatistLiteratureDemand()
{
	return separatist_literature_demand;
}



// ADD DEMAND
void UAdvancedInventory::addTitanDemand(float amount)
{
	titan_demand += amount;
}

void UAdvancedInventory::addLabourDemand(float amount)
{
	labour_demand += amount;
}

void UAdvancedInventory::addPowerDemand(float amount)
{
	power_demand += amount;
}

void UAdvancedInventory::addLightDemand(float amount)
{
	light_demand += amount;
}

void UAdvancedInventory::addCommoditiesDemand(float amount)
{
	commodities_demand += amount;
}

void UAdvancedInventory::addWeaponsDemand(float amount)
{
	weapons_demand += amount;
}

void UAdvancedInventory::addTitanCoilsDemand(float amount)
{
	titan_coils_demand += amount;
}

void UAdvancedInventory::addLumberDemand(float amount)
{
	lumber_demand += amount;
}

void UAdvancedInventory::addLoyalistLiteratureDemand(float amount)
{
	loyalist_literature_demand += amount;
}

void UAdvancedInventory::addSeparatistLiteratureDemand(float amount)
{
	separatist_literature_demand += amount;
}


/*
void UAdvancedInventory::resetProduction(int turns)
{
	labour_production /= turns;
	titan_production /= turns;
	equipment_production /= turns;
	light_production /= turns;
	textiles_production /= turns;
	weapons_production /= turns;
	titan_coils_production /= turns;
	fibres_production /= turns;
	paper_production /= turns;
	loyalist_literature_production /= turns;
	separatist_literature_production /= turns;
	light_powder_production /= turns;
}
*/
