// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WorldUserWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"

void UWorldUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!IsValid(AttachedActor))
	{
		RemoveFromParent();
		return;
	}
	
	FVector2D ScreenPos;
	FVector WorldPos = AttachedActor->GetActorLocation() + WorldOffsetLocation;
	if (UGameplayStatics::ProjectWorldToScreen(GetOwningPlayer(), WorldPos, ScreenPos))
	{
		float Scale = UWidgetLayoutLibrary::GetViewportScale(this);
		// ScreenPos = ScreenPos/Scale;
		ScreenPos /= Scale;
		if (ParentSizeBox)
		{
			ParentSizeBox->SetRenderTranslation(ScreenPos);
		}
	}
}
