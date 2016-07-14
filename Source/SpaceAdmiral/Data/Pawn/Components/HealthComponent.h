// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(DelegeteDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEADMIRAL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()


private:

	
	float Health;	
	float MaxHealth;

	bool CheckHealth() { if (Health <= 0) { DDeath.Broadcast(); return false; } else return true;
	
};


public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealth() { return Health; }
	UFUNCTION(BlueprintPure, Category = Health)
	float GetMaxHealth() { return MaxHealth; }

	UFUNCTION(BlueprintCallable, Category = Health)
	bool AddHealth(float value);
	UFUNCTION(BlueprintCallable, Category = Health)
	bool TakeHealth(float damage);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	float BeginHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	float BeginMaxHealth;

	


	

	/*Диспатч смерти*/
	DelegeteDeath DDeath;


	//// Called when the game starts
	virtual void BeginPlay() override;
	//
	//// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
