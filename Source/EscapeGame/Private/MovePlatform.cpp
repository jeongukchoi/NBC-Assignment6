// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"

AMovePlatform::AMovePlatform()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/EngineHall/StaticMeshes/SM_Floor_4x4.SM_Floor_4x4"));
	StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
}
