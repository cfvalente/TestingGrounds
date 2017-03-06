// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "PatrolAIController.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrolAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	
};
