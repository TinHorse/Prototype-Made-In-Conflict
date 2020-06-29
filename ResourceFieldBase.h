// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceFieldBase.generated.h"

UCLASS()
class MADEINCONFLICT__API AResourceFieldBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AResourceFieldBase();
	UPROPERTY(EditAnywhere, Category = "Objects")
		int NumResourceObjects;
	UPROPERTY(EditAnywhere, Category = "Objects")
		float boundsX;
	UPROPERTY(EditAnywhere, Category = "Objects")
		float boundsY;
	UPROPERTY(EditAnywhere, Category = "Objects")
		TSubclassOf<class AResourceObject> resourceClass;
	UPROPERTY(EditAnywhere, Category = "Objects")
		TSubclassOf<class AResourceObject> resourceClass2;
	UPROPERTY(EditAnywhere, Category = "Objects")
		TSubclassOf<class AResourceObject> resourceClass3;
	UPROPERTY(EditAnywhere, Category = "Objects")
		TSubclassOf<class AResourceObject> resourceClass4;
	UPROPERTY(EditAnywhere, Category = "Objects")
		TArray<class AResourceObject*> resourceObjects;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void makeResourceObjects();
	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void setBoundsX(float targetBounds);
	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void setBoundsY(float targetBounds);
	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void setNumObjects(float targetNumObjects);
	UFUNCTION(BlueprintCallable, Category = "Scale")
		void scaleObjects();

};
