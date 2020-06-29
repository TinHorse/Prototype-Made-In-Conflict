// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "Lightworks.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API ALightworks : public ABuildingBase
{
	GENERATED_BODY()
	
public:
	ALightworks();
	bool refit(class AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource) override;
	virtual void updateLabour(class AWarehouse* warehouse);
	
};
