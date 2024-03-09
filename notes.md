Notes for myself

# UMG and Slate
* 

# Widget Inheritance
* Don't import from SWidget
* Use Below
    * SLeafWidget -> "A LeafWidget is a Widget that has no slots for children. LeafWidgets are usually intended as building blocks for aggregate widgets." -> https://docs.unrealengine.com/5.3/en-US/API/Runtime/SlateCore/Widgets/SLeafWidget/
    * SPanel -> "A Panel arranges its child widgets on the screen." -> https://docs.unrealengine.com/5.3/en-US/API/Runtime/SlateCore/Widgets/SPanel/
    * SCompoundWidget -> A CompoundWidget is the base from which most non-primitive widgets should be built. CompoundWidgets have a protected member named ChildSlot. -> https://docs.unrealengine.com/5.3/en-US/API/Runtime/SlateCore/Widgets/SCompoundWidget/
* Other notes
    * SWindow -> https://docs.unrealengine.com/5.3/en-US/API/Runtime/SlateCore/Widgets/SWindow/

# Random Resources
## Videos
- https://www.youtube.com/watch?v=oCML-NOTArE -> Creating a UMG/Slate Image in Unreal Engine

## Blogs
- https://lxjk.github.io/2019/10/01/How-to-Make-Tools-in-U-E.html#_setup_editor_module (Note in UE4)
- https://docs.unrealengine.com/5.3/en-US/how-to-make-a-gameplay-module-in-unreal-engine/
- https://docs.unrealengine.com/5.0/en-US/slate-editor-window-quickstart-guide-for-unreal-engine/
