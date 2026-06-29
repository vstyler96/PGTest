// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/WallLever.h"

#include "Interfaces/GameplayInterface.h"
#include "Net/UnrealNetwork.h"
#include "PGTestCharacter.h"


// Sets default values
AWallLever::AWallLever()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeverMesh");
	LeverMesh->SetupAttachment(BaseMesh);
}

void AWallLever::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWallLever, bLeverOn);
}

void AWallLever::OnRep_LeverOn()
{
	UpdateLever();
}

float AWallLever::GetCurrentLeverPitch() const
{
	return bLeverOn ? TargetPitch : 140.0f;
}

void AWallLever::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);

	if (!bCanUpdate) return;

	// Validación: si la palanca requiere llave, el pawn que interactúa debe tenerla
	if (bRequiresKey)
	{
		APGTestCharacter* Character = Cast<APGTestCharacter>(InstigatorPawn);
		if (!Character || !Character->bHasKey)
		{
			// Sin llave: no se acciona (acá podés disparar feedback de "necesitás la llave")
			return;
		}
	}

	bLeverOn = !bLeverOn;
	UpdateLever();
}

// Called when the game starts or when spawned
void AWallLever::BeginPlay()
{
	Super::BeginPlay();
}

void AWallLever::UpdateLever_Implementation()
{

}
