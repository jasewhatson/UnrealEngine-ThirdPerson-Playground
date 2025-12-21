// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ASparrowEnemy.h" // Add this include
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ThirdPersonGameMode.generated.h"


// Change this line: remove (abstract)
UCLASS()
class AThirdPersonGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AThirdPersonGameMode();

protected:
    // This looks great!
    UPROPERTY(EditAnywhere, Category = "Combat")
    TSubclassOf<ASparrowEnemy> SparrowClass;

    virtual void BeginPlay() override;

    void SpawnEnemy();
};



