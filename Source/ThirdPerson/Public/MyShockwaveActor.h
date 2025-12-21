// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyShockwaveActor.generated.h"

UCLASS()
class THIRDPERSON_API AMyShockwaveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyShockwaveActor();

	// This allows us to call the function from the Player character later
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void TriggerExplosion();

	UPROPERTY(EditAnywhere, Category = "Abilities")
	float ExplosionRadius = 500.f;

	UPROPERTY(EditAnywhere, Category = "Abilities")
	float ExplosionStrength = 4000.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
