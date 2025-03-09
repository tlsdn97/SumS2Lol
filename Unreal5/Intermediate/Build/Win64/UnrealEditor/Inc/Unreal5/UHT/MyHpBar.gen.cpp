// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5/Public/MyHpBar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyHpBar() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UNREAL5_API UClass* Z_Construct_UClass_UMyHpBar();
UNREAL5_API UClass* Z_Construct_UClass_UMyHpBar_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5();
// End Cross Module References

// Begin Class UMyHpBar
void UMyHpBar::StaticRegisterNativesUMyHpBar()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyHpBar);
UClass* Z_Construct_UClass_UMyHpBar_NoRegister()
{
	return UMyHpBar::StaticClass();
}
struct Z_Construct_UClass_UMyHpBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyHpBar.h" },
		{ "ModuleRelativePath", "Public/MyHpBar.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyHpBar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyHpBar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyHpBar_Statics::ClassParams = {
	&UMyHpBar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyHpBar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyHpBar()
{
	if (!Z_Registration_Info_UClass_UMyHpBar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyHpBar.OuterSingleton, Z_Construct_UClass_UMyHpBar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyHpBar.OuterSingleton;
}
template<> UNREAL5_API UClass* StaticClass<UMyHpBar>()
{
	return UMyHpBar::StaticClass();
}
UMyHpBar::UMyHpBar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyHpBar);
UMyHpBar::~UMyHpBar() {}
// End Class UMyHpBar

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyHpBar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyHpBar, UMyHpBar::StaticClass, TEXT("UMyHpBar"), &Z_Registration_Info_UClass_UMyHpBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyHpBar), 2548658457U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyHpBar_h_2065571370(TEXT("/Script/Unreal5"),
	Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyHpBar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyHpBar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
