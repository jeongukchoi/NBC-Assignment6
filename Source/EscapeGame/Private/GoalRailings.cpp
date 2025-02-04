

#include "GoalRailings.h"
#include "SpartaCharacter.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/GameModeBase.h"

AGoalRailings::AGoalRailings()
{
	GoalLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("GoalStaticMesh"));
	GoalLight->SetupAttachment(RootComp);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComp);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AGoalRailings::OnOverlapBegin);
}

void AGoalRailings::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ASpartaCharacter* SpartaCharacter = Cast<ASpartaCharacter>(OtherActor))
	{
		FVector PlayerStartLocation = GetWorld()->GetAuthGameMode()->FindPlayerStart(SpartaCharacter->GetController())->GetActorLocation();
		SpartaCharacter->SetActorLocation(PlayerStartLocation);
	}
}

void AGoalRailings::BeginPlay()
{
	Super::BeginPlay();
	RotateSpeed *= -1;

	GoalLight->AddLocalOffset(FVector(0, 0, 50.f));
	CollisionBox->AddLocalOffset(FVector(0, 0, 50.f));
	CollisionBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));
}