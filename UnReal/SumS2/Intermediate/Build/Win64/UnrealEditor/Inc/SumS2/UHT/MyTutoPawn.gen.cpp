// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SumS2/Public/MyTutoPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyTutoPawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SUMS2_API UClass* Z_Construct_UClass_AMyTutoPawn();
SUMS2_API UClass* Z_Construct_UClass_AMyTutoPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_SumS2();
// End Cross Module References

// Begin Class AMyTutoPawn
void AMyTutoPawn::StaticRegisterNativesAMyTutoPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyTutoPawn);
UClass* Z_Construct_UClass_AMyTutoPawn_NoRegister()
{
	return AMyTutoPawn::StaticClass();
}
struct Z_Construct_UClass_AMyTutoPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyTutoPawn.h" },
		{ "ModuleRelativePath", "Public/MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__mesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyTutoPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyTutoPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__mesh = { "_mesh", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__mesh_MetaData), NewProp__mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__mesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyTutoPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_SumS2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyTutoPawn_Statics::ClassParams = {
	&AMyTutoPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyTutoPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyTutoPawn()
{
	if (!Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton, Z_Construct_UClass_AMyTutoPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton;
}
template<> SUMS2_API UClass* StaticClass<AMyTutoPawn>()
{
	return AMyTutoPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyTutoPawn);
AMyTutoPawn::~AMyTutoPawn() {}
// End Class AMyTutoPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_UnReal_SumS2_Source_SumS2_Public_MyTutoPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyTutoPawn, AMyTutoPawn::StaticClass, TEXT("AMyTutoPawn"), &Z_Registration_Info_UClass_AMyTutoPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyTutoPawn), 2121810579U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_UnReal_SumS2_Source_SumS2_Public_MyTutoPawn_h_3461762949(TEXT("/Script/SumS2"),
	Z_CompiledInDeferFile_FID_SumS2Lol_UnReal_SumS2_Source_SumS2_Public_MyTutoPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_UnReal_SumS2_Source_SumS2_Public_MyTutoPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
