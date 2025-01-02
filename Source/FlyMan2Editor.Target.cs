// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class FlyMan2EditorTarget : TargetRules
{
	public FlyMan2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        // 最新のビルド設定バージョンを使用
        DefaultBuildSettings = BuildSettingsVersion.V5;

        // 最新のInclude Orderを使用
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "FlyMan2" } );
	}
}
