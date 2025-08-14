// Fill out your copyright notice in the Description page of Project Settings.


#include "MPProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMPProjectile::AMPProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	sphereRadius = 37.5f;

	// init sphere component
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	sphereComponent->InitSphereRadius(sphereRadius);
	sphereComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = sphereComponent;

	// defining static mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultMesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	staticMeshComponent->SetupAttachment(RootComponent);

	//if mesh file is found
	if (DefaultMesh.Succeeded())
	{
		staticMeshComponent->SetStaticMesh(DefaultMesh.Object);
		staticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -37.5f));
		staticMeshComponent->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.75f));

	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> DefaultExplosionEffect(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));     
	if (DefaultExplosionEffect.Succeeded()) 
	{ 
		particleEffect = DefaultExplosionEffect.Object;
	}

	//Definition for the Projectile Movement Component.
	projectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	projectileMoveComponent->SetUpdatedComponent(sphereComponent);
	projectileMoveComponent->InitialSpeed = 1500.0f;
	projectileMoveComponent->MaxSpeed = 1500.0f;
	projectileMoveComponent->bRotationFollowsVelocity = true;
	projectileMoveComponent->ProjectileGravityScale = 0.0f;

	damageType = UDamageType::StaticClass();
	damageValue = 10.f;
}

// Called when the game starts or when spawned
void AMPProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMPProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

