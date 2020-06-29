// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedInventory.h"
#include "MyClass.h"
#include "MarketInventory.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API UMarketInventory : public UAdvancedInventory
{
	GENERATED_BODY()
public:
	UMarketInventory();
	
protected:
	// GENERAL
	float division_factor; // determines how much demand increases the price of resources
	float market_price_factor; // Prices for resources bought from the market are multiplied by this factor

	/*
	// DEMANDS
	UPROPERTY(EditAnywhere, Category = "Demands")
		float labour_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float power_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float commodities_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float weapons_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float titan_coils_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float loyalist_literature_demand;
	UPROPERTY(EditAnywhere, Category = "Demands")
		float separatist_literature_demand;
	*/


	// BASE PRICES
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float labour_basePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float powerbasePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float commodities_basePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float weapons_basePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float titan_coils_basePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float loyalist_literature_basePrice;
	UPROPERTY(EditAnywhere, Category = "Base Prices")
		float separatist_literature_basePrice;

	// PRICES
	UPROPERTY(EditAnywhere, Category = "Prices")
		float labour_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float power_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float commodities_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float weapons_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float titan_coils_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float loyalist_literature_price;
	UPROPERTY(EditAnywhere, Category = "Prices")
		float separatist_literature_price;

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void updateDemandsPeriodically(float population);
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void initialize();
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void calculatePricesIncremental(TEnumAsByte<EResourceEnum> resource, float demand_increase);
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void calculatePricesPeriodically();

	UFUNCTION(BlueprintCallable, Category = "Prices")
		float getMarketPriceFactor();


	// PRICES
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getLabourPrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getCommoditiesPrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getPowerPrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getWeaponsPrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getTitanCoilsPrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getLoyalistLiteraturePrice();
	UFUNCTION(BlueprintCallable, Category = "Prices")
		int getSeparatistLiteraturePrice();

	UFUNCTION(BlueprintCallable, Category = "Demand_Modification")
		float modifyDemandAmount(float titan_availibility, float price_per_unit, float resource);

	// TIER I
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellLabour(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyLabour(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellPower(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyPower(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);

	// TIER II
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellCommodities(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyCommodities(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellWeapons(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyWeapons(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);

	// TIER III
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellTitanCoils(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyTitanCoils(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellLoyalistLiterature(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buyLoyalistLiterature(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void sellSeparatistLiterature(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Trade")
		void buySeparatistLiterature(class UAdvancedInventory* warehouse_inventory, class AWarehouse* warehouse);
};
