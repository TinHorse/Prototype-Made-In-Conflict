// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UInventory::getLabour()
{
	return labour;
}

int UInventory::getTitan()
{
	return titan;
}

int UInventory::getPower()
{
	return power;
}

int UInventory::getLight()
{
	return light;
}

int UInventory::getCommodities()
{
	return commodities;
}

int UInventory::getWeapons()
{
	return weapons;
}

int UInventory::getTitanCoils()
{
	return titan_coils;
}

int UInventory::getLumber()
{
	return lumber;
}


int UInventory::getLoyalistLiterature()
{
	return loyalist_literature;
}

int UInventory::getSeparatistLiterature()
{
	return separatist_literature;
}


float UInventory::addLabour(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	labour += amount;
	if (labour < 0) {
		diff = labour;
		labour = 0;
	}
	return diff;
}

float UInventory::addTitan(float amount, float diff)
{
	if (diff != 0) {
		amount += diff;
	}

	titan += amount;
	if (titan < 0) {
		diff = titan;
		titan = 0;
	}
	return diff;
}

float UInventory::addPower(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	power += amount;
	if (power < 0) {
		diff = power;
		power = 0;
	}
	return diff;
}

float UInventory::addLight(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}
	
	if (diff != 0) {
		amount += diff;
	}

	light += amount;
	if (light < 0) {
		diff = light;
		light = 0;
	}
	return diff;
}

float UInventory::addCommodities(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	commodities += amount;
	if (commodities < 0) {
		diff = commodities;
		commodities = 0;
	}
	return diff;
}

float UInventory::addWeapons(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	weapons += amount;
	if (weapons < 0) {
		diff = weapons;
		weapons = 0;
	}
	return diff;
}

float UInventory::addTitanCoils(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	titan_coils += amount;
	if (titan_coils < 0) {
		diff = titan_coils;
		titan_coils = 0;
	}
	return diff;
}

float UInventory::addLumber(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	lumber += amount;
	if (lumber < 0) {
		diff = lumber;
		lumber = 0;
	}
	return diff;
}


float UInventory::addLoyalistLiterature(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	loyalist_literature += amount;
	if (loyalist_literature < 0) {
		diff = loyalist_literature;
		loyalist_literature = 0;
	}
	return diff;
}

float UInventory::addSeparatistLiterature(float amount, float diff, float titan_availibility, float price_per_unit)
{
	if (price_per_unit > 0) {
		float factor = titan_availibility / (price_per_unit * 10);
		if (factor > 1) { factor = 1; }
		amount *= factor;
	}

	if (diff != 0) {
		amount += diff;
	}

	separatist_literature += amount;
	if (separatist_literature < 0) {
		diff = separatist_literature;
		separatist_literature = 0;
	}
	return diff;
}
