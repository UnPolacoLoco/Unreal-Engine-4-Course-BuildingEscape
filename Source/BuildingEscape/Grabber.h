// Copyright Rafal Boguszewski 2017, Course content by Ben Tristem  

#pragma once

#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;



private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;

	float ThrowStrenght = 10000.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	AActor* ActorHit = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();

	// Throw currently held PhysicsBody
	void Throw();

	// Called when grab is released
	void Release();

	// Find (assumed) attached phyics handle
	void FindPhysicsHandleComponent();

	// Setup (assumed) attached input component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetReachLineStart();

	FVector GetPlayerViewPointRotation();

	// Returns current end of reach line
	FVector GetReachLineEnd();
};
