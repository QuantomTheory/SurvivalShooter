// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_PickUpComponent.h"
#include "Gun.h"
#include "BasePickup.h"

/* Modified from the automatically created class from the UE5 First Person Game Template */

UTP_PickUpComponent::UTP_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTP_PickUpComponent::EnablePickup()
{
	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTP_PickUpComponent::OnSphereBeginOverlap);
}

void UTP_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	EnablePickup();
}

void UTP_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	APlayerCharacter* Character = Cast<APlayerCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Attach the Owner Gun to the Actor
		ABasePickup* OwnerPickup = Cast<ABasePickup>(GetOwner());
		if (OwnerPickup != nullptr)
		{
			OwnerPickup->ApplyUpdate(Character);
			OwnerPickup->BeginRespawn();
		}
	}
}
