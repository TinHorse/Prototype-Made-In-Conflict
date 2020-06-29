// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Human_Controller_BP.generated.h"

/**
 * 
 */
UCLASS()
class MADEINCONFLICT__API AHuman_Controller_BP : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Titan")
		float titan;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float titan_production;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float titan_demand;
	UPROPERTY(EditAnywhere, Category = "Resources")
		float productionDivisor;

public:
	AHuman_Controller_BP();
	UFUNCTION(BlueprintCallable, Category = "Titan")
		float getTitan();
	UFUNCTION(BlueprintCallable, Category = "Titan")
		float modifyTitan(float value, float diff);

	UFUNCTION(BlueprintCallable, Category = "Get")
		float getTitanProduction();
	UFUNCTION(BlueprintCallable, Category = "Modify")
		void addTitanProduction(float amount, float diff);
	UFUNCTION(BlueprintCallable, Category = "Get")
		float getTitanDemand();
	UFUNCTION(BlueprintCallable, Category = "Modify")
		void addTitanDemand(float amount);
	UFUNCTION(BlueprintCallable, Category = "Production")
		void updateTitan();

};
