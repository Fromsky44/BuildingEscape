// Copyright Ivan Chesnokov 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();

	UPROPERTY(BlueprintReadOnly)
	bool OpenDoorSound;
	UPROPERTY(BlueprintReadOnly)
	bool CloseDoorSound;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle;

	float InitialYaw;
	float CurrentYaw;

	float DoorLastOpened;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed;
	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed;
	
	UPROPERTY(EditAnywhere)
	class ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoor;

	UPROPERTY(EditAnywhere)
	class UAudioComponent* AudioComponent;
};
