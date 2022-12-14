// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerSpawn.generated.h"

UCLASS()
class MYDOOMLIKE_API APlayerSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void SpawnPlayer();

private:
	UPROPERTY()
		class AHoardSurvivalGameMode* GameMode;

	// ACTOR COMPONENTS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mechanics", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* SpawnerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mechanics", meta = (AllowPrivateAccess = "true"))
		USceneComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visuals", meta = (AllowPrivateAccess = "true"))
		class UParticleSystem* SpawnEffect;

	// The Class of the melee character to be spawned
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mechanics", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class APlayerCharacter> SpawningCharacter;
};
