// Copyright Ben Tristem 2016.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "TrapDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTrapDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTrapDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrapDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FTrapDoorEvent OnOpenTrapDoor;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TrapDoorTrigger = nullptr;

	void OpenTrapDoor();
	
};
