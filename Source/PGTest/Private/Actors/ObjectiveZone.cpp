// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ObjectiveZone.h"

#include "PGTestCharacter.h"
#include "PGTestGameMode.h"
#include "Components/BoxComponent.h"


// Sets default values
AObjectiveZone::AObjectiveZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AObjectiveZone::HandleOverlap);
}

// Called when the game starts or when spawned
void AObjectiveZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveZone::HandleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APGTestCharacter* MyPawn = Cast<APGTestCharacter>(OtherActor);
	if (MyPawn == nullptr) return;
		
	APGTestGameMode* GM = Cast<APGTestGameMode>(GetWorld()->GetAuthGameMode());
	if (GM == nullptr) return;
		
	GM->CompleteMission(MyPawn);
}

// Called every frame
void AObjectiveZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

