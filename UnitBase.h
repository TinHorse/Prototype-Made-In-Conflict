// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UnitBase.generated.h"

UCLASS()
class MADEINCONFLICT__API AUnitBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "rendering")
		bool updateRenderState;
	UPROPERTY(EditAnywhere, Category = "rendering")
		bool currentRenderState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "rendering")
		bool getUpdateRenderState();
	UFUNCTION(BlueprintCallable, Category = "rendering")
		void setUpdateRenderState(bool state);
	UFUNCTION(BlueprintCallable, Category = "rendering")
		bool getCurrentRenderState();
	UFUNCTION(BlueprintCallable, Category = "rendering")
		void setCurrentRenderState(bool state);

};
