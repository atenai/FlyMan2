// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class FlyMan2EditorTarget : TargetRules
{
	public FlyMan2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        // �ŐV�̃r���h�ݒ�o�[�W�������g�p
        DefaultBuildSettings = BuildSettingsVersion.V5;

        // �ŐV��Include Order���g�p
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "FlyMan2" } );
	}
}
