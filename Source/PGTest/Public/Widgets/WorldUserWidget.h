// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "WorldUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PGTEST_API UWorldUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<USizeBox> ParentSizeBox;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="World User Widget")
	FVector WorldOffsetLocation;
	
public:
	UPROPERTY(BlueprintReadOnly, Category="World User Widget")
	TObjectPtr<AActor> AttachedActor;
};
