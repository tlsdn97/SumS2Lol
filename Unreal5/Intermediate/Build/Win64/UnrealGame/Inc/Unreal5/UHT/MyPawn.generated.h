// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREAL5_MyPawn_generated_h
#error "MyPawn.generated.h already included, missing '#pragma once' in MyPawn.h"
#endif
#define UNREAL5_MyPawn_generated_h

#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPawn(); \
	friend struct Z_Construct_UClass_AMyPawn_Statics; \
public: \
	DECLARE_CLASS(AMyPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal5"), NO_API) \
	DECLARE_SERIALIZER(AMyPawn)


#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyPawn(AMyPawn&&); \
	AMyPawn(const AMyPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPawn) \
	NO_API virtual ~AMyPawn();


#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_12_PROLOG
#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_15_INCLASS_NO_PURE_DECLS \
	FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL5_API UClass* StaticClass<class AMyPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
