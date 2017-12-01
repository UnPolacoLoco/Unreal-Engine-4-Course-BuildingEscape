// Copyright Ben Tristem 2016.

#include "BuildingEscape.h"
#include "TrapDoor.h"


// Sets default values for this component's properties
UTrapDoor::UTrapDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTrapDoor::BeginPlay()
{
	Super::BeginPlay();

	if (!TrapDoorTrigger)
	{
		UE_LOG(LogTemp, Error, TEXT("Trap Door Trigger Volume not attached to %s"), *GetOwner()->GetName());
	}

	// ...
	
}


// Called every frame
void UTrapDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	TArray<AActor*> ActorsOnPinTrigger;

	float TotalMass = 0.f;

	if (!TrapDoorTrigger) { return; }

	TrapDoorTrigger->GetOverlappingActors(OUT ActorsOnPinTrigger);

	for (auto* Pin : ActorsOnPinTrigger)
	{
		TotalMass += Pin->FindComponentByClass<UPrimitiveComponent>()->GetMass();

	}

	if (TotalMass < 1.0f)
	{
		//GetOwner()->SetActorRotation(FRotator(50.f, 0.f, 0.f));
		OpenTrapDoor();
		
	}

	// ...
}

void UTrapDoor::OpenTrapDoor()
{
	OnOpenTrapDoor.Broadcast();
}

