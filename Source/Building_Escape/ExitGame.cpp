// Copyright Ivan Chesnokov 2020


#include "ExitGame.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AExitGame::AExitGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	RootComponent = TriggerBox;
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	ExitSwitch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Exit Switch"));
	ExitSwitch->SetupAttachment(RootComponent);

	ExitTime = 3.f;
}

// Called when the game starts or when spawned
void AExitGame::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AExitGame::OnOverlapBegin);
}

// Called every frame
void AExitGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExitGame::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GetWorldTimerManager().SetTimer(SwitchHandle, this, &AExitGame::QuitGame, ExitTime);
}

void AExitGame::QuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(this, 0), EQuitPreference::Quit, false);
}