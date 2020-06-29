// Fill out your copyright notice in the Description page of Project Settings.

#include "MarketInventory.h"
#include "Warehouse.h"
#include "Human_Controller_BP.h"

UMarketInventory::UMarketInventory() {
	division_factor = 100;
	market_price_factor = 1.2; // increase of 20% for buying goods from the market
}

void UMarketInventory::updateDemandsPeriodically(float population)
{
	if (commodities_demand < population) {
		commodities_demand += population * 0.02;
	}
	if (power_demand < population) {
		power_demand += population * 0.04;
	}
	if (weapons_demand < population) {
		weapons_demand += population * 0.02;
	}
	calculatePricesPeriodically();
}

void UMarketInventory::initialize()
{
	labour_demand = 0;
	power_demand = 50;
	commodities_demand = 50;
	weapons_demand = 50;
	titan_coils_demand = 5;
	loyalist_literature_demand = 20;
	separatist_literature_demand = 20;


	float price_factor = 1;

	labour_basePrice = 10.0 * price_factor;
	powerbasePrice = 1.6 * price_factor;
	commodities_basePrice = 8.0 * price_factor;
	weapons_basePrice = 7.2 * price_factor;
	titan_coils_basePrice = 67.0 * price_factor;
	loyalist_literature_basePrice = 31.0 * price_factor;
	separatist_literature_basePrice = 31.0 * price_factor;
	
}

void UMarketInventory::calculatePricesIncremental(TEnumAsByte<EResourceEnum> resource, float demand_increase)
{

	if (resource == EResourceEnum::Labour) {
		labour_demand += demand_increase;
		if (labour_demand < 0) { labour_demand = 0; }
		labour_price = labour_basePrice + (labour_demand / division_factor);
	}
	else if (resource == EResourceEnum::Power) {
		power_demand += demand_increase;
		if (power_demand < 0) { power_demand = 0; }
		power_price = powerbasePrice + (power_demand / division_factor);
	}

	else if (resource == EResourceEnum::Commodities) {
		commodities_demand += demand_increase;
		if (commodities_demand < 0) { commodities_demand = 0; }
		commodities_price =commodities_basePrice + (commodities_demand / division_factor);
	}
	else if (resource == EResourceEnum::Weapons) {
		weapons_demand += demand_increase;
		if (weapons_demand < 0) { weapons_demand = 0; }
		weapons_price = weapons_basePrice + (weapons_demand / division_factor);
	}
	else if (resource == EResourceEnum::TitanCoils) {
		titan_coils_demand += demand_increase;
		if (titan_coils_demand < 0) { titan_coils_demand = 0; }
		titan_coils_demand = titan_coils_basePrice + (titan_coils_demand / division_factor);
	}
	else if (resource == EResourceEnum::LoyalistLiterature) {
		loyalist_literature_demand += demand_increase;
		if (loyalist_literature_demand < 0) { loyalist_literature_demand = 0; }
		loyalist_literature_price = loyalist_literature_basePrice + (loyalist_literature_demand / division_factor);
	}
	else if (resource == EResourceEnum::SeparatistLiterature) {
		separatist_literature_demand += demand_increase;
		if (separatist_literature_demand < 0) { separatist_literature_demand = 0; }
		separatist_literature_price = separatist_literature_basePrice + (separatist_literature_demand / division_factor);
	}
}

void UMarketInventory::calculatePricesPeriodically()
{
	labour_price = labour_basePrice + ((labour_demand * labour_basePrice) / division_factor);
	power_price = powerbasePrice + ((power_demand * powerbasePrice) / division_factor);
	commodities_price = commodities_basePrice + ((commodities_demand * commodities_basePrice ) / division_factor);
	weapons_price = weapons_basePrice + ((weapons_demand * weapons_basePrice) / division_factor);
	titan_coils_price = titan_coils_basePrice + ((titan_coils_demand * titan_coils_basePrice) / division_factor);
	loyalist_literature_price = loyalist_literature_basePrice + ((loyalist_literature_demand * loyalist_literature_basePrice) / division_factor);
	separatist_literature_price = separatist_literature_basePrice + ((separatist_literature_demand * separatist_literature_basePrice) / division_factor);
}

float UMarketInventory::getMarketPriceFactor()
{
	return market_price_factor;
}


int UMarketInventory::getLabourPrice()
{
	return labour_price;
}

int UMarketInventory::getPowerPrice()
{
	return power_price;
}

int UMarketInventory::getCommoditiesPrice()
{
	return commodities_price;
}

int UMarketInventory::getWeaponsPrice()
{
	return weapons_price;
}

int UMarketInventory::getTitanCoilsPrice()
{
	return titan_coils_price;
}

int UMarketInventory::getLoyalistLiteraturePrice()
{
	return loyalist_literature_price;
}

