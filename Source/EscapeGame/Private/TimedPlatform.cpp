#include "TimedPlatform.h"

ATimedPlatform::ATimedPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh> 
		StaticMeshAsset(TEXT("/Game/EngineHall/StaticMeshes/SM_Trail_02.SM_Trail_02"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
	}

	bCollision = true;
	ConstructorHelpers::FObjectFinder<UMaterialInstance> NoMaterialAsset(TEXT("/Game/EngineHall/Materials/Instances/MI_railings1.MI_railings1"));
	ConstructorHelpers::FObjectFinder<UMaterialInstance> YesMaterialAsset(TEXT("/Game/EngineHall/Materials/Instances/MI_railings2.MI_railings2"));
	if (NoMaterialAsset.Succeeded())
	{
		NoCollisionMaterial = NoMaterialAsset.Object;
	}
	if (YesMaterialAsset.Succeeded())
	{
		YesCollisionMaterial = YesMaterialAsset.Object;
	}
	
	StartLocation = FVector(0);
	StartRotation = FRotator(0);
	Duration = 2.f;
	FirstDelay = 2.f;
}

void ATimedPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	StartRotation = GetActorRotation();

	SetActorRotation(StartRotation);
	SetActorLocation(StartLocation);

	GetWorld()->GetTimerManager().SetTimer(PlatformTimerHandle, this, &ATimedPlatform::ToggleCollision, Duration, true, FirstDelay);
}

void ATimedPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimedPlatform::ToggleCollision()
{
	StaticMesh->SetMaterial(0, bCollision ? NoCollisionMaterial : YesCollisionMaterial);
	bCollision = !bCollision;
	SetActorEnableCollision(bCollision);
}