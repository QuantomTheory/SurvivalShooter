// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_StopAttacking.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BaseEnemyController.h"
#include "BaseEnemy.h"

UBTService_StopAttacking::UBTService_StopAttacking()
{
	NodeName = TEXT("Stop Attacking");
}

// A Behavior Tree Service to stop the Enemy attack once out of Range of Target.
void UBTService_StopAttacking::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ABaseEnemyController* OwnerController = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner());
	if (OwnerController == nullptr) return;

	ABaseEnemy* EnemyPawn = Cast<ABaseEnemy>(OwnerController->GetPawn());
	if (EnemyPawn == nullptr) return;

	EnemyPawn->SetIsAttacking(false);
}

