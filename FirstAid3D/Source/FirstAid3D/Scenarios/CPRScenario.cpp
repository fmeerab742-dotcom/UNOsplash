#include "Scenarios/CPRScenario.h"
#include "Core/FirstAidGameMode.h"
#include "Kismet/GameplayStatics.h"

ACPRScenario::ACPRScenario()
{
    ScenarioInfo.Id = 1;
    ScenarioInfo.Title = "CPR Simulation";
    ScenarioInfo.Description = "Perform 30 chest compressions followed by 2 rescue breaths.";
}

void ACPRScenario::PerformCompression()
{
    if (!bIsActive) return;

    CurrentCompressionsCount++;
    UE_LOG(LogTemp, Log, TEXT("Compression Performed: %d/%d"), CurrentCompressionsCount, TotalCompressionsTarget);

    if (CurrentCompressionsCount >= TotalCompressionsTarget)
    {
        AdvanceStep(); // Move from Compression step to Rescue Breath step
    }
}

void ACPRScenario::PerformRescueBreath()
{
    if (!bIsActive) return;

    CurrentBreathsCount++;
    UE_LOG(LogTemp, Log, TEXT("Rescue Breath Given: %d/%d"), CurrentBreathsCount, RescueBreathsTarget);

    if (CurrentBreathsCount >= RescueBreathsTarget && CurrentCompressionsCount >= TotalCompressionsTarget)
    {
        // Scenario 100% completed!
        CompleteScenario(true);
    }
}