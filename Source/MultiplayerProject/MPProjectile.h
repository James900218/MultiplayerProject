// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MPProjectile.generated.h"

UCLASS()
class MULTIPLAYERPROJECT_API AMPProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMPProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// sphere component for collision detection
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* sphereComponent;

	// sphere Radius
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	float sphereRadius;

	// static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* staticMeshComponent;

	// movement component for the projectile
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* projectileMoveComponent;

	// for explosion particle effects
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* particleEffect;

	// damage type
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TSubclassOf<class UDamageType> damageType;

	// how much damage to be dealt to target
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float damageValue;
};
