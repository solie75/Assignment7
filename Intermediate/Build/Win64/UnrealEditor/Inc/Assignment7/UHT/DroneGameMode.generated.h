// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DroneGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASSIGNMENT7_DroneGameMode_generated_h
#error "DroneGameMode.generated.h already included, missing '#pragma once' in DroneGameMode.h"
#endif
#define ASSIGNMENT7_DroneGameMode_generated_h

#define FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADroneGameMode(); \
	friend struct Z_Construct_UClass_ADroneGameMode_Statics; \
public: \
	DECLARE_CLASS(ADroneGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Assignment7"), NO_API) \
	DECLARE_SERIALIZER(ADroneGameMode)


#define FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADroneGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADroneGameMode(ADroneGameMode&&); \
	ADroneGameMode(const ADroneGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADroneGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADroneGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADroneGameMode) \
	NO_API virtual ~ADroneGameMode();


#define FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_12_PROLOG
#define FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ASSIGNMENT7_API UClass* StaticClass<class ADroneGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_Assignment7_Source_Assignment7_DroneGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
