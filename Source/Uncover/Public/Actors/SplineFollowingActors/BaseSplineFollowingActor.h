// The use of the project for commercial purposes is partially allowed. Distribution of project files is PROHIBITED. The ban does not apply to packaged versions that have encrypted files. One of the formats allowed for distribution is the game in the form of an .exe file.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "BaseSplineFollowingActor.generated.h"

/**
 * 
 */
UCLASS()
class UNCOVER_API ABaseSplineFollowingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:

	ABaseSplineFollowingActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class USplineComponent* ActorPathSplineComponent;

private:

	UPROPERTY(EditAnywhere)
	float ActorSpeed = 200;

	float DistanceAlongSpline;
};
