// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	MyTank = GetControlledTank();
	PlayerTank = GetPlayerTank();

	if (!MyTank)	 UE_LOG(LogTemp, Warning, TEXT("AI Controller does not possess a Tank"))
	if (!PlayerTank) UE_LOG(LogTemp, Warning, TEXT("Cannot find PlayerTank"))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MyTank && PlayerTank) {
		MyTank->AimAt(PlayerTank->GetActorLocation());
	}
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
