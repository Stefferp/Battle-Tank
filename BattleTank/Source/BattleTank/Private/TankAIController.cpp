// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Pawn.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	MyTank = GetControlledTank();
	if (!MyTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI: I do not possess a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I am AI and my tank is %s"), *MyTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}