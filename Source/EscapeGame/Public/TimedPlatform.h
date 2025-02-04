

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimedPlatform.generated.h"

UCLASS()
class ESCAPEGAME_API ATimedPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimedPlatform();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Timed")
	UMaterialInstance* NoCollisionMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Timed")
	UMaterialInstance* YesCollisionMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties|Timed")
	bool bCollision;

	UPROPERTY()
	FTimerHandle PlatformTimerHandle;


public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Transform")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Transform")
	FRotator StartRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Timed")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Timed")
	float FirstDelay;

	UFUNCTION()
	void ToggleCollision();

};
