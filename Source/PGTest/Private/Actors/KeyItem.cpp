// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/KeyItem.h"

#include "PGTestCharacter.h"


// Sets default values
AKeyItem::AKeyItem()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	// Necesario para que el Destroy() en el servidor se replique a los clientes
	bReplicates = true;
}

void AKeyItem::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);

	APGTestCharacter* Character = Cast<APGTestCharacter>(InstigatorPawn);
	if (!Character) return;

	// Le damos la llave al jugador (corre en servidor y bHasKey está replicada)
	Character->bHasKey = true;

	// Quitamos la llave del mundo
	Destroy();
}
