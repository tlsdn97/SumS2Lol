// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5/Public/MyStatComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyStatComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UNREAL5_API UClass* Z_Construct_UClass_UMyStatComponent();
UNREAL5_API UClass* Z_Construct_UClass_UMyStatComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5();
// End Cross Module References

// Begin Class UMyStatComponent
void UMyStatComponent::StaticRegisterNativesUMyStatComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyStatComponent);
UClass* Z_Construct_UClass_UMyStatComponent_NoRegister()
{
	return UMyStatComponent::StaticClass();
}
struct Z_Construct_UClass_UMyStatComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyStatComponent.h" },
		{ "ModuleRelativePath", "Public/MyStatComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyStatComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyStatComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyStatComponent_Statics::ClassParams = {
	&UMyStatComponent::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyStatComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyStatComponent()
{
	if (!Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton, Z_Construct_UClass_UMyStatComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton;
}
template<> UNREAL5_API UClass* StaticClass<UMyStatComponent>()
{
	return UMyStatComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyStatComponent);
UMyStatComponent::~UMyStatComponent() {}
// End Class UMyStatComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyStatComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyStatComponent, UMyStatComponent::StaticClass, TEXT("UMyStatComponent"), &Z_Registration_Info_UClass_UMyStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyStatComponent), 3811615891U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyStatComponent_h_3918448710(TEXT("/Script/Unreal5"),
	Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SumS2Lol_Unreal5_Source_Unreal5_Public_MyStatComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
