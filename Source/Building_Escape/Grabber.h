// Copyright Ivan Chesnokov 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Return Line Trace End
	FVector GetPlayersReach() const;

	// Get Players position in the World
	FVector GetPlayersWorldPos() const;


	// Return the 1st Actor within reach with physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	int32 Reach;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UPhysicsHandleComponent* PhysicsHandle;
	UPROPERTY()
	class UInputComponent* InputComponent;
};
