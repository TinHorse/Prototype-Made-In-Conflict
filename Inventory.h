// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MADEINCONFLICT__API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float labour;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float titan;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float light;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float power;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float commodities;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float weapons;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float titan_coils;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float lumber;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float loyalist_literature;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float separatist_literature;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// GET
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getLabour();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getTitan();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getPower();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getLight();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getLumber();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getCommodities();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getWeapons();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getTitanCoils();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getLoyalistLiterature();
	UFUNCTION(BlueprintCallable, Category = "Get")
		int getSeparatistLiterature();

	// ADD
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addLabour(float amount, float diff, float titan_availibility =0, float price_per_unit=0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addTitan(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addPower(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addLight(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addCommodities(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addWeapons(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addTitanCoils(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addLumber(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addLoyalistLiterature(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
	UFUNCTION(BlueprintCallable, Category = "Modify")
		float addSeparatistLiterature(float amount, float diff, float titan_availibility = 0, float price_per_unit = 0);
};
