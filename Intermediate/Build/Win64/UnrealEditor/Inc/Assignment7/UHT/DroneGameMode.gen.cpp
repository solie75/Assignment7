// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Assignment7/DroneGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDroneGameMode() {}

// Begin Cross Module References
ASSIGNMENT7_API UClass* Z_Construct_UClass_ADroneGameMode();
ASSIGNMENT7_API UClass* Z_Construct_UClass_ADroneGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
UPackage* Z_Construct_UPackage__Script_Assignment7();
// End Cross Module References

// Begin Class ADroneGameMode
void ADroneGameMode::StaticRegisterNativesADroneGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADroneGameMode);
UClass* Z_Construct_UClass_ADroneGameMode_NoRegister()
{
	return ADroneGameMode::StaticClass();
}
struct Z_Construct_UClass_ADroneGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "DroneGameMode.h" },
		{ "ModuleRelativePath", "DroneGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADroneGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADroneGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_Assignment7,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADroneGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADroneGameMode_Statics::ClassParams = {
	&ADroneGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADroneGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ADroneGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADroneGameMode()
{
	if (!Z_Registration_Info_UClass_ADroneGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADroneGameMode.OuterSingleton, Z_Construct_UClass_ADroneGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADroneGameMode.OuterSingleton;
}
template<> ASSIGNMENT7_API UClass* StaticClass<ADroneGameMode>()
{
	return ADroneGameMode::StaticClass();
}
ADroneGameMode::ADroneGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADroneGameMode);
ADroneGameMode::~ADroneGameMode() {}
// End Class ADroneGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADroneGameMode, ADroneGameMode::StaticClass, TEXT("ADroneGameMode"), &Z_Registration_Info_UClass_ADroneGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADroneGameMode), 4242782033U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_4293814931(TEXT("/Script/Assignment7"),
	Z_CompiledInDeferFile_FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
