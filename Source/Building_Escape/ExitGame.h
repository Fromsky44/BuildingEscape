// Copyright Ivan Chesnokov 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitGame.generated.h"

UCLASS()
class BUILDING_ESCAPE_API AExitGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExitGame();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exit Game")
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exit Game")
	class UStaticMeshComponent* ExitSwitch;

	float ExitTime;
	FTimerHandle SwitchHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void QuitGame();

};
