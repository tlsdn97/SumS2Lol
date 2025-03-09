// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5/Public/MyInvenComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInvenComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UNREAL5_API UClass* Z_Construct_UClass_UMyInvenComponent();
UNREAL5_API UClass* Z_Construct_UClass_UMyInvenComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5();
// End Cross Module References

// Begin Class UMyInvenComponent
void UMyInvenComponent::StaticRegisterNativesUMyInvenComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyInvenComponent);
UClass* Z_Construct_UClass_UMyInvenComponent_NoRegister()
{
	return UMyInvenComponent::StaticClass();
}
struct Z_Construct_UClass_UMyInvenComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyInvenComponent.h" },
		{ "ModuleRelativePath", "Public/MyInvenComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInvenComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyInvenComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyInvenComponent_Statics::ClassParams = {
	&UMyInvenComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyInvenComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyInvenComponent()
{
	if (!Z_Registration_Info_UClass_UMyInvenComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyInvenComponent.OuterSingleton, Z_Construct_UClass_UMyInvenComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyInvenComponent.OuterSingleton;
}
template<> UNREAL5_API UClass* StaticClass<UMyInvenComponent>()
{
	return UMyInvenComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInvenComponent);
UMyInvenComponent::~UMyInvenComponent() {}
// End Class UMyInvenComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyInvenComponent, UMyInvenComponent::StaticClass, TEXT("UMyInvenComponent"), &Z_Registration_Info_UClass_UMyInvenComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyInvenComponent), 3144239632U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenComponent_h_3188636043(TEXT("/Script/Unreal5"),
	Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyInvenComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
