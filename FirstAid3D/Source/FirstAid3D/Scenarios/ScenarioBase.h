#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Database/DatabaseTypes.h"
#include "ScenarioBase.generated.h"

UCLASS()
class FIRSTAID3D_API AScenarioBase : public AActor
{
    GENERATED_BODY()
    
public:    
    AScenarioBase();

protected:
    virtual void BeginPlay() override;

public:    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scenario Config")
    FScenarioData ScenarioInfo;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scenario State")
    int32 CurrentStepIndex = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scenario State")
    bool bIsActive = false;

    UFUNCTION(BlueprintCallable, Category = "Scenario Logic")
    virtual void StartScenario();

    UFUNCTION(BlueprintCallable, Category = "Scenario Logic")
    virtual void AdvanceStep();

    UFUNCTION(BlueprintCallable, Category = "Scenario Logic")
    virtual void CompleteScenario(bool bSuccess);
};