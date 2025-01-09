#include "MyActor.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
}

// Called when the actor is spawned or the game starts
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // Start moving from the initial point
    Move();
}

// Generates a random step value of either 0 or 1
int AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

// Handles the movement logic and logs each position
void AMyActor::Move()
{
    FVector2D CurrentPosition = FVector2D(0, 0); // Starting at (0, 0)

    for (int i = 0; i < 10; ++i)
    {
        // Generate random steps for x and y coordinates
        int StepX = Step();
        int StepY = Step();

        // Update position
        CurrentPosition.X += StepX;
        CurrentPosition.Y += StepY;

        // Log the current position
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Position = (%d, %d)"), i + 1, (int)CurrentPosition.X, (int)CurrentPosition.Y);
    }
}
