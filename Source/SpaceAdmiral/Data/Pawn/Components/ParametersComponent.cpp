// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceAdmiral.h"
#include "ParametersComponent.h"

UParametersComponent::UParametersComponent()
{
	/*default*/
	Level = 1;
	Experience = 0;

	CalculateExperienceTheNextLvl();

}

void UParametersComponent::LevelUp(int32 Value)
{
	if (Value > 0)
	{
		Level += Value;
	}
}

bool UParametersComponent::AddExperience(int32 vExperience)
{
	bool ReturnValue = false;

	if (vExperience > 0)
	{
		Experience += vExperience;
	}

	
	while (CheckNewLevel() )
	{
		LevelUp(1);
		CalculateExperienceTheNextLvl();

		ReturnValue = true;
	}

	return ReturnValue;
}

bool UParametersComponent::CheckNewLevel()
{ 
	if (Experience >= ExperienceTheNextLvl)
	{
		return true;
	}


	return false;
}

void UParametersComponent::CalculateExperienceTheNextLvl()
{
	ExperienceTheNextLvl = ExperienceTheNextLvl + (Level * Level * 100);
}

