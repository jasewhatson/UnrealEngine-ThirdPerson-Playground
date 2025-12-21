// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonGameMode.h"
#include <Kismet/GameplayStatics.h>

AThirdPersonGameMode::AThirdPersonGameMode()
{
	// stub
}

void AThirdPersonGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Call SpawnEnemy every 5 seconds, starting 2 seconds after game start
    FTimerHandle SpawnHandle;
    GetWorldTimerManager().SetTimer(SpawnHandle, this, &AThirdPersonGameMode::SpawnEnemy, 5.0f, true, 2.0f);

}

//void AThirdPersonGameMode::SpawnEnemy()
//{
//    if (SparrowClass)
//    {
//        // Generate a random spot within 1000 units of the center
//        FVector RandomLoc = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 200.0f);
//        GetWorld()->SpawnActor<ASparrowEnemy>(SparrowClass, RandomLoc, FRotator::ZeroRotator);
//    }
//}

//void AThirdPersonGameMode::SpawnEnemy()
//{
//    // 1. Get all existing Sparrow actors in the world
//    TArray<AActor*> FoundEnemies;
//    UGameplayStatics::GetAllActorsOfClass(GetWorld(), SparrowClass, FoundEnemies);
//
//    // 2. Only spawn if we have fewer than 5
//    if (SparrowClass && FoundEnemies.Num() < 5)
//    {
//        FVector RandomLoc = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 200.0f);
//        GetWorld()->SpawnActor<ASparrowEnemy>(SparrowClass, RandomLoc, FRotator::ZeroRotator);
//    }
//}

void AThirdPersonGameMode::SpawnEnemy()
{
    // 1. Get all existing Sparrow actors in the world
    TArray<AActor*> FoundEnemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), SparrowClass, FoundEnemies);

    // 2. Only spawn if we have fewer than 5
    if (SparrowClass && FoundEnemies.Num() < 5)
    {
        // Increase Z slightly to 300.0f to give them room to fall to the floor
        FVector RandomLoc = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 300.0f);

        // 3. Setup Spawn Parameters to ignore collisions
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        // 4. Spawn using the parameters
        GetWorld()->SpawnActor<ASparrowEnemy>(SparrowClass, RandomLoc, FRotator::ZeroRotator, SpawnParams);
    }
}