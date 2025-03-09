// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5/Public/MyInvenUI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInvenUI() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UNREAL5_API UClass* Z_Construct_UClass_UMyInvenUI();
UNREAL5_API UClass* Z_Construct_UClass_UMyInvenUI_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5();
// End Cross Module References

// Begin Class UMyInvenUI
void UMyInvenUI::StaticRegisterNativesUMyInvenUI()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyInvenUI);
UClass* Z_Construct_UClass_UMyInvenUI_NoRegister()
{
	return UMyInvenUI::StaticClass();
}
struct Z_Construct_UClass_UMyInvenUI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyInvenUI.h" },
		{ "ModuleRelativePath", "Public/MyInvenUI.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInvenUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyInvenUI_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyInvenUI_Statics::ClassParams = {
	&UMyInvenUI::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyInvenUI_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyInvenUI()
{
	if (!Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton, Z_Construct_UClass_UMyInvenUI_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton;
}
template<> UNREAL5_API UClass* StaticClass<UMyInvenUI>()
{
	return UMyInvenUI::StaticClass();
}
UMyInvenUI::UMyInvenUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInvenUI);
UMyInvenUI::~UMyInvenUI() {}
// End Class UMyInvenUI

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenUI_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyInvenUI, UMyInvenUI::StaticClass, TEXT("UMyInvenUI"), &Z_Registration_Info_UClass_UMyInvenUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyInvenUI), 43989083U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenUI_h_3805814736(TEXT("/Script/Unreal5"),
	Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenUI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenUI_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
