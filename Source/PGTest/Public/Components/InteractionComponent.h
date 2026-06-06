// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PGTEST_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractionComponent();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	void FindBestInteractable();
	
	FTimerHandle InteractionTraceTimerHandle;
	
	UFUNCTION(Server, Reliable)
	void ServerUpdateFocusActor(AActor* HitActor);

public:
	
	void PrimaryInteract();
	
	UPROPERTY(EditAnywhere)
	bool bShowDebug;
	
	UPROPERTY(Replicated)
	TObjectPtr<AActor> FocusActor;
};
