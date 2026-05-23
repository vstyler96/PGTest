// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/ChestItem.h"

#include "Net/UnrealNetwork.h"


// Sets default values
AChestItem::AChestItem()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
}

void AChestItem::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AChestItem, bLidOpened);
}

void AChestItem::OnRep_LidOpened()
{
	UpdateLidChest();
}

float AChestItem::GetCurrentLidPitch() const
{
	return bLidOpened ? TargetPitch : 0.0f;
}

void AChestItem::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);

	if (!bCanUpdate) return;
	bLidOpened = !bLidOpened;
	UpdateLidChest();
}

// Called when the game starts or when spawned
void AChestItem::BeginPlay()
{
	Super::BeginPlay();
}

void AChestItem::UpdateLidChest_Implementation()
{
	
}