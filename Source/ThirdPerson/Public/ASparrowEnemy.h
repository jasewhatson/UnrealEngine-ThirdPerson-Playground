// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ASparrowEnemy.generated.h"

UCLASS()
class THIRDPERSON_API ASparrowEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    // FIXED: Removed the extra 'A' so it matches the class name
    ASparrowEnemy();

    UPROPERTY(EditAnywhere, Category = "Combat")
    TSubclassOf<class AActor> ProjectileClass;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void ShootAtPlayer(); // Add this line
};