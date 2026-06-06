// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class PGTEST_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.0f;
	
	UPROPERTY(ReplicatedUsing=OnRep_DoorOpened, EditDefaultsOnly)
	bool bDoorOpened;
	
	UFUNCTION()
	void OnRep_DoorOpened();
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentDoorYaw() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> DoorMesh;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Exec, Category="Interactable")
	void UpdateDoor();
};
