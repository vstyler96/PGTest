// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameplayInterface.h"
#include "KeyItem.generated.h"

UCLASS()
class PGTEST_API AKeyItem : public AActor, public IGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKeyItem();

	// Al interactuar, le da la llave al jugador (bHasKey = true) y se quita del mundo
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
};
