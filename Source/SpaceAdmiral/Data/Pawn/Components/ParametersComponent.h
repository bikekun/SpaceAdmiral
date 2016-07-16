// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Data/Pawn/Components/HealthComponent.h"
#include "ParametersComponent.generated.h"

/**
 * 
 */
UCLASS()
class SPACEADMIRAL_API UParametersComponent : public UHealthComponent
{
	GENERATED_BODY()
	
public:

	/*my level*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 Level;

	/*Start Experience*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 Experience;

	/*Experience tp the next level = ExperienceTheNextLvl + (Level * Level * 100)*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Parameters)
	int32 ExperienceTheNextLvl;

	/*My statima*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 Statima;

	/*My max statima*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 MaxStatima;

	/*My  Thirst*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 Thirst;

	/*My  maxThirst*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int32 MaxThirst;
	

	
	

	/*add Experience and Check New Level. If LevelUp return true*/
	UFUNCTION(BlueprintCallable, Category = Parameters)
	bool AddExperience(int32 vExperience);

	/*Level up of value*/
	UFUNCTION(BlueprintCallable, Category = Parameters)
	void LevelUp(int32 Value);

	/*change Statima of Value*/
	/*UFUNCTION(BlueprintCallable, Category = Parameters)*/
	bool ÑhangeStatima(int32 Value);

	/*change Statima of Value*/
//	UFUNCTION()
	bool ÑhangeThirst(int32 Value);

private:

	bool CheckNewLevel();
	void CalculateExperienceTheNextLvl();

public:
	/*constructor*/
	UParametersComponent();

	/*Get my Level*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetLevel() { return Level; }

	/*Get my Experience*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetExperience() { return Experience; }

	/*Get experience to the next level*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetExperienceTheNextLvl() { return ExperienceTheNextLvl; }

	/*Get my Statima*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetStatima() { return Statima; }

	/*Get my max Statima*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetMaxStatima() { return MaxStatima; }

	/*Get my Thirst*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetThirst() { return Thirst; }

	/*Get my max Thirst*/
	UFUNCTION(BlueprintPure, Category = Parameters)
	int32 GetMaxThirst() { return MaxThirst; }
	
	
};
