// Fill out your copyright notice in the Description page of Project Settings.


#include "ASparrowEnemy.h"

// Sets default values
ASparrowEnemy::ASparrowEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
//void ASparrowEnemy::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
void ASparrowEnemy::BeginPlay()
{
    Super::BeginPlay();

    // Shoot every 3 seconds
    FTimerHandle ShootHandle;
    GetWorldTimerManager().SetTimer(ShootHandle, this, &ASparrowEnemy::ShootAtPlayer, 3.0f, true);
}


// Called every frame
void ASparrowEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASparrowEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void ASparrowEnemy::ShootAtPlayer()
//{
//    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//    if (PlayerPawn && ProjectileClass)
//    {
//        FVector SpawnLoc = GetMesh()->GetSocketLocation("Muzzle_01"); // Sparrow's bow socket
//        FRotator SpawnRot = (PlayerPawn->GetActorLocation() - SpawnLoc).Rotation();
//
//        GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLoc, SpawnRot);
//    }
//}

//void ASparrowEnemy::ShootAtPlayer()
//{
//    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//    if (PlayerPawn && ProjectileClass)
//    {
//        FVector SpawnLoc = GetMesh()->GetSocketLocation("Muzzle_01");
//        FRotator SpawnRot = (PlayerPawn->GetActorLocation() - SpawnLoc).Rotation();
//
//        FActorSpawnParameters SpawnParams;
//        SpawnParams.Owner = this;
//        SpawnParams.Instigator = GetInstigator();
//        // This ensures the arrow doesn't collide with the shooter
//        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//
//        GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLoc, SpawnRot, SpawnParams);
//    }
//}

void ASparrowEnemy::ShootAtPlayer()
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (PlayerPawn && ProjectileClass)
    {
        FVector SpawnLoc = GetMesh()->GetSocketLocation("Muzzle_01");
        FRotator SpawnRot = (PlayerPawn->GetActorLocation() - SpawnLoc).Rotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this; // Set the Sparrow as the owner
        SpawnParams.Instigator = GetInstigator();
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AActor* NewArrow = GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLoc, SpawnRot, SpawnParams);

        if (NewArrow)
        {
            // 1. Get the Primitive Component (the collision)
            UPrimitiveComponent* RootPrim = Cast<UPrimitiveComponent>(NewArrow->GetRootComponent());

            if (RootPrim)
            {
                // 2. Use this specific function to ignore the Sparrow
                RootPrim->IgnoreActorWhenMoving(this, true);
            }

            // 3. Set a lifespan so the world doesn't fill up with arrows
            NewArrow->SetLifeSpan(5.0f);
        }
    }
}
