// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0, NewElevation, 0));
}


