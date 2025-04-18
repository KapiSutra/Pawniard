// Copyright 2019-Present tarnishablec. All Rights Reserved.


#include "PMoverInputFactoryComponent.h"

#include "MoverComponent.h"


// Sets default values for this component's properties
UPMoverInputFactoryComponent::UPMoverInputFactoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPMoverInputFactoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	const auto Controller = CastChecked<AController>(GetOwner());
	Controller->OnPossessedPawnChanged.AddUniqueDynamic(this, &ThisClass::HandleOwnerPawnChanged);
}

void UPMoverInputFactoryComponent::ProduceInput_Implementation(int32 SimTimeMs, FMoverInputCmdContext& InputCmdResult)
{
	
}

void UPMoverInputFactoryComponent::HandleOwnerPawnChanged(
	// ReSharper disable once CppParameterMayBeConstPtrOrRef
	APawn* OldPawn,
	// ReSharper disable once CppParameterMayBeConstPtrOrRef
	APawn* NewPawn)
{
	if (OldPawn)
	{
		auto* Mover = OldPawn->GetComponentByClass<UMoverComponent>();
		{
			if (Mover->InputProducer == this)
			{
				Mover->InputProducer = nullptr;
			}
		}
	}
	if (NewPawn)
	{
		auto* Mover = NewPawn->GetComponentByClass<UMoverComponent>();
		if (Mover)
		{
			Mover->InputProducer = this;
		}
	}
}
