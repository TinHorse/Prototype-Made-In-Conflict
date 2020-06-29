// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum EFactionEnum
{
	Loyalists 	UMETA(DisplayName = "Loyalists"),
	Separatists 	UMETA(DisplayName = "Separatists"),
	Gloomers	UMETA(DisplayName = "Gloomers"),
	Freemen	UMETA(DisplayName = "Freemen")
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum EResourceEnum
{
	Labour 	UMETA(DisplayName = "Labour"),
	Titan 	UMETA(DisplayName = "Titan"),
	Power 	UMETA(DisplayName = "Power"),
	Light 	UMETA(DisplayName = "Light"),
	Commodities 	UMETA(DisplayName = "Commodities"),
	Weapons 	UMETA(DisplayName = "Weapons"),
	TitanCoils 	UMETA(DisplayName = "TitanCoils"),
	Lumber	UMETA(DisplayName = "Lumber"),
	LoyalistLiterature	UMETA(DisplayName = "LoyalistLiterature"),
	SeparatistLiterature	UMETA(DisplayName = "SeparatistLiterature"),
	None	UMETA(DisplayName = "")
	
};

struct BuildingCosts {
public:
	int	lumbermill_cost = 150;
	int manufacture_cost = 250;
	int generator_cost = 200;
	int forge_cost = 250;
	int lightworks_cost = 250;
	int titanextractor_cost = 250;
	int warehouse_cost = 800;

	int refitting_lumbermill_cost = 30;
	int refitting_manufacture_cost = 30;
	int refitting_generator_cost = 30;
	int refitting_lightworks_cost = 30;
	int refitting_titanextractor_cost = 30;
	int refitting_forge_cost = 30;
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum ETownNames
{
	ARNHEIM 	UMETA(DisplayName = "ARNHEIM"),
	IRONSTEAD 	UMETA(DisplayName = "IRONSTEAD"),
	KINGSBREACH 	UMETA(DisplayName = "KINGSBREACH"),
	MORNAU 	UMETA(DisplayName = "MORNAU"),
};