// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxTrackDrivingForce = 40000000;
	float TrackForcePitch = 0.01;

private:
	UTankTrack();
	virtual void BeginPlay() override;
	
	void DriveTank();
	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;
};
