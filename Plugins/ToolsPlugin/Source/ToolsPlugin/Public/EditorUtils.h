// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorUtils.generated.h"

/**
 * 
 */
UCLASS()
class TOOLSPLUGIN_API UEditorUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:


	UFUNCTION(BlueprintCallable, Category = "Utils")
	static void ExportListAsLogFile(const TArray<FString>& AssetNameList);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	static void ExportStaticMeshes(const TArray<UStaticMesh*>& StaticMeshList);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	static void GetAllAssetOfClass(TArray<UStaticMesh*>& OutStaticMeshes);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	static float GetNumberOfTriangles(UStaticMesh* StaticMesh);

};
