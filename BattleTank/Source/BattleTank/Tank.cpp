// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"

#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"


void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool bReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && bReloaded)
	{
		auto SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("ProjectileSocket")),
			Barrel->GetSocketRotation(FName("ProjectileSocket"))
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




