// Copyright 2019-Present tarnishablec. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MoverComponent.h"
#include "GameFramework/Pawn.h"
#include "PCharacter.generated.h"

class UPathFollowingComponent;
class UArrowComponent;
class UCapsuleComponent;
class UNavMoverComponent;

UCLASS(DisplayName="PCharacter (Pawniard)")
class PAWNIARD_API APCharacter : public APawn
{
	GENERATED_BODY()

public:
	APCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual FVector GetNavAgentLocation() const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_Controller() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> CollisionCapsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UArrowComponent> ArrowComponent;

	UPROPERTY(Category=Movement, VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UMoverComponent> MoverComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPathFollowingComponent> PathFollowingComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category=Movement)
	TObjectPtr<UNavMoverComponent> NavMoverComponent;
};
