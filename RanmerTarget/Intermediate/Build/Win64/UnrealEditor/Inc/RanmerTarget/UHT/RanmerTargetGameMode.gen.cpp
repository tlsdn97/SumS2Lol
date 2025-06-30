// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RanmerTarget/RanmerTargetGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRanmerTargetGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
RANMERTARGET_API UClass* Z_Construct_UClass_ARanmerTargetGameMode();
RANMERTARGET_API UClass* Z_Construct_UClass_ARanmerTargetGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_RanmerTarget();
// End Cross Module References

// Begin Class ARanmerTargetGameMode
void ARanmerTargetGameMode::StaticRegisterNativesARanmerTargetGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARanmerTargetGameMode);
UClass* Z_Construct_UClass_ARanmerTargetGameMode_NoRegister()
{
	return ARanmerTargetGameMode::StaticClass();
}
struct Z_Construct_UClass_ARanmerTargetGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RanmerTargetGameMode.h" },
		{ "ModuleRelativePath", "RanmerTargetGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARanmerTargetGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARanmerTargetGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_RanmerTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARanmerTargetGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARanmerTargetGameMode_Statics::ClassParams = {
	&ARanmerTargetGameMode::StaticClass,
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
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARanmerTargetGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARanmerTargetGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARanmerTargetGameMode()
{
	if (!Z_Registration_Info_UClass_ARanmerTargetGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARanmerTargetGameMode.OuterSingleton, Z_Construct_UClass_ARanmerTargetGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARanmerTargetGameMode.OuterSingleton;
}
template<> RANMERTARGET_API UClass* StaticClass<ARanmerTargetGameMode>()
{
	return ARanmerTargetGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARanmerTargetGameMode);
ARanmerTargetGameMode::~ARanmerTargetGameMode() {}
// End Class ARanmerTargetGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_RanmerTarget_Source_RanmerTarget_RanmerTargetGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARanmerTargetGameMode, ARanmerTargetGameMode::StaticClass, TEXT("ARanmerTargetGameMode"), &Z_Registration_Info_UClass_ARanmerTargetGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARanmerTargetGameMode), 1293479401U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_RanmerTarget_Source_RanmerTarget_RanmerTargetGameMode_h_3708352392(TEXT("/Script/RanmerTarget"),
	Z_CompiledInDeferFile_FID_SumS2Lol_RanmerTarget_Source_RanmerTarget_RanmerTargetGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_RanmerTarget_Source_RanmerTarget_RanmerTargetGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
