// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorUtils.h"

#include "IAssetTools.h"
#include "Exporters/Exporter.h"
#include "AssetRegistry/AssetRegistryModule.h"



void UEditorUtils::ExportListAsLogFile(const TArray<FString>& AssetNameList)
{

	if (AssetNameList.IsEmpty())
		return;

	FString OutputText;
	for (const auto& AssetName : AssetNameList)
	{
		OutputText.Append(AssetName + '\n');
	}
	const FString FileName = FPaths::ProjectSavedDir() / TEXT("UnworthyTextures_") + FDateTime::Now().ToString() + TEXT(".log");
	FFileHelper::SaveStringToFile(OutputText, *FileName);

}

void UEditorUtils::ExportStaticMeshes(const TArray<UStaticMesh*>& StaticMeshList)
{

    if(StaticMeshList.IsEmpty())
        return;

    //Create the save direction path
    const FString ExportPathDir = FPaths::ProjectSavedDir() / TEXT("Rework");
    IFileManager::Get().MakeDirectory(*ExportPathDir, true);

    
    //Export StaticMesh one by one
    for (const auto& StaticMeshToExport : StaticMeshList)
    {
        //Name Each StaticMesh 
        const FString StaticMeshName = ExportPathDir / StaticMeshToExport->GetName() + TEXT(".fbx");

        FArchive* CreateExport = IFileManager::Get().CreateFileWriter(*StaticMeshName);
        UExporter* Exporter = UExporter::FindExporter(StaticMeshToExport, TEXT("FBX"));

        
        Exporter->ExportBinary(StaticMeshToExport,TEXT("FBX"), *CreateExport,GWarn);
        CreateExport->Close();

    }

}


//void UEditorUtils::GetAllAssetOfClass(UClass* InClass, TArray<FAssetData>& OutAssetData, TArray<UStaticMesh*>& OutStaticMeshes)
//{
//
//	if (InClass)return;
//
//	const auto& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
//	const IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
//
//
//	AssetRegistry.GetAssetsByClass(InClass->GetClassPathName(), OutAssetData);
//	
//}

void UEditorUtils::GetAllAssetOfClass(TArray<UStaticMesh*>& OutStaticMeshes)
{

    const auto& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
    const IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

    TArray<FAssetData> AssetList;
    AssetRegistry.GetAssetsByClass(UStaticMesh::StaticClass()->GetClassPathName(), AssetList);

    //Add StaticMesh to a List
    for (const FAssetData& AssetData : AssetList)
    {
        UStaticMesh* StaticMesh = Cast<UStaticMesh>(AssetData.GetAsset());
        if (StaticMesh)
        {
            OutStaticMeshes.Add(StaticMesh);
        }
    }
}

float UEditorUtils::GetNumberOfTriangles(UStaticMesh* StaticMesh)
{

	const FStaticMeshLODResources& StaticMeshResources = StaticMesh->GetRenderData()->LODResources[0];
    
	return StaticMeshResources.GetNumTriangles();

}
