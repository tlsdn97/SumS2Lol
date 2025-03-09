// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREAL5_MyPlayer_generated_h
#error "MyPlayer.generated.h already included, missing '#pragma once' in MyPlayer.h"
#endif
#define UNREAL5_MyPlayer_generated_h

#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayer(); \
	friend struct Z_Construct_UClass_AMyPlayer_Statics; \
public: \
	DECLARE_CLASS(AMyPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal5"), NO_API) \
	DECLARE_SERIALIZER(AMyPlayer)


#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyPlayer(AMyPlayer&&); \
	AMyPlayer(const AMyPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPlayer) \
	NO_API virtual ~AMyPlayer();


#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_9_PROLOG
#define FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_12_INCLASS_NO_PURE_DECLS \
	FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL5_API UClass* StaticClass<class AMyPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
