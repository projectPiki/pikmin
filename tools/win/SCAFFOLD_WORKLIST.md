# Pikmin Windows Modules -- Source-File Worklist

These are the source files to create for five not-yet-started Pikmin Windows modules, derived from each module's **shipped `.ilk`** -- the linker's own record of which object file defined which function. The function/class **names and their object-file ownership are ground truth** (read straight from the incremental-link database). The proposed **source paths** are conventions only (`src/<module>/<stem>.cpp`); adjust them to whatever layout the project adopts. Every "own TU" is a `kind=cmdline` object built as `.\Debug\<stem>.obj` -- one such object equals one `.cpp` to author.

Two cautions that apply to every module:
- **`attachModule.cpp` and `sysNew.cpp` are shared per-plugin boilerplate**, not module-unique logic. They are `.\Debug\*.obj` in every plugin's own build tree (so they are listed as files to create), but their *contents* are the generic DLL bootstrap (`DllMain` + `speedy_sqrtf`/`sqrtf` + the compiler's vector-constructor-iterator helper) and the global `operator new`/`delete` family respectively. Source them from a shared template rather than hand-authoring per module.
- **COMDATs do not respect one-class-per-file.** A class's ctor/vtable can be emitted into a *different* TU than its other methods. Attribute each function to the object that actually owns it (as listed), not to where the class "should" live. Per-class notes below flag the notable cases.

---

## 1. filterDvw -- DVW (GameCube model/view) file-format importer

**9 files, 121 functions.** A "filter" plugin whose classes are almost all DVW format chunks with a `readDVW(RandomAccessStream&)` deserializer; ctors are batched into `filtDvwParser.obj`/`dvwModelData.obj`, and `DvwParser::import` (in `filtDvwParser.obj`) is the load entry point.

| Proposed source path | #fns | Primary class(es) |
|---|---|---|
| `src/filterDvw/attachModule.cpp` | 4 | *(DLL glue -- boilerplate)* |
| `src/filterDvw/sysNew.cpp` | 6 | *(global new/delete -- boilerplate)* |
| `src/filterDvw/dvwAnimFrame.cpp` | 1 | DVWAnimFrameInfo |
| `src/filterDvw/dvwHeader.cpp` | 12 | DVWHeader + header chunks |
| `src/filterDvw/dvwMaterial.cpp` | 50 | DVWMaterial + material/tev/tex chunks |
| `src/filterDvw/dvwModelData.cpp` | 13 | DVWModelData + chunk ctors |
| `src/filterDvw/dvwPicData.cpp` | 3 | DVWPicData, DVWPicAttrInfo |
| `src/filterDvw/attachFilterDvw.cpp` | 7 | DvwParser, FilterInterface (exports) |
| `src/filterDvw/filtDvwParser.cpp` | 25 | DvwParser + chunk ctors |

**Header note:** DVW classes are declared in shared header(s), not one-per-TU (e.g. `DVWPicData`'s ctor is in `dvwHeader.obj` but its `readDVW`/`copyToTexImg` are in `dvwPicData.obj`; `DVWMaterial`'s ctor is in `dvwModelData.obj`). Propose one shared DVW-format header family (e.g. `include/DVW.h`) plus `include/DvwParser.h` for the parser/FilterInterface glue.

### attachModule.cpp *(boilerplate)*
- *(free / DLL):* `DllMain`, `speedy_sqrtf(float)`, `sqrtf`, `\`vector constructor iterator\`` helper

### sysNew.cpp *(boilerplate)*
- *(global):* `operator new(uint)`, `operator new[](uint)`, `operator new(uint,int)`, `operator new[](uint,int)`, `operator delete(void*)`, `operator delete[](void*)`

### dvwAnimFrame.cpp
- **DVWAnimFrameInfo:** `readDVW`

### dvwHeader.cpp
- **DVWHeader:** `readDVW` -> bool
- **DVWSysInfo / DVWScrnInfo / DVWBackInfo / DVWCamInfo / DVWPictures / DVWFooter:** `readDVW` (each)
- **DVWLightInfo:** `readDVW`; nested `SpotInfo::readDVW`, `PointInfo::readDVW`
- **DVWPicData:** ctor
- **DVWChunk:** ctor

