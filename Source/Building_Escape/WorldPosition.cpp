// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("This is Warning!"));
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("This is owner name: %s"), *ObjectName);
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	float X = GetOwner()->GetActorLocation().X;
	float Y = GetOwner()->GetActorLocation().Y;
	float Z = GetOwner()->GetActorLocation().Z;
	UE_LOG(LogTemp, Warning, TEXT("%s Location is X: %f, Y: %f, Z: %f"), *ObjectName, X, Y, Z);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

