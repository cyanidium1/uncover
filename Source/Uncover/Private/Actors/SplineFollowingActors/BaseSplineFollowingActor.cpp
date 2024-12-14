// The use of the project for commercial purposes is partially allowed. Distribution of project files is PROHIBITED. The ban does not apply to packaged versions that have encrypted files. One of the formats allowed for distribution is the game in the form of an .exe file.


#include "Actors/SplineFollowingActors/BaseSplineFollowingActor.h"
#include "Components/SplineComponent.h"

ABaseSplineFollowingActor::ABaseSplineFollowingActor()
{
    ActorPathSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("ActorPath"));
    ActorPathSplineComponent->SetupAttachment(RootComponent);
}

void ABaseSplineFollowingActor::BeginPlay()
{
    Super::BeginPlay();

    
}

void ABaseSplineFollowingActor::Tick(float DeltaTime)
{
    DistanceAlongSpline += ActorSpeed * DeltaTime;

    FTransform ActorMeshTransformAlongSpline = ActorPathSplineComponent->GetTransformAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::Local);
    BaseMeshComponent->SetRelativeTransform(ActorMeshTransformAlongSpline);

}