// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EasyBPLibraryBPLibrary.h"
#include "Misc/App.h"
#include "Misc/ConfigCacheIni.h"
#include "Components/PrimitiveComponent.h"
#include "EasyBPLibrary.h"

UEasyBPLibraryBPLibrary::UEasyBPLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

int32 UEasyBPLibraryBPLibrary::ActuallyModulus(const int32 A, const int32 B)
{
	if (B == 0) {
		return 0;
	}
	if (A < 0) {
		return (A % B) + B;
	}
	return A % B;
}

bool UEasyBPLibraryBPLibrary::ChangeComponentsOwner(UActorComponent* Component, AActor* NewOwner) {
	return Component->Rename(NULL, NewOwner);
}

EBuildConfig UEasyBPLibraryBPLibrary::GetBuildConfiguration()
{
	switch (FApp::GetBuildConfiguration()) {
	case EBuildConfigurations::Debug:
		return EBuildConfig::Debug;
		break;
	case EBuildConfigurations::DebugGame:
		return EBuildConfig::DebugGame;
		break;
	case EBuildConfigurations::Development:
		return EBuildConfig::Development;
		break;
	case EBuildConfigurations::Shipping:
		return EBuildConfig::Shipping;
	case EBuildConfigurations::Test:
		return EBuildConfig::Test;
	default:
		return EBuildConfig::Unknown;
	}
}

FString UEasyBPLibraryBPLibrary::StringsToString(TArray<FString> Strings)
{
	FString OutputString = "";
	for (int i = 0; i < Strings.Num(); i++) {
		OutputString.Append(Strings[i]);
		if (i + 1 < Strings.Num()) {
			OutputString.AppendChar(',');
		}
	}
	return OutputString;
}

float UEasyBPLibraryBPLibrary::GetActorMass(const AActor * Actor)
{
	float TotalMass = 0.0f;
	TArray<UActorComponent*> ActorPrimatives = Actor->GetComponentsByClass(UPrimitiveComponent::StaticClass());
	for (auto Component : ActorPrimatives) {
		TotalMass = TotalMass + Cast<UPrimitiveComponent>(Component)->GetMass();
	}
	return TotalMass;
}

void UEasyBPLibraryBPLibrary::GetVersionString(FString& Version)
{
	if (!GConfig) return;
	GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("ProjectVersion"), Version, GGameIni);
}
