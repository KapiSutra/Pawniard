// Copyright 2019-Present tarnishablec. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MoverSimulationTypes.h"
#include "Components/ActorComponent.h"
#include "PMoverInputFactoryComponent.generated.h"


UCLASS(ClassGroup=(Pawniard), meta=(BlueprintSpawnableComponent, ToolTip="Should Add to Controller"), DisplayName="Mover Input Factory")
class PAWNIARD_API UPMoverInputFactoryComponent : public UActorComponent, public IMoverInputProducerInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UPMoverInputFactoryComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    virtual void ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& InputCmdResult) override;

protected:
    UFUNCTION()
    void HandleOwnerPawnChanged(APawn* OldPawn, APawn* NewPawn);
};
