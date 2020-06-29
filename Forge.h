// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "Forge.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API AForge : public ABuildingBase
{
	GENERATED_BODY()
public:
	AForge();
	bool refit(class AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource) override;
	virtual void updateLabour(class AWarehouse* warehouse);
};
