// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHelloWorldActor.h"

// Sets default values
AMyHelloWorldActor::AMyHelloWorldActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyHelloWorldActor::BeginPlay()
{
	Super::BeginPlay();

	// Print Hello World to the Screen
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Hello World from C++! 5"));
	}
	
}

// Called every frame
void AMyHelloWorldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

