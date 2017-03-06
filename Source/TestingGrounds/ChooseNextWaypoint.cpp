// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	int32 NextWaypointIndex = -1;
	int32 NumberOfWaypoints = -1;
	AActor *Waypoint = nullptr;
	AAIController *AIController = OwnerComp.GetAIOwner();
	APawn *Self = AIController->GetControlledPawn();
	UPatrolRoute *PatrolRoute = nullptr;
	PatrolRoute = Self->FindComponentByClass<UPatrolRoute>();
	if (!PatrolRoute) return EBTNodeResult::Aborted;

	UBlackboardComponent *BlackboardComp = OwnerComp.GetBlackboardComponent();
	NextWaypointIndex = BlackboardComp->GetValueAsInt(NextWaypointIndexKey.SelectedKeyName);
	NumberOfWaypoints = BlackboardComp->GetValueAsInt(NumberOfWaypointsKey.SelectedKeyName);

	TArray<AActor *> PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (NumberOfWaypoints == 0) Waypoint = nullptr;
	else
	{
		Waypoint = PatrolPoints[NextWaypointIndex];
		NextWaypointIndex = (NextWaypointIndex + 1) % NumberOfWaypoints;
	}

	BlackboardComp->SetValueAsInt(NextWaypointIndexKey.SelectedKeyName, NextWaypointIndex);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoint);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %d"), NextWaypointIndex);
	return EBTNodeResult::Succeeded;
}
