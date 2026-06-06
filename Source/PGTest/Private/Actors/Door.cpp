// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/Door.h"

#include "Net/UnrealNetwork.h"


// Sets default values
ADoor::ADoor()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	DoorMesh->SetupAttachment(BaseMesh);
}

void ADoor::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADoor, bDoorOpened);
}

void ADoor::OnRep_DoorOpened()
{
	UpdateDoor();
}

float ADoor::GetCurrentDoorYaw() const
{
	return bDoorOpened ? TargetYaw : 0.0f;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::UpdateDoor_Implementation()
{
	bDoorOpened = !bDoorOpened;
}

