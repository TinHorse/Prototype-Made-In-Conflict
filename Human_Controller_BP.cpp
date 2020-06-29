// Fill out your copyright notice in the Description page of Project Settings.

#include "Human_Controller_BP.h"

AHuman_Controller_BP::AHuman_Controller_BP() {
	bHidden = false;
#if WITH_EDITORONLY_DATA
	bHiddenEd = false;
#endif // WITH_EDITORONLY_DATA

	productionDivisor = 20;
}

float AHuman_Controller_BP::getTitan()
{
	return titan;
}

float AHuman_Controller_BP::modifyTitan(float amount, float diff)
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

float AHuman_Controller_BP::getTitanProduction()
{
	return titan_production;
}

void AHuman_Controller_BP::addTitanProduction(float amount, float diff)
{
	titan_production += amount;
}

float AHuman_Controller_BP::getTitanDemand()
{
	return titan_demand;
}

void AHuman_Controller_BP::addTitanDemand(float amount)
{
	titan_demand += amount;
}

void AHuman_Controller_BP::updateTitan()
{
	modifyTitan((titan_production - titan_demand) / productionDivisor, 0);
}
