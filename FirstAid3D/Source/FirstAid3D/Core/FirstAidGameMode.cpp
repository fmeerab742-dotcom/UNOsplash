#include "Core/FirstAidGameMode.h"
#include "Core/FirstAidGameInstance.h"
#include "Kismet/GameplayStatics.h"

AFirstAidGameMode::AFirstAidGameMode()
{
}

void AFirstAidGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Start Simulation Countdown Timer (1 second interval)
    GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AFirstAidGameMode::UpdateTimer, 1.0f, true);
}

void AFirstAidGameMode::AddScore(int32 Points)
{
    CurrentScore += Points;
    OnScoreUpdated.Broadcast(CurrentScore, TotalTimeSeconds);
}

void AFirstAidGameMode::UpdateTimer()
{
    if (TotalTimeSeconds > 0)
    {
        TotalTimeSeconds--;
        OnScoreUpdated.Broadcast(CurrentScore, TotalTimeSeconds);
    }
    else
    {
        GetWorldTimerManager().ClearTimer(GameTimerHandle);
        EndScenario(false); // Time out
    }
}

void AFirstAidGameMode::EndScenario(bool bSuccess)
{
    GetWorldTimerManager().ClearTimer(GameTimerHandle);

    // Get reference to GameInstance and save score via MySQLManager
    UFirstAidGameInstance* GI = Cast<UFirstAidGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (GI && GI->DbManager)
    {
        int32 CompletionTime = 180 - TotalTimeSeconds;
        
        GI->DbManager->SaveUserResult(
            GI->CurrentUser.Id,
            CurrentScenarioId,
            CurrentScore,
            CompletionTime,
            FOnDataReceived::CreateLambda([](bool bWasSuccessful, const FString& Response)
            {
                if (bWasSuccessful)
                {
                    UE_LOG(LogTemp, Log, TEXT("Simulation result saved to MySQL database successfully!"));
                }
            })
        );
    }
}