### dvwMaterial.cpp *(largest chunk TU; ~164 rdata consts; `DVWMaterial::copyToMaterial` ~ 0x1550 bytes)*
- **DVWMaterial:** `copyToMaterial(Mesh*, Material*)`, `readDVW`
- **DVWTextureData:** `readDVW`, `updateForNormal`, `updateForBump`, `updateForIndirect`, ctor
- **DVWTextureInfo:** `readDVW`
- **DVWPeInfo:** `readDVW`; nested `DVWACompInfo::readDVW`, `DVWZCompInfo::readDVW`, `DVWBlendInfo::readDVW`, `DVWPolygonInfo::readDVW`
- **DVWTevInfo:** `readDVW`, ctor
- **DVWStageInfo:** `readDVW`, ctor
- **DVWCombineInfo:** `readDVW`, `print`
- **DVWOneStageInfo:** `readDVW`, `print`
- **DVWTevColRegInfo / DVWTevKonstRegInfo:** `readDVW`, ctor (each)
- **DVWTevUserColourAnimInfo / DVWTevUserAlphaAnimInfo:** `readDVW`, ctor (each)
- **DVWToolColAnimInfo / DVWUserColourAnimInfo / DVWPolygonColourInfo / DVWTexXformInfo / DVWCullingInfo / DVWLightingInfo / DVWDitherInfo:** `readDVW` (each)
- **DVWUserAlphaAnimInfo:** `readDVW`, ctor
- **DVWTexSAnimInfo / DVWTexRAnimInfo / DVWTexTAnimInfo:** `readDVW`, ctor (each)
- **DVWProjData:** `readDVW`; nested `SAttrInfo::readDVW`; ctor
- **DVWFogCalcInfo:** `readDVW`; nested `DVWFogAttrInfo::readDVW`
- **DVWAnimFrameInfo:** ctor

### dvwModelData.cpp *(chunk-class ctor batch)*
- **DVWModelData:** `readDVW`
- **DVWCharacterAnimInfo / DVWClusterAnimInfo / DVWTexPatternAnimInfo:** `readDVW` (each)
- *ctors:* **DVWMaterial**, **DVWCullingInfo**, **DVWPolygonColourInfo**, **DVWLightingInfo**, **DVWTextureInfo**, **DVWFogCalcInfo**, **DVWDitherInfo**, **DVWPeInfo**, **DVWUserColourAnimInfo**

### dvwPicData.cpp
- **DVWPicAttrInfo:** `readDVW`
- **DVWPicData:** `readDVW`, `copyToTexImg(TexImg*)`

