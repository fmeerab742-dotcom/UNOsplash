#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstAidGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScoreUpdated, int32, NewScore, int32, TimeRemaining);

UCLASS()
class FIRSTAID3D_API AFirstAidGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AFirstAidGameMode();

    virtual void BeginPlay() override;

    // Active Scenario Tracking
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Simulation")
    int32 CurrentScenarioId = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Simulation")
    int32 CurrentScore = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Simulation")
    int32 TotalTimeSeconds = 180;

    // Scoring & Flow Controls
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void AddScore(int32 Points);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void EndScenario(bool bSuccess);

    UPROPERTY(BlueprintAssignable, Category = "Simulation | Events")
    FOnScoreUpdated OnScoreUpdated;

private:
    FTimerHandle GameTimerHandle;
    void UpdateTimer();
};