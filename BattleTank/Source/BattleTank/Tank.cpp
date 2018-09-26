// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"


void ATank::Fire()
{
	if (!ensure(TankAimingComponent)) { return; }

	bool bReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (TankAimingComponent->GetBarrel() && bReloaded)
	{
		auto SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			TankAimingComponent->GetBarrel()->GetSocketLocation(FName("ProjectileSocket")),
			TankAimingComponent->GetBarrel()->GetSocketRotation(FName("ProjectileSocket"))
			);
		SpawnedProjectile->Launch(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