### attachFilterDvw.cpp *(plugin ABI -- 3 validated DLL exports)*
- *(free):* `newFilterDvw()` factory; **exports** `AutoStart` (#1), `GetObjectList` (#2), `NewObject` (#3)
- **DvwParser:** ctor
- **FilterInterface:** ctor *(shared plugin base emitted here)*
- **ObjectHandle:** `ObjectHandle(char*, bool, void*(*)())`

### filtDvwParser.cpp *(entry point + ctor batch)*
- **DvwParser:** `import(BaseShape*, RandomAccessStream&)` *(virtual override -- the load entry point)*
- **DVWChunk:** `read`
- **DVWLighting / DVWProjInfo / DVWFogInfo / DVWModelsInfo:** `readDVW` + ctor (each)
- **DVWFogData:** `readDVW`; nested `SAttrInfo::readDVW`; ctor
- *ctors:* **DVWHeader**, **DVWPictures**, **DVWSysInfo**, **DVWScrnInfo**, **DVWBackInfo**, **DVWCamInfo**, **DVWFooter**, **DVWLightInfo**, **DVWModelData**, **DVWCharacterAnimInfo**, **DVWClusterAnimInfo**, **DVWTexPatternAnimInfo**

**NOT files to create (library/SDK/linker):** `sysCore.dll` (51 import thunks -- `RandomAccessStream`, `Vector3f::read`, `Colour::read`, `Material`/`Mesh`/`TexImg` ctors, `CoreNode`, `System::halt`, `AyuStack::push`, `PVW*` readers, etc.; `Material.h`/`Mesh.h` already in `include/`), `KERNEL32.dll` (6), `MSVCRTD.dll` (36 debug-CRT), the VC6 CRT startup objects under `build\intel\xdll_obj\` (`dllsupp/crtdll/cinitexe/atonexit/adjustfd.obj`), `Debug/filterDvw.exp` (linker export stub from the `.def`), and the `linker defined module` synthetics (`__except_list`, `__fltused`, `__ldused`).

---

## 2. filterJmp -- JMP map/collision-attribute import filter

**4 files, 18 functions.** Only 2 TUs are genuinely plugin-specific; the other 2 are shared boilerplate. The whole parser is a single ~3.2 KB virtual method.

| Proposed source path | #fns | Primary class(es) |
|---|---|---|
| `src/filterJmp/attachFilterJmp.cpp` | 7 | JmpParser, FilterInterface (exports) |
| `src/filterJmp/filtJmpParser.cpp` | 1 | JmpParser |
| `src/filterJmp/attachModule.cpp` | 4 | *(DLL glue -- boilerplate)* |
| `src/filterJmp/sysNew.cpp` | 6 | *(global new/delete -- boilerplate)* |

**Header note:** `JmpParser` is split across the two plugin TUs (ctor+vtable in `attachFilterJmp.obj`, virtual `import` in `filtJmpParser.obj`); declare it once in a shared `src/filterJmp/jmpParser.h`. `JmpParser` derives from `FilterInterface`.

### attachFilterJmp.cpp *(3 validated DLL exports)*
- *(free):* `newFilterJmp()` factory; **exports** `NewObject`, `GetObjectList`, `AutoStart`
- **JmpParser:** ctor
- **FilterInterface:** ctor *(framework base emitted here)*
- **ObjectHandle:** `ObjectHandle(char*, bool, void*(*)())`

### filtJmpParser.cpp
- **JmpParser:** `import(BaseShape*, RandomAccessStream&)` *(virtual; ~0xcb7/3255 bytes -- the ENTIRE JMP parser in one method: tokenized `CmdStream` parse -> `BaseShape::findCollTri` collision-triangle tagging)*

### attachModule.cpp *(boilerplate)*
- `DllMain`, `speedy_sqrtf`, `sqrtf`, `\`vector constructor iterator\`` helper

### sysNew.cpp *(boilerplate)*
- `operator new`/`new[]`/`delete`/`delete[]` (2 each)

**NOT files to create:** `sysCore.dll` (11 call thunks -- `CmdStream::{isToken,getToken,endOfSection,endOfCmds,ctor}`, `BaseShape::findCollTri`, `Vector3f`, `StdSystem::stringDup`, `System::halt`, `Stream::print`, `AyuStack::push`; data `gsys`,`sysCon`), `KERNEL32.dll` (`GlobalAlloc`/`GlobalFree`), `MSVCRTD.dll` (debug-CRT), CRT startup objects under `build\intel\xdll_obj\` (`dllsupp/chkstk/crtdll/cinitexe/atonexit/adjustfd.obj`), the `linker defined module` synthetics, and `Debug/filterJmp.exp`.

---

## 3. plugAtxServer -- Windows-side "Age" property-editor SERVER

**19 files, 280 functions.** A standalone Win32 GUI app (uses `HWND`/`HDC`/`HMENU`/`HPEN`, USER32/GDI32) shipped as a plugin DLL. **Not** a DOL/PPC port -- the existing `include/Age.h` is the *game-side client* (`AgeServer : AtxStream`) that talks *to* this server and declares none of these classes. Dominant parallel hierarchies: `AtxService*`, `AgeNode*`, `AgeGadget*`, `*PropEvent`, and the tree/window UI (`TreeViewGadget`/`TreeViewLeaf`, `AgeView*`, `AgeWindow*`).

| Proposed source path | #fns | Primary class(es) |
|---|---|---|
| `src/plugAtxServer/attachModule.cpp` | 4 | *(DLL glue -- boilerplate)* |
| `src/plugAtxServer/sysNew.cpp` | 6 | *(global new/delete -- boilerplate)* |
| `src/plugAtxServer/atxServiceAge.cpp` | 11 | AtxServiceAge, AgeNode |
| `src/plugAtxServer/atxServiceFile.cpp` | 2 | AtxServiceFile |
| `src/plugAtxServer/ageWinNodes.cpp` | 18 | AgeWindowNodes/Tree, TreeViewLeaf |
| `src/plugAtxServer/ageWinPopup.cpp` | 5 | AgeWindowPopup |
| `src/plugAtxServer/ageWinSections.cpp` | 25 | AgeView{Leaf,Tree}, AgeWindowSections, AgeGadget base |
| `src/plugAtxServer/ageGadget.cpp` | 5 | AgeGadget |
| `src/plugAtxServer/ageGadgetBitGroup.cpp` | 7 | AgeGadgetBitGroup, AgeNodeBitGroup, FlagBit |
| `src/plugAtxServer/ageGadgetButton.cpp` | 20 | AgeGadgetButton, ButtonPropEvent, PropEvent base |
| `src/plugAtxServer/ageGadgetColour.cpp` | 21 | AgeGadgetColour, IntPropEvent, PropEditStringInfo |
| `src/plugAtxServer/ageGadgetEditor.cpp` | 42 | AgeGadgetEditorInt, {Short,Byte,Float}PropEvent |
| `src/plugAtxServer/ageGadgetLabel.cpp` | 1 | AgeGadgetLabel |
| `src/plugAtxServer/ageGadgetOptionBox.cpp` | 16 | AgeGadgetOptionBox, OptionBoxPropEvent |
| `src/plugAtxServer/ageGadgetString.cpp` | 5 | AgeGadgetString, StringPropEvent |
| `src/plugAtxServer/ageGadgetViewer.cpp` | 4 | AgeGadgetViewer |
| `src/plugAtxServer/attachPlugAtxServer.cpp` | 62 | *(factory/registration -- exports)* |
| `src/plugAtxServer/plugAtxServer.cpp` | 16 | AtxServerApp, AtxAppWindow |
| `src/plugAtxServer/treeViewGadget.cpp` | 10 | TreeViewGadget |

**Header note:** prefer a consolidated header cluster for the shared `AgeGadget`/`AgeNode`/`PropEvent` hierarchies rather than one header per `.cpp`. COMDAT placement crosses TUs -- e.g. `AgeGadgetLabel`'s ctor+vtable live in `attachPlugAtxServer.obj` (only `drawGadget` is in `ageGadgetLabel.obj`); most of `StringPropEvent` lives in `attachPlugAtxServer.obj`; `AgeGadget` base ctor/vtable partly in `ageWinSections.obj`.

### attachModule.cpp / sysNew.cpp *(boilerplate -- same as above)*

### atxServiceAge.cpp
- **AgeNode:** `createAgeGadget` [v], `getSectionCmds`, `getNodeCmds`, `AgeNode(char*)` ctor, `initialise` [v]
- **AtxServiceAge:** `invoke` [v], `doupdate` [v], `closedown` [v]
- **AtxService:** `closedown` [v]
- **AgeWinInfo:** `AgeWinInfo(char*, void*, AtxService*)` ctor
- *(free):* `createEditor(AtxService*, String&)` -> AgeNode*

### atxServiceFile.cpp
- **AtxServiceFile:** `invoke` [v], `doupdate` [v]

### ageWinNodes.cpp
- **AgeWindowNodes:** ctor, `init(AtxService*, AgeNode*)`, `processMessage` [v]
- **AgeWindowTree:** ctor, `processMessage` [v], `makeViewNodeList` [v]
- **AgeNodeWindowLeaf:** `handleNameClick` [v], ctor
- **TreeViewGadget:** ctor, `initViewNodeList` [v], `makeViewNodeList` [v]
- **TreeViewLeaf:** `TreeViewLeaf(char*)` ctor, `handleAreaMState` [v], `handleNameClick` [v], `drawInside` [v], `isAvailable` [v], `isHilighted` [v]
- **AtxServiceCreateAgeWindowNodes:** `invoke`

### ageWinPopup.cpp
- **AgeWindowPopup:** ctor, `init`, `updateValue(char*)`, `processMessage` [v]
- **AtxServiceCreateAgeWindowPopup:** `invoke` [v]

### ageWinSections.cpp
- **AgeViewLeaf:** `isHilighted` [v], `isAvailable` [v], `updateSheet`, `refreshNode`, `handleNameClick` [v], `handleAreaMState` [v], `drawInside` [v], ctor
- **AgeViewTree:** `handleClick` [v], `processMessage` [v], `initViewNodeList` [v], `makeGadgets`, `makeGNodeGadgets`, `makeViewSection` [v], `makeViewNodeList` [v], ctor
- **AgeWindowSections:** ctor, `init(AtxService*, AgeNode*)`, `processMessage` [v]
- **AgeGadget (base):** default ctor, `acceptKey` [v], `acceptMove` [v], `finishCall` [v], `invoke` [v]
- **AtxServiceCreateAgeWindowSections:** `invoke`

### ageGadget.cpp
- **AgeGadget:** `AgeGadget(int,int,char*)` ctor, `acceptClick` [v], `invalidateRect` [v], `drawGadget` [v]
- *(free):* `serviceAgeInvoke(AgeGadget*)` -> ulong

### ageGadgetBitGroup.cpp
- **AgeGadgetBitGroup:** ctor, `drawGadget` [v], `updateBits`, `acceptClick` [v], `invoke` [v]
- **AgeNodeBitGroup:** `initialise` [v]
- **FlagBit:** `FlagBit(String,int,int)` ctor

### ageGadgetButton.cpp
- **AgeGadgetButton:** ctor, `drawGadget` [v], `invoke` [v], `finishCall` [v]
- **AgeNodeButton:** `initialise` [v]
- **ButtonPropEvent:** ctor, `read` [v], `write` [v]
- **PropEvent (base):** ctor + `getRange`, `getNumItems`, `getCurrItem`, `igetValue`, `getValue`, `setValue`, `getPercentage`, `setPercentage`, `getMaxStringLen`, `genValueString`, `setString` (all [v])

### ageGadgetColour.cpp
- **AgeGadgetColour:** ctor, `percToPos`, `posToPerc`, `drawGadget` [v], `acceptKey` [v], `acceptMove` [v], `acceptClick` [v], `invoke` [v]
- **AgeNodeColour:** `initialise` [v]
- **IntPropEvent:** ctor + `getRange`, `setValue`, `getValue`, `setPercentage`, `getPercentage`, `genValueString`, `setString`, `read`, `write` (all [v])
- **PropEditStringInfo:** ctor, `set(PropEvent*, RectArea*, AgeGadget*)`

### ageGadgetEditor.cpp *(largest gadget TU)*
- **AgeGadgetEditorInt:** ctor, `percToPos`, `posToPerc`, `drawGadget` [v], `acceptKey` [v], `acceptMove` [v], `acceptClick` [v], `invoke` [v]
- **AgeNodeEditor{Int,Short,Byte,Float}:** `initialise` [v] (each)
- **ShortPropEvent / BytePropEvent / FloatPropEvent:** ctor + `getRange`, `setValue`, `getValue`, `setPercentage`, `getPercentage`, `genValueString`, `setString`, `read`, `write` (all [v], each type)

### ageGadgetLabel.cpp
- **AgeGadgetLabel:** `drawGadget` [v] *(ctor + vtable are in `attachPlugAtxServer.obj`, not here)*

### ageGadgetOptionBox.cpp
- **AgeGadgetOptionBox:** ctor, `drawGadget` [v], `updateBits`, `acceptClick` [v], `invoke` [v], `finishCall` [v]
- **AgeNodeOptionBox:** `initialise` [v]
- **OptionBoxPropEvent:** ctor, `genValueString` [v], `setString` [v], `lsetValue`, `igetValue` [v], `getCurrItem` [v], `getNumItems` [v], `read` [v], `write` [v]

### ageGadgetString.cpp
- **AgeGadgetString:** ctor, `drawGadget` [v], `acceptClick` [v], `invoke` [v]
- **StringPropEvent:** `write` [v] *(most of the class lives in `attachPlugAtxServer.obj`)*

### ageGadgetViewer.cpp
- **AgeGadgetViewer:** ctor, `drawGadget` [v], `invoke` [v]
- **PropEvent:** `sendRead(Stream*)`

### attachPlugAtxServer.cpp *(factory/registration; 3 validated DLL exports; 20 vtables)*
- *(free factories):* `newAtxServer`, `newAtxServiceFile`, `newAtxServiceAge`, `newAgeNodeEditor{Int,Short,Byte,Float}`, `newAgeNode{Colour,BitGroup,OptionBox,Label,Button,Viewer,String}`, `newAgeWindow{Nodes,Sections,Popup}`
- **exports:** `NewObject`, `GetObjectList`, `AutoStart`
- **AtxService (base):** ctor, `invoke` [v], `doupdate` [v]
- *service ctors:* **AtxServiceFile**, **AtxServiceAge**, **AtxServiceCreateAgeWindow{Nodes,Sections,Popup}**
- **AgeNode (base):** default ctor
- *node ctors + `createAgeGadget` [v] overrides:* **AgeNodeEditorNum** (ctor only), **AgeNodeEditor{Int,Short,Byte,Float}**, **AgeNode{Colour,BitGroup,OptionBox,Button}** (ctor + createAgeGadget each); **AgeNodeLabel** (ctor, `initialise` [v], createAgeGadget [v]); **AgeNodeViewer** / **AgeNodeString** (ctor, `initialise` [v], createAgeGadget [v] each)
- **AgeGadgetLabel:** `AgeGadgetLabel(int,int,char*)` ctor
- **StringPropEvent:** ctor, `setString` [v], `getMaxStringLen` [v], `genValueString` [v], `read` [v]
- **ObjectHandle:** ctor

### plugAtxServer.cpp *(app shell; holds 18 shared GDI pen/brush/icon globals)*
- **AtxServerApp:** `idle` [v], ctor, `\`vector deleting destructor\``, `\`scalar deleting destructor\``, `~AtxServerApp`
- **AtxAppWindow:** ctor, `createWindow` [v], `update` [v], `routeAll`, `processMessage` [v], `addService`, `connectNew`
- **TreeNodeMenu:** `TreeNodeMenu(AtxService*)` ctor, `handleNameClick` [v]
- **DataTreeView:** ctor, `makeViewNodeList` [v]

### treeViewGadget.cpp
- **TreeViewGadget:** `createWindow` [v], `recCalcSize`, `calcSize`, `autoSize`, `updateSizes` [v], `showTree`, `handleClick` [v], `recHandleClick`, `processMessage` [v]
- *(free):* `drawOutline(HDC,int,int,int,int,HPEN,HPEN)`

**NOT files to create:** `sysCore.dll` (163 symbols -- `String`/`Stream`/`Node`/`UIWindow`/`RectArea`/`Delegate`/`Colour`/math base classes + COMDAT inlines), `KERNEL32.dll` (2), `USER32.dll` (21), `GDI32.dll` (13), `MSVCRTD.dll` (15), VC6 CRT-DLL startup objs `crtdll/cinitexe/atonexit.obj` under `build\intel\xdll_obj\`, and the `linker defined module` synthetics. (Link-order 20 is the empty `.exp`/import-stub slot; order 21 is `sysCore.dll`.)

---

## 4. plugTexConv -- texture/model converter + DMD importer (Win32 authoring tool)

**8 files, 268 functions.** A standalone MSVC tool linking against `sysCore.dll`; exports the standard `AutoStart`/`GetObjectList`/`NewObject`. Dominated by two large TUs. **Data-integrity caveat:** `filtDmdImport.obj` is a **stale relink generation absent from the module (contribution) table** (the table jumps mod-index 3 -> 5), but it owns 406 symbols / 123 functions via per-symbol attribution and is the single largest file -- any tool that reads own-TUs from the module table alone will miss it. Trust per-symbol `obj`.

| Proposed source path | #fns | Primary class(es) |
|---|---|---|
| `src/plugTexConv/attachModule.cpp` | 4 | *(DLL glue -- boilerplate)* |
| `src/plugTexConv/sysNew.cpp` | 6 | *(global new/delete -- boilerplate)* |
| `src/plugTexConv/collCreator.cpp` | 6 | CollCreator |
| `src/plugTexConv/filtDmdImport.cpp` | 123 | ConvModel, RouteGroupEdit, DmdImportFilter |
| `src/plugTexConv/fileTga.cpp` | 11 | TgaHeader, TgaBody, TgaImage |
| `src/plugTexConv/attachPlugTexConv.cpp` | 8 | *(plugin registration -- exports)* |
| `src/plugTexConv/parameters.cpp` | 26 | Parameters, BaseParm, Parm\<T\> |
| `src/plugTexConv/plugTexConv.cpp` | 84 | TexConvApp, BundleMgr, ModelDataMgr |

**Template caveat:** the `Parm<T>`, `Delegate`/`Delegate1`/`Delegate2`/`IDelegate`, and `FixedString<N>` instantiations listed below are COMDAT expansions of templates that in source live in shared *headers* -- define them in headers and let the compiler re-emit; do not create one file per instantiation. Also: `plugTexConv.res` (compiled resource -- a scaffolder may want a `.rc`), `Debug/plugTexConv.exp`, and the stale `.exp` are not `.cpp` TUs.

### attachModule.cpp / sysNew.cpp *(boilerplate -- same as above)*

### collCreator.cpp
- **CollCreator:** `countCollTris`, `makeCollInfos`, `findConnections`, `createCollGrid(RandomAccessStream&)`, `createCollisions(BaseShape*)`
- *(free):* `operator==(Vector3f const&, Vector3f const&)` -> bool
- *(note: `CollCreator` ctor is emitted in `filtDmdImport.obj` -- share the header)*

### filtDmdImport.cpp *(LARGEST TU; ConvModel ~ 85 fns; 13 vtables)*
- **ConvModel:** parse group -- `parseMaterial`, `parseTexAttr`, `parseJoint`, `parseVtxMatrix`, `parseTexImg`, `parseMesh`, `checkShapeFlags`, `ConvModel(char*, CmdStream*)` ctor; get group -- `getVertices`, `getColours`, `getTexCoords`, `getMakeNBTs`, `getNormals`, `getVtxMatrix`, `getEnvelope`, `getInformation`; import group -- `importDVW`, `ageImportDVW`, `importJMP`, `ageImportJMP`, `loadIni`, `loadIniButton`, `saveIniButton`, `doImportAnimFolder`, `loadAnim`; export group -- `exportMod`, `exportJointEnums`, `exportModFile`, `exportInfo`, `startChunk`, `finishChunk`, `exportShapeInfo`, `exportVtxs`, `exportCols`, `exportNorms`, `exportBiNorms`, `exportTexUVs`, `exportTexImgs`, `exportTexAttrs`, `exportTexNames`, `exportMaterials`, `exportEnvelopes`, `exportVtxMatrixs`, `exportMeshes`, `exportJoints`, `exportJointNames`, `exportCollInfo`, `exportCollGrid`, `exportBundle`, `removeMtx`; AgeServer UI group -- `genAge` [v], `sectionAnimList`, `importAnimationButton`, `importAnimFolderButton`, `sectionAnimChange`, `newCollInfoButton`, `newLightGroupButton`, `ageDelAllLights`, `ageRefreshNode`, `ageModelFuncs`, `exportModButton`, `exportModAsButton`, `addVertexColours`, `removeMtxButton`, `deleteButton`, `outputLineGraph`, `ageNewRoute`, `recCreateObjCollInfoSection`; render -- `update` [v], `render` [v], `recDrawJoints`, `render2d` [v], `makeRouteGroup` [v], `msgCommand` [v]; local-class `outputLineGraph()::EdgeInfo::EdgeInfo`
- **RouteGroupEdit:** `makeNewPoint`, `makeRouteLink`, `findRoutePoint`, `findIntersection`, `triPosFromMouse`, `worldPosFromMouse`, `delRoutePoint`, `msgCommand` [v], `ageRefreshSection`, `genAge` [v], `ageChangeID`, ctor
- **DmdImportFilter:** `importFile(char*, DataMgr*)` [v]
- **RoomMatHandler:** ctor, `setMaterial` [v]
- **CollCreator / CollisionData:** ctor (each)
- *(free `parseFormat*`):* `parseFormatS3TC`, `parseFormatRGB5A3`, `parseFormatRGB565`, `parseFormatRGBA8`, `parseFormatI4`, `parseFormatI8`, `parseFormatIA4`, `parseFormatIA8`
- *(free Vector3f operators):* `operator+`, `operator-`, `operator*`
- *template instantiations (header-defined):* `Delegate1<{RouteGroupEdit,ConvModel,ObjCollInfo,RouteGroup,LightGroup},AgeServer&>` ctor+invoke; `Delegate<RouteGroupEdit>` ctor+invoke; `Delegate2<ConvModel,char*,uint>` ctor+invoke; `IDelegate`/`IDelegate1<AgeServer&>`/`IDelegate2<char*,uint>` ctors; `FixedString<0x800>`, `FixedString<0x80>` ctors; `\`vcall\`` thunk

### fileTga.cpp
- **TgaHeader:** `ReadHeader(RandomAccessStream&)`, `Print`
- **TgaBody:** `ReadBody(RandomAccessStream&, TgaHeader*)`, `Print`
- **TgaImage:** `ReadImage(char*)` -> bool, `Width`, `Height`, `Bpp`, `Data`, `ConvToRGBA32`, `ConvToInternal(Texture*)`

### attachPlugTexConv.cpp *(3 validated DLL exports)*
- *(free):* `newTexConv()`, `newDmdImportFilter()`; **exports** `NewObject`, `GetObjectList`, `AutoStart`
- **DmdImportFilter:** ctor
- **ImportFilter:** ctor
- **ObjectHandle:** ctor

### parameters.cpp *(AgeServer-driven parameter serialization)*
- **BaseParm:** `BaseParm(Parameters*, ayuID)` ctor, `genAge` [v], `write` [v], `read` [v]
- **Parameters:** `write`, `sizeInFile`, `read`, `genAgeParms`, `genAge`
- **Parm\<Colour\> / Parm\<Vector3f\> / Parm\<float\> / Parm\<int\> / Parm\<String\>:** `read` [v], `genAge` [v], `write` [v] (each)
- **ayuID:** ctor, `Num()`

### plugTexConv.cpp *(GUI app; 14 vtables; ICF folds `TexConvApp` ??_E/??_G at one RVA)*
- **TexConvApp:** `idle` [v], `genAge` [v], ctor, `\`vector deleting destructor\``, `\`scalar deleting destructor\``, `~TexConvApp`
- **BundleMgr:** `genAge`, `convertBtiButton`, `doConvertTexture`, `bundleTexFolderButton`, `doBundleFolder`, `loadFile`, `copyFile`, `bundlePcrFolderButton`, `bundleBloFolderButton`, `bundleAllFolderButton`, `doArchiveFolder`, `bundleBinFolderButton`, ctor
- **BundleNode:** `BundleNode(char*)` ctor, default ctor
- **TexAppWindow:** ctor, `update` [v], `processMessage` [v]
- **TexViewWindow:** ctor, `setTexture`, `processMessage` [v], `createWindow` [v]
- **WorkArea:** `Refresh`, `Width`, `Height`, `WorkArea(HWND,int,int,int)` ctor, `CopyImage`, `Bpp`
- **ModelDataMgr:** ctor, `update` [v], `render` [v], `addCommand` [v, varargs], `clearCommands` [v], `saveCommands` [v], `genAge` [v], `ageDataMgrSection`, `importModelButton`, `importModel`, `convClearCommands`, `loadCNVfileButton`, `loadCNVfile`, `saveCNVfile`, `convFolderButton`; nested `Parms::Parms` ctor, `ConvCommand::ConvCommand` ctor, `ConvCommand::set`
- **ViewUserWindow:** ctor, `processMessage` [v], `update` [v], `draw` [v]
- **FilterType:** default ctor, `FilterType(char*,char*)` ctor, `initType`
- *Msg ctors:* **MsgCommand**, **MsgParseCommand**, **MsgMouseMove**, **MsgLeftDown**, **MsgLeftUp**, **MsgRightDown**, **MsgRightUp**, **DataMsg**
- *other ctors:* **ayuID(char*)** + `Set`, **Parameters(char*)**, **DataMgr**, **TgaImage**, **TgaBody**
- *template instantiations:* **Parm\<String\>** ctor + `size` [v]; `FixedString<0x200>` ctor; `Delegate2<ModelDataMgr,...>` / `Delegate1<ModelDataMgr,AgeServer&>` / `Delegate2<BundleMgr,...>` / `Delegate1<BundleMgr,AgeServer&>` ctor+invoke

**NOT files to create:** `sysCore.dll` (458 symbols -- imports + COMDAT template/inline expansions: `Vector3f`/`Matrix`/containers, `UIWindow`, `AgeServer`, `RandomAccessStream`, `String`, ...), `KERNEL32/USER32/GDI32/MSVCRTD.dll`, VC6 CRT/DLL-startup objs under `build\intel\{xdll_obj,st_obj}\` (`chkstk/crtdll/atonexit/cinitexe/dllsupp/adjustfd.obj`, `strdup.obi`), the `linker defined module` + empty-name synthetics, `plugTexConv.res` (compiled resource), and `Debug/plugTexConv.exp`.

---

## 5. sysBootup -- Win32 GUI bootstrapper (single-file .exe)

**1 file, 10 functions.** The sole own TU is `.\Debug\sysBootup.obj`; the other cmdline entry, `.\Debug\sysBootup.res`, is a compiled menu resource, not a `.cpp`. Only **3 of the 10** functions are hand-authored; the other 7 are compiler/inline-emitted COMDATs that merely landed here.

| Proposed source path | #fns | Primary class(es) |
|---|---|---|
| `src/win/sysBootup.cpp` *(see collision note)* | 10 | SysWindow, WinMain |

**Path collision:** a `src/sysBootup.cpp` **already exists** -- but it's the DOL/PPC build (a ~15-line `main()`: `gsys->Initialise` / `new NodeMgr` / `run(new PlugPikiApp)`). This Win32 TU is a completely different `WinMain` GUI bootstrapper, so it must **not** overwrite the DOL file -- put it at a platform-scoped path (e.g. `src/win/sysBootup.cpp`) or split with `#ifdef _WIN32`. Optional `include/SysWindow.h` (`SysWindow` is small and self-contained, defining its own vtable -- a header is reasonable but not required).

### sysBootup.cpp
**Hand-authored (3):**
- *(global)* `WinMain(HINSTANCE, HINSTANCE, char*, int)` -- `__stdcall` entry, largest fn (~0x251 bytes). Reads `config.ini`, sets `Basedir`, creates `atxDirectRouter`, scans a plugins dir for `*.dll`, boots the "OpenGL / Dolphin System", opens the main "DUIClearWin" window.
- **SysWindow:** `SysWindow(UIWindow*, int, int, int, bool)` ctor *(derives from sysCore's `UIWindow`)*, `processMessage(HWND, uint, uint, long)` [virtual window-proc override]

**Compiler/inline-emitted COMDATs -- expect these to appear, do NOT hand-author (7):**
- `UIMgr::\`scalar deleting destructor\``, `ModuleMgr::\`scalar deleting destructor\``, `NodeMgr::\`scalar deleting destructor\`` *(sysCore classes; landed here from `delete` expressions)*
- `speedy_sqrtf`, `sqrtf` *(shared math-header inlines)*
- `\`vector constructor iterator\`` *(MSVC helper)*
- `MenuPlugin::MenuPlugin()` *(inline default ctor of a non-owned class, emitted because sysBootup constructs a MenuPlugin)*

**Data (not source):** 19 symbols = 1 vtable `??_7SysWindow` + 18 `??_C` string constants (no RTTI, no named globals).

**NOT files to create:** `.\Debug\sysBootup.res` (menu resource), `sysCore.dll` (~64 import stubs -- `System`, `UIMgr`, `ModuleMgr`, `NodeMgr`, `UIWindow` + virtuals, `UIFrame`, `Node`/`CoreNode`, `Module::menuPlugins`, `CmdStream`, `Stream::print`, `RamStream`, `RectArea`, `AtxDirectRouter`), `USER32.dll` (`MessageBoxA`/`ShowWindow`/`LoadMenuA`/`GetSubMenu`/`GetMenu`), `KERNEL32.dll` (`GetModuleHandleA`/`GetStartupInfoA`), `MSVCRTD.dll` (CRT), the VC6 CRT startup objects under `build\intel\{xdll_obj,st_obj}\` (`crtexew`/`atonexit`/`cinitexe`/`dllargv`/`dllsupp`/`fp8`/`merr`/`wildcard`/`_newmode`/`xncommod`/`xtxtmode`/`adjustfd.obj`, `oldnames\strdup.obi`), and the 5 linker-defined sentinels. Note this is an `.exe`: no export table (`AutoStart`/`GetObjectList`/`NewObject` do not apply).

---

## How to wire a module in

For each new module, two things register it, then the `.ilk`-derived map does the rest:

1. **Add a `MODULES` entry in `configure_win.py`** naming the module and pointing at its `src/<module>/` directory (create the dir and drop in the `.cpp` files above). This is what makes `configure_win` emit the module's ninja build + `.link`/objdiff targets.
2. **Run the 5-step `.ilk` integration** for the module. It consumes the shipped `.ilk` (the same ground-truth source these worklists came from) and produces the module's **objdiff target** (so each function can be diffed against the shipped binary) and the **completeness denominator** (the true own-function inventory -- 121 for filterDvw, 18 for filterJmp, 280 for plugAtxServer, 268 for plugTexConv, 10 for sysBootup -- against which coverage is measured).

Reminder while scaffolding: create files only for the `kind=cmdline` `.\Debug\<stem>.obj` TUs listed as "own TUs". Everything under `sysCore.dll`, the Win32 SDK import libs (`KERNEL32`/`USER32`/`GDI32`/`MSVCRTD`), the VC6 CRT startup objects (`build\intel\...`), the `.exp` export stubs, `.res` resources, and the `linker defined module` synthetics is **not source** -- leave it to the linker/toolchain. And for `filtDmdImport` specifically, remember it is a real own TU even though it is missing from the module table (recover it by per-symbol `obj`, never by the contribution table alone).