// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Widgets/WorldUserWidget.h"
#include "InteractionComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PGTEST_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	// Sets default values for this component's properties
	UInteractionComponent();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts
	
	void FindBestInteractable();
	
	FTimerHandle InteractionTraceTimerHandle;
	
	UFUNCTION(Server, Reliable)
	void ServerUpdateFocusActor(AActor* HitActor);
	
	// Widget
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UWorldUserWidget> DefaultWidgetClass;
	
	UPROPERTY(BlueprintReadOnly, Category="UI")
	TObjectPtr<UWorldUserWidget> DefaultWidgetInteraction;

public:
	
	void PrimaryInteract();
	
	UPROPERTY(EditAnywhere)
	bool bShowDebug;
	
	UPROPERTY(Replicated)
	TObjectPtr<AActor> FocusActor;
};
