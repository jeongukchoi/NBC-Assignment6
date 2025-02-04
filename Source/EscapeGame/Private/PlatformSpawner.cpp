

#include "PlatformSpawner.h"
#include "Components/BoxComponent.h"
#include "MoveRailings.h"
#include "RotateRailings.h"

APlatformSpawner::APlatformSpawner()
{
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);;

	SpawnLocation = FVector(0);
	SpawnRotation = FRotator(0);
	SpawnMax = 4;
	SpawnOffsetX = 0.f;
}

void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnLocation = GetActorLocation();
	SpawnRotation = GetActorRotation();

	SetActorRotation(SpawnRotation);
	SetActorLocation(SpawnLocation);
	SpawnPlatforms();
}

void APlatformSpawner::SpawnPlatforms()
{
	for (int SpawnCount = 0; SpawnCount < SpawnMax; SpawnCount++)
	{
		
		if (FMath::RandRange(0, 1))
		{
			AMoveRailings* SpawnedPlatform = GetWorld()->SpawnActor<AMoveRailings>(SpawnLocation, SpawnRotation);
			SpawnOffsetX = SpawnedPlatform->GetSize().X;
		}
		else
		{
			ARotateRailings* SpawnedPlatform = GetWorld()->SpawnActor<ARotateRailings>(SpawnLocation, SpawnRotation);
			SpawnOffsetX = SpawnedPlatform->GetSize().X;
		}

		SpawnLocation.X += SpawnOffsetX;
		SpawnLocation.Y += FMath::RandRange(-150, 150);
		SpawnLocation.Z += FMath::RandRange(-100, 100);
	}
}

