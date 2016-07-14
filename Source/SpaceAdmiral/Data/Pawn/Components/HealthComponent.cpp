// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceAdmiral.h"
#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// Значение HP по умолчанию
	BeginHealth = 100;
	BeginMaxHealth = 100;

	Health = 100;
	MaxHealth = 100;
}


//// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Health = BeginHealth;
	MaxHealth = BeginMaxHealth;
}
//
//
//// Called every frame
//void UHealthComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
//{
//	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
//
//	// ...
//}



bool UHealthComponent::AddHealth(float value)
{
	Health += value;

	Health = FMath::Min(Health, MaxHealth);
	Health = FMath::Max(0.0f, Health);

	if (!(CheckHealth() )) return false;	

	return true;
}

bool UHealthComponent::TakeHealth(float damage)
{
	if (!(AddHealth(-1 * damage))) return false;
	return true;
}