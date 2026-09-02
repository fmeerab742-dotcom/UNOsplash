#pragma once

#include "CoreMinimal.h"
#include "Scenarios/ScenarioBase.h"
#include "CPRScenario.generated.h"

UCLASS()
class FIRSTAID3D_API ACPRScenario : public AScenarioBase
{
    GENERATED_BODY()

public:
    ACPRScenario();

    // CPR Specific Metrics
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPR Logic")
    int32 TotalCompressionsTarget = 30;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CPR Logic")
    int32 CurrentCompressionsCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPR Logic")
    int32 RescueBreathsTarget = 2;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CPR Logic")
    int32 CurrentBreathsCount = 0;

    UFUNCTION(BlueprintCallable, Category = "CPR Logic")
    void PerformCompression();

    UFUNCTION(BlueprintCallable, Category = "CPR Logic")
    void PerformRescueBreath();
};