// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5/Public/MyEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyEnemy() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UNREAL5_API UClass* Z_Construct_UClass_AMyEnemy();
UNREAL5_API UClass* Z_Construct_UClass_AMyEnemy_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5();
// End Cross Module References

// Begin Class AMyEnemy
void AMyEnemy::StaticRegisterNativesAMyEnemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyEnemy);
UClass* Z_Construct_UClass_AMyEnemy_NoRegister()
{
	return AMyEnemy::StaticClass();
}
struct Z_Construct_UClass_AMyEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyEnemy.h" },
		{ "ModuleRelativePath", "Public/MyEnemy.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMyEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyEnemy_Statics::ClassParams = {
	&AMyEnemy::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyEnemy()
{
	if (!Z_Registration_Info_UClass_AMyEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyEnemy.OuterSingleton, Z_Construct_UClass_AMyEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyEnemy.OuterSingleton;
}
template<> UNREAL5_API UClass* StaticClass<AMyEnemy>()
{
	return AMyEnemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyEnemy);
AMyEnemy::~AMyEnemy() {}
// End Class AMyEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyEnemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyEnemy, AMyEnemy::StaticClass, TEXT("AMyEnemy"), &Z_Registration_Info_UClass_AMyEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyEnemy), 2035404913U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyEnemy_h_3354330620(TEXT("/Script/Unreal5"),
	Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