int UMarketInventory::getSeparatistLiteraturePrice()
{
	return separatist_literature_price;
}

float UMarketInventory::modifyDemandAmount(float titan_availibility, float price_per_unit, float resource)
{
	float factor = titan_availibility / (price_per_unit);
	if (factor > 1) { factor = 1; }

	if (resource < factor) {
		factor = resource;
	}

	return factor;
}


// TIER I


void UMarketInventory::sellLabour(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getLabourPrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getLabour();

	float diff = warehouse_inventory->addLabour(-10, 0, titan, price);
	addLabour(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Labour, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyLabour(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getLabourPrice() * market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getLabour();

	float diff = addLabour(-10, 0, titan, price);
	warehouse_inventory->addLabour(10, diff, titan, price);

	float amount = price* modifyDemandAmount(titan, price, resource);
	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Labour, modifyDemandAmount(titan, price, resource));
}



void UMarketInventory::sellPower(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getPowerPrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getPower();

	float diff = warehouse_inventory->addPower(-10, 0, titan, price);
	addPower(10, diff, titan, price);

	float amount = price* modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);

	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Power, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyPower(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getPowerPrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();	
	float resource = getPower();

	float diff = addPower(-10, 0, titan, price);
	warehouse_inventory->addPower(10, diff, titan, price);

	float amount = price* modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Power, modifyDemandAmount(titan, price, resource));
}



// TIER II

void UMarketInventory::sellCommodities(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getCommoditiesPrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getCommodities();


	float diff = warehouse_inventory->addCommodities(-10, 0, titan, price);
	addCommodities(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Commodities, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyCommodities(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getCommoditiesPrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getCommodities();

	float diff = addCommodities(-10, 0, titan, price);
	warehouse_inventory->addCommodities(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Commodities, modifyDemandAmount(titan, price, resource));
}


void UMarketInventory::sellWeapons(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getWeaponsPrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getWeapons();

	float diff = warehouse_inventory->addWeapons(-10, 0, titan, price);
	addWeapons(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Weapons, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyWeapons(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getWeaponsPrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getWeapons();

	float diff = addWeapons(-10, 0, titan, price);
	warehouse_inventory->addWeapons(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::Weapons, modifyDemandAmount(titan, price, resource));
}


// TIER III

void UMarketInventory::sellTitanCoils(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getTitanCoilsPrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getTitanCoils();

	float diff = warehouse_inventory->addTitanCoils(-10, 0, titan, price);
	addTitanCoils(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::TitanCoils, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyTitanCoils(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getTitanCoilsPrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getTitanCoils();

	float diff = addTitanCoils(-10, 0, titan, price);
	warehouse_inventory->addTitanCoils(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::TitanCoils, modifyDemandAmount(titan, price, resource));
}

void UMarketInventory::sellLoyalistLiterature(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getLoyalistLiteraturePrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getLoyalistLiterature();

	float diff = warehouse_inventory->addLoyalistLiterature(-10, 0, titan, price);
	addLoyalistLiterature(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::LoyalistLiterature, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buyLoyalistLiterature(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getLoyalistLiteraturePrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getLoyalistLiterature();

	float diff = addLoyalistLiterature(-10, 0, titan, price);
	warehouse_inventory->addLoyalistLiterature(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::LoyalistLiterature, modifyDemandAmount(titan, price, resource));
}

void UMarketInventory::sellSeparatistLiterature(UAdvancedInventory* warehouse_inventory, AWarehouse* warehouse)
{
	float price = getSeparatistLiteraturePrice();
	float titan = getTitan();
	float resource = warehouse_inventory->getSeparatistLiterature();

	float diff = warehouse_inventory->addSeparatistLiterature(-10, 0, titan, price);
	addSeparatistLiterature(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = addTitan(-amount, 0);
	warehouse->getPlayerProxy()->modifyTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::SeparatistLiterature, -modifyDemandAmount(titan, price, resource));

}

void UMarketInventory::buySeparatistLiterature(UAdvancedInventory * warehouse_inventory, AWarehouse* warehouse)
{
	float price = getSeparatistLiteraturePrice()* market_price_factor;
	float titan = warehouse->getPlayerProxy()->getTitan();
	float resource = getSeparatistLiterature();

	float diff = addSeparatistLiterature(-10, 0, titan, price);
	warehouse_inventory->addSeparatistLiterature(10, diff, titan, price);

	float amount = price * modifyDemandAmount(titan, price, resource);

	diff = warehouse->getPlayerProxy()->modifyTitan(-amount, 0);
	addTitan(amount, diff);

	calculatePricesIncremental(EResourceEnum::SeparatistLiterature, modifyDemandAmount(titan, price, resource));
}
