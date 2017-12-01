// Copyright Rafal Boguszewski 2017, Course content by Ben Tristem  

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "OpenSesame.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenSesameEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenSesame : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenSesame();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FOpenSesameEvent OnOpenSesame;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* BullsEye;
	
};
