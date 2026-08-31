#include "Database/MySQLManager.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"

UMySQLManager::UMySQLManager()
{
}

void UMySQLManager::FetchUserData(int32 UserId, FOnDataReceived OnComplete)
{
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    
    FString RequestUrl = FString::Printf(TEXT("%s/users/%d"), *BaseApiUrl, UserId);
    Request->SetURL(RequestUrl);
    Request->SetVerb("GET");
    Request->SetHeader("Content-Type", "application/json");

    Request->OnProcessRequestComplete().BindUObject(this, &UMySQLManager::OnHttpResponseReceived, OnComplete);
    Request->ProcessRequest();
}

void UMySQLManager::SaveUserResult(int32 UserId, int32 ScenarioId, int32 Score, int32 CompletionTime, FOnDataReceived OnComplete)
{
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

    FString RequestUrl = FString::Printf(TEXT("%s/results"), *BaseApiUrl);
    Request->SetURL(RequestUrl);
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");

    // Construct JSON Payload matching MySQL Results table schema
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    JsonObject->SetNumberField("user_id", UserId);
    JsonObject->SetNumberField("scenario_id", ScenarioId);
    JsonObject->SetNumberField("score", Score);
    JsonObject->SetNumberField("completion_time", CompletionTime);

    FString OutputJsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputJsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    Request->SetContentAsString(OutputJsonString);
    Request->OnProcessRequestComplete().BindUObject(this, &UMySQLManager::OnHttpResponseReceived, OnComplete);
    Request->ProcessRequest();
}

void UMySQLManager::OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnDataReceived OnComplete)
{
    FString ResponseString = "";
    bool bSuccess = false;

    if (bWasSuccessful && Response.IsValid())
    {
        if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
        {
            ResponseString = Response->GetContentAsString();
            bSuccess = true;
        }
        else
        {
            ResponseString = FString::Printf(TEXT("HTTP Error Code: %d"), Response->GetResponseCode());
        }
    }
    else
    {
        ResponseString = TEXT("Connection Failed: Unable to reach MySQL API Server.");
    }

    // Execute Blueprint Callback
    OnComplete.ExecuteIfBound(bSuccess, ResponseString);
}