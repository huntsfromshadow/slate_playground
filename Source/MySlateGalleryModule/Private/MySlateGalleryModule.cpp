// ReSharper disable CommentTypo
#include "MySlateGalleryModule.h"
#include "ToolMenus.h"

static const FName MySlateGalleryWindowTabName("MySlateGalleryWindow");

#define LOCTEXT_NAMESPACE "FMySlateGalleryModule"

void FMySlateGalleryModule::StartupModule()
{
	// Register function to called when menu system is brought online
	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(
			this, &FMySlateGalleryModule::RegisterMenuExtensions)
	);

	// Register the Tab Spawner
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		MySlateGalleryWindowTabName,	// FName of the new Tab (defined above
		FOnSpawnTab::CreateRaw(this, &FMySlateGalleryModule::OnSpawnPluginTab))	// What to do when spawned
	.SetDisplayName(FText::FromString("My Slate Gallery"))
	.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMySlateGalleryModule::ShutdownModule()
{
	// Unregister the startup function
	UToolMenus::UnRegisterStartupCallback(this);

	// Unregister all our menu extensions
	UToolMenus::UnregisterOwner(this);

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MySlateGalleryWindowTabName);
}

void FMySlateGalleryModule::RegisterMenuExtensions()
{
	// Use the current object as the owner of the menus
	// This allows us to uninstall custom menus and callbacks
	// and easier (see Shutdown above)
	FToolMenuOwnerScoped OwnerScoped(this);

/*
	// Extend the "File" Section of the main toolbar.
	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu(
		"LevelEditor.LevelEditorToolBar.ModesToolBar");
	FToolMenuSection& ToolbarSection = ToolbarMenu->FindOrAddSection("File");

	ToolbarSection.AddEntry(FToolMenuEntry::InitToolBarButton(
		TEXT("MyCustomButtonName"),
		FExecuteAction::CreateLambda([]()
		{
			//Log out for test
			UE_LOG(LogTemp, Log, TEXT("MyCustomButton triggered"));
		}),
		INVTEXT("My Custom Button"),
		INVTEXT("Tooltip for My custom button"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Comment")
	));
*/

	// Add Menu
	// Add a new section to the select menu right after the "BSP" section
	UToolMenu* SelectionMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Select");
	FToolMenuSection& SelectionSection = SelectionMenu->AddSection(
		"MyCustomSection",
		INVTEXT("My Custom Section"),
		FToolMenuInsert("SelectBSP", EToolMenuInsertType::After)
	);

	SelectionSection.AddEntry(FToolMenuEntry::InitMenuEntry(
		"MyCustomEntryName",
		INVTEXT("My custom entry"),
		INVTEXT("Tooltip for my custom entry"),
		FSlateIcon(),
		FExecuteAction::CreateLambda([]() 
		{
			UE_LOG(LogTemp, Log, TEXT("MyCustomEntry triggered!!"));
			FGlobalTabmanager::Get()->TryInvokeTab(MySlateGalleryWindowTabName);
		})
	));

}

// ReSharper disable once CppMemberFunctionMayBeStatic
TSharedRef<class SDockTab> FMySlateGalleryModule::OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs)
{
	const FText WidgetText = FText::FromString("Hello World");
	return SNew(SDockTab)
	.TabRole(ETabRole::NomadTab)
	[
		SNew(STextBlock)
			.Text(WidgetText)
	];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMySlateGalleryModule, MySlateGalleryModule)
