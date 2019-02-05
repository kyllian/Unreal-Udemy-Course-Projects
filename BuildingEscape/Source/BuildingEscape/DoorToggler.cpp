// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorToggler.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UDoorToggler::UDoorToggler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UDoorToggler::BeginPlay()
{
	Owner = GetOwner();
	initialYaw = Owner->GetActorRotation().Yaw;

	Super::BeginPlay();

	Toggle();
}


// Called every frame
void UDoorToggler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UDoorToggler::Toggle()
{
	auto diff = Owner->GetActorRotation().Yaw == initialYaw ? -90 : 90;
	Owner->SetActorRotation(Owner->GetActorRotation().Add(0, diff, 0));
}

