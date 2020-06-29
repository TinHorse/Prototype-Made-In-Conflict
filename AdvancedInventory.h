// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "AdvancedInventory.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API UAdvancedInventory : public UInventory
{
	GENERATED_BODY()
protected:

	// PRODUCTION
	UPROPERTY(EditAnywhere, Category = "Production")
		float titan_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float labour_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float power_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float light_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float commodities_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float weapons_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float titan_coils_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float lumber_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float loyalist_literature_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float separatist_literature_production;

	// DEMAND
	UPROPERTY(EditAnywhere, Category = "Demand")
		float titan_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float labour_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float power_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float light_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float commodities_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float weapons_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float titan_coils_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float lumber_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float loyalist_literature_demand;
	UPROPERTY(EditAnywhere, Category = "Demand")
		float separatist_literature_demand;

public:
	// GET PRODUCTION
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getTitanProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getLabourProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getPowerProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getLightProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getCommoditiesProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getWeaponsProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getTitanCoilsProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getLumberProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getLoyalistLiteratureProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		float getSeparatistLiteratureProduction();

	// ADD PRODUCTION
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addTitanProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addLabourProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addPowerProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addLightProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addCommoditiesProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addWeaponsProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addTitanCoilsProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addLumberProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addLoyalistLiteratureProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void addSeparatistLiteratureProduction(float amount, float diff);

	// GET DEMAND
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getTitanDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getLabourDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getPowerDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getLightDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getCommoditiesDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getWeaponsDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getTitanCoilsDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getLumberDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getLoyalistLiteratureDemand();
	UFUNCTION(BlueprintCallable, Category = "Demand")
		float getSeparatistLiteratureDemand();

	// ADD DEMAND
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addTitanDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addLabourDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addPowerDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addLightDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addCommoditiesDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addWeaponsDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addTitanCoilsDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addLumberDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addLoyalistLiteratureDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Demand")
		void addSeparatistLiteratureDemand(float amount);

	/*
	UFUNCTION(BlueprintCallable, Category = "Modify")
		void resetProduction(int turns);
	*/
};
