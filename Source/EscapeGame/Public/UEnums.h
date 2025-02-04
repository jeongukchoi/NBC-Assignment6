#pragma once

#include "CoreMinimal.h"


class ESCAPEGAME_API UEnums
{
public:
	UEnums();
	~UEnums();
};

UENUM(BlueprintType)
enum class EAxisType : uint8 {
	X,
	Y,
	Z
};
