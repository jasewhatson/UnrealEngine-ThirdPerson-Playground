// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShockwaveActor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/OverlapResult.h"


// Sets default values
AMyShockwaveActor::AMyShockwaveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    // Add this line to allow the actor to be moved to your feet
    RootComponent->SetMobility(EComponentMobility::Movable);

}

// Called when the game starts or when spawned
void AMyShockwaveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyShockwaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyShockwaveActor::TriggerExplosion()
{
    // Fetch the current location of THIS specific spawned actor
    FVector ExplodeLocation = GetActorLocation();

    // DEBUG: Add this to see exactly where the code thinks the explosion is
   // DrawDebugSphere(GetWorld(), ExplodeLocation, ExplosionRadius, 12, FColor::Red, false, 5.f);

    TArray<FOverlapResult> OutHits;
    FCollisionShape MyColShape = FCollisionShape::MakeSphere(ExplosionRadius);

    if (GetWorld()->OverlapMultiByChannel(OutHits, ExplodeLocation, FQuat::Identity, ECC_WorldDynamic, MyColShape))
    {
        for (auto& Hit : OutHits)
        {
            UPrimitiveComponent* Mesh = Hit.GetComponent();
            if (Mesh && Mesh->IsSimulatingPhysics())
            {
                Mesh->WakeRigidBody();
                Mesh->AddRadialImpulse(ExplodeLocation, ExplosionRadius, ExplosionStrength, ERadialImpulseFalloff::RIF_Linear, true);
            }
        }
    }
    this->Destroy();
}
//void AMyShockwaveActor::TriggerExplosion()
//{
//    FVector ExplodeLocation = GetActorLocation(); // Ensure it uses ITS OWN location
//    TArray<FOverlapResult> OutHits;
//    FCollisionShape MyColShape = FCollisionShape::MakeSphere(ExplosionRadius);
//
//    if (GetWorld()->OverlapMultiByChannel(OutHits, ExplodeLocation, FQuat::Identity, ECC_WorldDynamic, MyColShape))
//    {
//        for (auto& Hit : OutHits)
//        {
//            UPrimitiveComponent* Mesh = Hit.GetComponent();
//            if (Mesh && Mesh->IsSimulatingPhysics())
//            {
//                Mesh->WakeRigidBody(); // Wakes up the cube so it can move again
//                Mesh->AddRadialImpulse(ExplodeLocation, ExplosionRadius, ExplosionStrength, RIF_Linear, true);
//            }
//        }
//    }
//
//    // This is the most important line for re-triggering!
//    this->Destroy(); // Delete this spawn so the next "I" press makes a fresh one
//}

//void AMyShockwaveActor::TriggerExplosion()
//{
//    // Play a sound and spawn an emitter (visuals)
//    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), nullptr, GetActorLocation()); // Replace nullptr with a particle if you have one
//
//    // Create the physical force
//    FVector ExplodeLocation = GetActorLocation();
//    TArray<AActor*> IgnoredActors;
//
//    // This helper function applies "Radial Impulse" to all physics objects nearby
//    UGameplayStatics::ApplyRadialDamage(GetWorld(), 0.f, ExplodeLocation, ExplosionRadius, nullptr, IgnoredActors, this, nullptr, false);
//
//    // To actually "push" things physically:
//    TArray<FHitResult> OutHits;
//    FCollisionShape MyColSphere = FCollisionShape::MakeSphere(ExplosionRadius);
//
//    if (GetWorld()->SweepMultiByChannel(OutHits, ExplodeLocation, ExplodeLocation, FQuat::Identity, ECC_WorldDynamic, MyColSphere))
//    {
//        for (auto& Hit : OutHits)
//        {
//            UPrimitiveComponent* Mesh = Hit.GetComponent();
//            if (Mesh && Mesh->IsSimulatingPhysics())
//            {
//                Mesh->AddRadialImpulse(ExplodeLocation, ExplosionRadius, ExplosionStrength, ERadialImpulseFalloff::RIF_Linear, true);
//            }
//        }
//    }
//
//    this->Destroy();
//}

