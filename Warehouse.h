// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "Warehouse.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API AWarehouse : public ABuildingBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class ABuildingBase*> buildings;
	UPROPERTY(EditAnywhere, Category = "Storage")
		class AHuman_Controller_BP* player_proxy;
	UPROPERTY(EditAnywhere, Category = "Storage")
		class UAdvancedInventory* storage;
	UPROPERTY(EditAnywhere, Category = "Counter")
		int warehouseCounter; // simple counter
	UPROPERTY(EditAnywhere, Category = "Counter")
		int warehouseProductionCounter; // production cycle
	UPROPERTY(EditAnywhere, Category = "Counter")
		int productionDivisor; // divisor for slowing down production
public:
	AWarehouse();

	UFUNCTION(BlueprintCallable, Category = "Resources")
		TArray<ABuildingBase*>& getBuildings();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void addBuildingToArray(class ABuildingBase* building);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void count();
	UFUNCTION(BlueprintCallable, Category = "Storage")
		class UAdvancedInventory* getStorage();

	UFUNCTION(BlueprintCallable, Category = "Player")
		void setPlayerProxy(class AHuman_Controller_BP* control);
	UFUNCTION(BlueprintCallable, Category = "Player")
		class AHuman_Controller_BP* getPlayerProxy();

};

