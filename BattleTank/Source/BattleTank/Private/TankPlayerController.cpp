// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/Pawn.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankController on BeginPlay"));
	MyTank = GetControlledTank();
	if (!MyTank) {
		UE_LOG(LogTemp, Warning, TEXT("I do not possess a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("My tank is %s"), *MyTank->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}