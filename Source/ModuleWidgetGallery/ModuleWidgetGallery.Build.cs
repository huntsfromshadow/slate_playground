using UnrealBuildTool;

public class ModuleWidgetGallery : ModuleRules
{
	public ModuleWidgetGallery(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "ModuleWidgetGallery"	
		});
	}
}