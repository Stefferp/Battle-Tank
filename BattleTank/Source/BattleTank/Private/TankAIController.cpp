// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	MyTank = GetControlledTank();
	PlayerTank = GetPlayerTank();

	if (!MyTank)	 UE_LOG(LogTemp, Warning, TEXT("AI Controller does not possess a Tank"))
	if (!PlayerTank) UE_LOG(LogTemp, Warning, TEXT("Cannot find PlayerTank"))
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}
