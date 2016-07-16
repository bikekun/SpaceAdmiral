// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceAdmiral.h"
#include "ParametersComponent.h"



UParametersComponent::UParametersComponent()
{
	/*default*/
	Level = 1;
	Experience = 0;
	Statima = MaxStatima = 100;

	ReStatima = 10;
	TimeRestoreStatime = 1;
	IsRestoreStatima = true;

	Thirst = 0;
	MaxThirst = 100;
	Hunger = 0;
	MaxHunger = 100;

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

bool UParametersComponent::CheckStatima()
{
	if (Statima < MaxStatima && IsRestoreStatima)
	{
		return true;
	}

	return false;
}




bool UParametersComponent::ChangeStatima(int32 Value)
{
	Statima = CalculateValue(Statima, Value, 0, MaxStatima);

	if (CheckStatima() )
	{
		//getworldrimermanager
		GetWorld()->GetTimerManager().SetTimer(CountupTimerStatima, this, &UParametersComponent::RestoreStatima, TimeRestoreStatime, true);
	}

	if (Statima <= 0)
		return true;

	return false;
}

void UParametersComponent::RestoreStatima()
{
	ChangeStatima(ReStatima);

	if (Statima >= MaxStatima)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountupTimerStatima);
	}
}

bool UParametersComponent::ChangeThirst(int32 Value)
{
	Thirst = CalculateValue(Thirst, Value, 0, MaxThirst);

	if (Thirst >= MaxThirst)
		return false;

	return true;
}

bool UParametersComponent::ChangeHunger(int32 Value)
{
	Hunger = CalculateValue(Hunger, Value, 0, MaxHunger);

	if (Hunger >= MaxHunger)
		return false;

	return false;
}
