// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyClass.h"
#include "BuildingBase.generated.h"

UCLASS()
class MADEINCONFLICT__API ABuildingBase : public APawn
{
	GENERATED_BODY()
		
public:
	// Sets default values for this pawn's properties
	ABuildingBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// general
	BuildingCosts costs;

	UPROPERTY(EditAnywhere, Category = "inventory")
		class UInventory* inventory;
	UPROPERTY(EditAnywhere, Category = "Production")
		TEnumAsByte<EResourceEnum> production_type;
	UPROPERTY(EditAnywhere, Category = "rendering")
		bool updateRenderState;
	UPROPERTY(EditAnywhere, Category = "rendering")
		bool currentRenderState;
	UPROPERTY(EditAnywhere, Category = "name")
		FString building_name;

	// cost
	UPROPERTY(EditAnywhere, Category = "Cost")
		int titan_cost;
	UPROPERTY(EditAnywhere, Category = "Refitting")
		int equipment_refitting_cost;
	UPROPERTY(EditAnywhere, Category = "Refitting")
		int refitting_time;
	UPROPERTY(EditAnywhere, Category = "Refitting")
		int refitting;

	// refitting
	UPROPERTY(EditAnywhere, Category = "Refitting")
		TEnumAsByte<EResourceEnum> refitting_option_1;
	UPROPERTY(EditAnywhere, Category = "Refitting")
		TEnumAsByte<EResourceEnum> refitting_option_2;
	UPROPERTY(EditAnywhere, Category = "Refitting")
		TEnumAsByte<EResourceEnum> refitting_option_3;

	// output
	UPROPERTY(EditAnywhere, Category = "Production")
		float production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float previous_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float production_difference;
	UPROPERTY(EditAnywhere, Category = "Production")
		float output_per_worker;

	// labour
	UPROPERTY(EditAnywhere, Category = "Production")
		float max_workers;

	// raw material
	UPROPERTY(EditAnywhere, Category = "Production")
		TEnumAsByte<EResourceEnum> raw_material_type;
	UPROPERTY(EditAnywhere, Category = "Production")
		float raw_material;
	UPROPERTY(EditAnywhere, Category = "Production")
		float raw_material_need_per_production;
	UPROPERTY(EditAnywhere, Category = "Production")
		float raw_material_need;
	UPROPERTY(EditAnywhere, Category = "Production")
		float updated_raw_material_need;

	// titan
	UPROPERTY(EditAnywhere, Category = "Production")
		float titan_need_per_labour;
	UPROPERTY(EditAnywhere, Category = "Production")
		float previousProductionTitanCost;
	UPROPERTY(EditAnywhere, Category = "Production")
		float productionTitanCost;

	// power
	UPROPERTY(EditAnywhere, Category = "Production")
		float power_need_per_labour;
	UPROPERTY(EditAnywhere, Category = "Production")
		float previousProductionPowerCost;
	UPROPERTY(EditAnywhere, Category = "Production")
		float productionPowerCost;

public:	
	UFUNCTION(BlueprintCallable, Category = "inventory")
		class UInventory* getInventory();
	UFUNCTION(BlueprintCallable, Category = "rendering")
		bool getUpdateRenderState();
	UFUNCTION(BlueprintCallable, Category = "rendering")
		void setUpdateRenderState(bool state);
	UFUNCTION(BlueprintCallable, Category = "rendering")
		bool getCurrentRenderState();
	UFUNCTION(BlueprintCallable, Category = "rendering")
		void setCurrentRenderState(bool state);

	UFUNCTION(BlueprintCallable, Category = "Production")
		virtual bool produce(class AWarehouse* warehouse);
	UFUNCTION(BlueprintCallable, Category = "Production")
		virtual void updateLabour(class AWarehouse* warehouse);

	UFUNCTION(BlueprintCallable, Category = "Refit")
		virtual bool refit(class AWarehouse* warehouse, TEnumAsByte<EResourceEnum> resource);

	UFUNCTION(BlueprintCallable, Category = "Production")
		int getProduction();
	UFUNCTION(BlueprintCallable, Category = "Production")
		int getRawMaterialNeed();
	UFUNCTION(BlueprintCallable, Category = "Production")
		TEnumAsByte<EResourceEnum> getRawMaterialType();

	UFUNCTION(BlueprintCallable, Category = "Production")
		FString getBuildingName();
	UFUNCTION(BlueprintCallable, Category = "Production")
		int getMaxLabour();
	UFUNCTION(BlueprintCallable, Category = "Production")
		TEnumAsByte<EResourceEnum> getProductionType();

	// cost
	UFUNCTION(BlueprintCallable, Category = "Cost")
		int getTitanCost();
	UFUNCTION(BlueprintCallable, Category = "Cost")
		int getEquipmentRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Cost")
		void decrementRefitting();
	UFUNCTION(BlueprintCallable, Category = "Cost")
		int getRefitting();
	UFUNCTION(BlueprintCallable, Category = "Production")
		int getProductionTitanCost();
	UFUNCTION(BlueprintCallable, Category = "Production")
		int getProductionPowerCost();

	// refitting
	UFUNCTION(BlueprintCallable, Category = "Production")
		TEnumAsByte<EResourceEnum> getRefittingOption1();
	UFUNCTION(BlueprintCallable, Category = "Production")
		TEnumAsByte<EResourceEnum> getRefittingOption2();
	UFUNCTION(BlueprintCallable, Category = "Production")
		TEnumAsByte<EResourceEnum> getRefittingOption3();
};
