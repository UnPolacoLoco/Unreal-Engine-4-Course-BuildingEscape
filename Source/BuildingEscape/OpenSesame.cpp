// Copyright Rafal Boguszewski 2017, Course content by Ben Tristem  

#include "BuildingEscape.h"
#include "OpenSesame.h"


// Sets default values for this component's properties
UOpenSesame::UOpenSesame()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenSesame::BeginPlay()
{
	Super::BeginPlay();

	if (!BullsEye)
	{
		UE_LOG(LogTemp, Error, TEXT("BullsEye Trigger not connected to %s"), *GetOwner()->GetName())
	}

	// ...
	
}


// Called every frame
void UOpenSesame::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<AActor*> ActorsHittingBullsEye;
	
	if (!BullsEye) { return; }
	
	BullsEye->GetOverlappingActors(ActorsHittingBullsEye);

	for (auto Balls : ActorsHittingBullsEye)
	{
		if (Balls->FindComponentByClass<UPrimitiveComponent>()->GetMass() > 4.f)
		{
			//UE_LOG(LogTemp, Warning, TEXT("BullsEye hit!"));

			//GetOwner()->SetActorLocation(FVector(-1470.0, 490.0, 281.0));

			OnOpenSesame.Broadcast();
		}
	}


	// ...
}

