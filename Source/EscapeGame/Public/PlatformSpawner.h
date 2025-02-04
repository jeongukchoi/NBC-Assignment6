

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class ESCAPEGAME_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformSpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	USceneComponent* RootComp;

	UFUNCTION()
	void SpawnPlatforms();


public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class UBoxComponent* SpawnVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FRotator SpawnRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	int SpawnMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float SpawnOffsetX;


};
