#include "Scenarios/ScenarioBase.h"
#include "Core/FirstAidGameMode.h"
#include "Kismet/GameplayStatics.h"

AScenarioBase::AScenarioBase()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AScenarioBase::BeginPlay()
{
    Super::BeginPlay();
}

void AScenarioBase::StartScenario()
{
    bIsActive = true;
    CurrentStepIndex = 0;
    UE_LOG(LogTemp, Log, TEXT("Scenario Started: %s"), *ScenarioInfo.Title);
}

void AScenarioBase::AdvanceStep()
{
    if (!bIsActive) return;

    CurrentStepIndex++;
    UE_LOG(LogTemp, Log, TEXT("Advanced to Step Index: %d"), CurrentStepIndex);

    // Reward points for completing a step
    AFirstAidGameMode* GM = Cast<AFirstAidGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (GM)
    {
        GM->AddScore(25); // 25 Points per correct step
    }
}

void AScenarioBase::CompleteScenario(bool bSuccess)
{
    bIsActive = false;
    
    AFirstAidGameMode* GM = Cast<AFirstAidGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (GM)
    {
        GM->EndScenario(bSuccess);
    }
}