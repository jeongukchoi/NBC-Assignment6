

#pragma once

#include "CoreMinimal.h"
#include "RotateRailings.h"
#include "GoalRailings.generated.h"


class UPointLightComponent;
class UBoxComponent;

UCLASS()
class ESCAPEGAME_API AGoalRailings : public ARotateRailings
{
	GENERATED_BODY()
	
public:
	AGoalRailings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UPointLightComponent* GoalLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UBoxComponent* CollisionBox;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	
	virtual void BeginPlay() override;
};
