// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "EasyBPLibraryBPLibrary.generated.h"

UENUM()
enum class EBuildConfig : uint8
{
	Debug		UMETA(DisplayName = "Debug"),
	DebugGame   UMETA(DisplayName = "DebugGame"),
	Development	UMETA(DisplayName = "Development"),
	Shipping	UMETA(DisplayName = "Shipping"),
	Test		UMETA(DisplayName = "Test"),
	Unknown		UMETA(DisplayName = "Unknown")
};

UCLASS()
class UEasyBPLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(Category = "Math|Integer", BlueprintPure, meta=(CompactNodeTitle="% (AM!)", Keywords = "% mod", ToolTip = "Like a regular %, but entering a number less than 0 will make it wrap around."))
	static int32 ActuallyModulus(const int32 A, const int32 B);

	UFUNCTION(Category = "Utilities", BlueprintCallable)
	static bool ChangeComponentsOwner(UActorComponent* Component, AActor* NewOwner);

	UFUNCTION(Category = "Utilities", BlueprintCallable, BlueprintPure)
	static EBuildConfig GetBuildConfiguration();

	UFUNCTION(Category = "Utilities|String", BlueprintCallable, BlueprintPure)
	static FString StringsToString(TArray<FString> Strings);

	UFUNCTION(Category = "Actor", BlueprintCallable, BlueprintPure)
	static float GetActorMass(const AActor* Actor);

	UFUNCTION(Category = "Utilities", BlueprintCallable, BlueprintPure)
	static void GetVersionString(FString& Version);
};
