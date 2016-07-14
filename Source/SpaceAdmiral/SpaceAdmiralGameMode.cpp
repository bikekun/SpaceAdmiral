// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SpaceAdmiral.h"
#include "SpaceAdmiralGameMode.h"
#include "SpaceAdmiralHUD.h"
#include "SpaceAdmiralCharacter.h"

ASpaceAdmiralGameMode::ASpaceAdmiralGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASpaceAdmiralHUD::StaticClass();
}
