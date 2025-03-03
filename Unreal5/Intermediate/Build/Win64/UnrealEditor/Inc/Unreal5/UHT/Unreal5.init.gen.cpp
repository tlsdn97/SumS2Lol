// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnreal5_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Unreal5;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Unreal5()
	{
		if (!Z_Registration_Info_UPackage__Script_Unreal5.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Unreal5",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xD2402D97,
				0x0EDDF67C,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Unreal5.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Unreal5.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Unreal5(Z_Construct_UPackage__Script_Unreal5, TEXT("/Script/Unreal5"), Z_Registration_Info_UPackage__Script_Unreal5, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD2402D97, 0x0EDDF67C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
