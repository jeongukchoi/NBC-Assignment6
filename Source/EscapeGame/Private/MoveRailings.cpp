#include "MoveRailings.h"

AMoveRailings::AMoveRailings()
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
		StaticMeshAsset(TEXT("/Game/EngineHall/StaticMeshes/SM_railings_straight.SM_railings_straight"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
	}

	StartLocation = FVector(0);
	StartRotation = FRotator(0, -90.f, 0);
	MoveSpeed = 200.f;
	MoveRange = 200.f;
	MoveAxis = EAxisType::Z;
	ShouldRandomize = false;
}

void AMoveRailings::BeginPlay()
{
	Super::BeginPlay();
	
	// Account for changes made in the editor
	StartLocation = GetActorLocation();
	StartRotation = GetActorRotation();
	
	SetActorRotation(StartRotation);
	SetActorLocation(StartLocation);

	if (ShouldRandomize)
	{
		MoveSpeed = FMath::RandRange(100.f, 200.f);
		MoveRange = FMath::RandRange(200.f, 400.f);
		// Movement along the Y-axis may cause overlap with other objects in the level
		if (FMath::RandRange(0, 1))
		{
			MoveAxis = EAxisType::Z;
		}
		else
		{
			MoveAxis = EAxisType::X;
		}
	}
}

void AMoveRailings::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (MoveAxis) {
	case EAxisType::X:
		if (abs(StartLocation.X - GetActorLocation().X) + abs(MoveSpeed * DeltaTime) > MoveRange) {
			MoveSpeed *= -1;
		}
		AddActorWorldOffset(FVector(MoveSpeed * DeltaTime, 0, 0));
		break;

	case EAxisType::Y:
		if (abs(StartLocation.Y - GetActorLocation().Y) + abs(MoveSpeed * DeltaTime) > MoveRange) {
			MoveSpeed *= -1;
		}
		AddActorWorldOffset(FVector(0, MoveSpeed * DeltaTime, 0));
		break;

	case EAxisType::Z:
		if (abs(StartLocation.Z - GetActorLocation().Z) + abs(MoveSpeed * DeltaTime) > MoveRange) {
			MoveSpeed *= -1;
		}
		AddActorWorldOffset(FVector(0, 0, MoveSpeed * DeltaTime));
		break;
	}
}

FVector AMoveRailings::GetSize()
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
