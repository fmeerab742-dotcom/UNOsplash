#pragma once

#include "CoreMinimal.h"
#include "DatabaseTypes.generated.h"

// 1. User Profile Data
USTRUCT(BlueprintType)
struct FUserData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Id = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Name = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString CreatedAt = "";
};

// 2. User Settings
USTRUCT(BlueprintType)
struct FUserSettingsData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 UserId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    bool bSoundEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Difficulty = "Normal";
};

// 3. Scenario Metadata
USTRUCT(BlueprintType)
struct FScenarioData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Id = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Title = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Description = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Difficulty = "Easy";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Category = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 MaxScore = 100;
};

// 4. Scenario Steps
USTRUCT(BlueprintType)
struct FScenarioStepData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Id = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 ScenarioId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 StepNumber = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString Instruction = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString CorrectAction = "";
};

// 5. Quiz Questions
USTRUCT(BlueprintType)
struct FQuestionData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Id = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 ScenarioId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString QuestionText = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString OptionA = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString OptionB = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString OptionC = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString OptionD = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString CorrectAnswer = "A";
};

// 6. User Attempt Results
USTRUCT(BlueprintType)
struct FResultData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Id = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 UserId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 ScenarioId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 Score = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    int32 CompletionTime = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
    FString CompletedAt = "";
};