#include "RotateRailings.h"

ARotateRailings::ARotateRailings()
{
	PrimaryActorTick.bCanEverTick = true;

	// Setup root component
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	// Setup static mesh component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComp);

	// Apply static mesh
	ConstructorHelpers::FObjectFinder<UStaticMesh>
		StaticMeshAsset(TEXT("/Game/EngineHall/StaticMeshes/SM_railings_crossing.SM_railings_crossing"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
	}

	StartLocation = FVector(0);
	StartRotation = FRotator(0);
	RotateSpeed = 45.f;
	RotateAxis = EAxisType::Z;
	ShouldRandomize = false;
}

void ARotateRailings::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	StartRotation = GetActorRotation();

	SetActorRotation(StartRotation);
	SetActorLocation(StartLocation);

	if (ShouldRandomize)
	{
		RotateSpeed = FMath::RandRange(45.f, 75.f);
		RotateAxis = static_cast<EAxisType>(FMath::RandRange(0, 2));
	}
}

void ARotateRailings::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (RotateAxis) {
	case EAxisType::X:
		AddActorLocalRotation(FRotator(0, 0, RotateSpeed * DeltaTime));
		break;

	case EAxisType::Y:

		AddActorLocalRotation(FRotator(RotateSpeed * DeltaTime, 0, 0));
		break;

	case EAxisType::Z:
		AddActorLocalRotation(FRotator(0, RotateSpeed * DeltaTime, 0));
		break;
	}
}

FVector ARotateRailings::GetSize()
{
	FVector Size = FVector::ZeroVector;
	if (StaticMesh)
	{
		if (StaticMesh->GetStaticMesh())
		{
			Size = StaticMesh->GetStaticMesh()->GetBounds().GetBox().GetSize();
		}
	}
	return Size;
}

