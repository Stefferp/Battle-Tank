// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20; //sensible default

	UPROPERTY(EditAnywhere)
		float MaxElevation = 40; //sensible default	

	UPROPERTY(EditAnywhere)
		float MinElevation = -5; //sensible default
};

