// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyClass.h"
#include "Town.generated.h"

UCLASS()
class MADEINCONFLICT__API ATown : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	BuildingCosts costs;

	UPROPERTY(EditAnywhere, Category = "Faction")
		TEnumAsByte<EFactionEnum> faction;
	UPROPERTY(EditAnywhere, Category = "Name")
		TEnumAsByte<ETownNames> town_name;
	UPROPERTY(EditAnywhere, Category = "Storage")
		class UMarketInventory* marketInventory;
	UPROPERTY(EditAnywhere, Category = "Population")
		int total_population;

	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class AGate*> gates;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class AShack*> shacks;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class ABuildingBase*> buildings;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class APlaceholder*> placeholders;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class AWarehouse*> warehouses;


	// CLASSES
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AGate> gateClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AShack> shackClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class APlaceholder> placeholderClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AManufacture> manufactureClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class APlantation> plantationClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class APapermill> papermillClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class ALightworks> lightworksClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class ATitanExtractor> titanextractorClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AForge> forgeClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AWarehouse> warehouseClass;

	UPROPERTY(EditAnywhere, Category = "ResourceField")
		TSubclassOf<class AResourceFieldBase> treeFieldClass;
	UPROPERTY(EditAnywhere, Category = "ResourceField")
		TSubclassOf<class AResourceFieldBase> titanFieldClass;
	UPROPERTY(EditAnywhere, Category = "ResourceField")
		TSubclassOf<class AResourceFieldBase> lightFieldClass;


	FActorSpawnParameters buildingSpawnParameters;
	TArray <FTransform> shackSpawnTransform;
	TArray <FTransform> buildingSpawnTransforms;
	UPROPERTY(EditAnywhere)
		int32 spawnIndex;
	UPROPERTY(EditAnywhere)
		int32 numProductions;
	UPROPERTY(EditAnywhere)
		int32 numWarehouses;

	UPROPERTY(EditAnywhere, Category = "ResourceField")
		int32 numTreeResourceFields;
	UPROPERTY(EditAnywhere, Category = "ResourceField")
		int32 numTitanResourceFields;
	UPROPERTY(EditAnywhere, Category = "ResourceField")
		int32 numLightResourceFields;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Factions")
		void setFaction(TEnumAsByte<EFactionEnum> value);
	UFUNCTION(BlueprintCallable, Category = "Factions")
		TEnumAsByte<EFactionEnum> getFaction();
	UFUNCTION(BlueprintCallable, Category = "Town Name")
		TEnumAsByte<ETownNames> getName();


	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void setGatesAndPlaceholders();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void addShack();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		AWarehouse* addWarehouse(FTransform transform, int ID);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class AManufacture* addManufacture(FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class APlantation* addPlantation(FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class AForge* addForge(FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class APapermill* addPapermill(FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class ALightworks* addLightworks(FTransform transform);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		class ATitanExtractor* addTitanExtractor(FTransform transform);

	UFUNCTION(BlueprintCallable, Category = "Buildings")
		TArray<class APlaceholder*> getPlaceholders(int32 index);
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		TArray<ABuildingBase*>& getBuildings();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		TArray<AWarehouse*>& getWarehouses();

	UFUNCTION(BlueprintCallable, Category = "Storage")
		class UMarketInventory* getMarketInventory();

	UFUNCTION(BlueprintCallable, Category = "Population")
		int getPopulation();
	

	// Costs
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getManufactureCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getForgeCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getLumbermillCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getGeneratorCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getLightworksCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getTitanExtractorCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getWarehouseCost();

	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getManufactureRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getForgeRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getLumbermillRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getGeneratorRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getLightworksRefittingCost();
	UFUNCTION(BlueprintCallable, Category = "Costs")
		int getTitanExtractorRefittingCost();
};
