// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, category = "Blackboard")
	struct FBlackboardKeySelector NextWaypointIndexKey;

	UPROPERTY(EditAnywhere, category = "Blackboard")
	struct FBlackboardKeySelector NumberOfWaypointsKey;

	UPROPERTY(EditAnywhere, category = "Blackboard")
	struct FBlackboardKeySelector WaypointKey;
	
};
