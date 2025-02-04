

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEnums.h"
#include "RotateRailings.generated.h"

UCLASS()
class ESCAPEGAME_API ARotateRailings : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotateRailings();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMesh;
	

public:	
	virtual void Tick(float DeltaTime) override;

	virtual FVector GetSize();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Transform")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Transform")
	FRotator StartRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Movement")
	float RotateSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Movement")
	EAxisType RotateAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties|Movement")
	bool ShouldRandomize;
};
