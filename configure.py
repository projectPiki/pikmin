LIBS = [
    {
        "lib": "sysBootup",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["sysBootup", True],
        ],
    },
    {
        "lib": "jaudio",
        "cflags": "$cflags_pikmin -func_align 32 -lang c++",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["jaudio/dummyprobe", True],
            ["jaudio/memory", False],
            ["jaudio/aictrl", False],
            ["jaudio/sample", False],
            ["jaudio/dummyrom", False],
            ["jaudio/audiothread", False],
            ["jaudio/audiothread_fakebss", False],
            ["jaudio/streamctrl", False],
            ["jaudio/dspbuf", False],
            ["jaudio/cpubuf", False],
            ["jaudio/playercall", False],
            ["jaudio/dvdthread", False],
            ["jaudio/audiomesg", False],
            ["jaudio/rate", False],
            ["jaudio/stackchecker", False],
            ["jaudio/dspboot", False],
            ["jaudio/dspproc", False],
            ["jaudio/ipldec", False],
            ["jaudio/dsp_cardunlock", False],
            ["jaudio/driverinterface", False],
            ["jaudio/dspdriver", False],
            ["jaudio/dspinterface", False],
            ["jaudio/fxinterface", False],
            ["jaudio/bankread", False],
            ["jaudio/waveread", False],
            ["jaudio/connect", False],
            ["jaudio/tables", False],
            ["jaudio/bankdrv", False],
            ["jaudio/random", False],
            ["jaudio/aramcall", False],
            ["jaudio/ja_calc", False],
            ["jaudio/fat", False],
            ["jaudio/cmdstack", False],
            ["jaudio/virload", False],
            ["jaudio/heapctrl", False],
            ["jaudio/jammain_2", False],
            ["jaudio/midplay", False],
            ["jaudio/noteon", False],
            ["jaudio/seqsetup", False],
            ["jaudio/centcalc", False],
            ["jaudio/jamosc", False],
            ["jaudio/oneshot", False],
            ["jaudio/interface", False],
            ["jaudio/verysimple", False],
            ["jaudio/app_inter", False],
            ["jaudio/pikiinter", False],
            ["jaudio/piki_player", False],
            ["jaudio/piki_bgm", False],
            ["jaudio/piki_scene", False],
            ["jaudio/pikidemo", False],
            ["jaudio/file_seq", False],
            ["jaudio/cmdqueue", False],
            ["jaudio/filter3d", True],
            ["jaudio/syncstream", False],
            ["jaudio/bankloader", False],
            ["jaudio/interleave", False],
            ["jaudio/pikiseq", False],
            ["jaudio/hplaybss", False],
            ["jaudio/hplaybss2", False],
            ["jaudio/hvqm_play", False],
        ],
    },
    {
        "lib": "hvqm4dec",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["hvqm4dec/hvqm4dec", False],
        ],
    },
    {
        "lib": "sysCommon",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["sysCommon/ayuStack", False],
            ["sysCommon/baseApp", False],
            ["sysCommon/stream", False],
            ["sysCommon/streamBufferedInput", False],
            ["sysCommon/string", True],
            ["sysCommon/graphics", False],
            ["sysCommon/grLight", False],
            ["sysCommon/shapeBase", False],
            ["sysCommon/shpLightFlares", False],
            ["sysCommon/shpObjColl", False],
            ["sysCommon/shpRoutes", False],
            ["sysCommon/sysMath", False],
            ["sysCommon/matMath", False],
            ["sysCommon/stdSystem", False],
            ["sysCommon/node", False],
            ["sysCommon/timers", True],
            ["sysCommon/controller", False],
            ["sysCommon/cmdStream", False],
            ["sysCommon/camera", False],
            ["sysCommon/atx", False],
            ["sysCommon/id32", False],
        ],
    },
    {
        "lib": "sysDolphin",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["sysDolphin/texture", False],
            ["sysDolphin/system", False],
            ["sysDolphin/sysNew", False],
            ["sysDolphin/controllerMgr", False],
            ["sysDolphin/dgxGraphics", False],
            ["sysDolphin/gameApp", True],
        ],
    },
    {
        "lib": "plugPikiColin",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiColin/cardutil", False],
            ["plugPikiColin/dynsimulator", False],
            ["plugPikiColin/animMgr", False],
            ["plugPikiColin/gameflow", False],
            ["plugPikiColin/game", False],
            ["plugPikiColin/gamePrefs", False],
            ["plugPikiColin/gameSetup", False],
            ["plugPikiColin/cardSelect", False],
            ["plugPikiColin/mapSelect", False],
            ["plugPikiColin/newPikiGame", False],
            ["plugPikiColin/introGame", False],
            ["plugPikiColin/gameExit", False],
            ["plugPikiColin/gauges", False],
            ["plugPikiColin/genMapObject", False],
            ["plugPikiColin/gui", False],
            ["plugPikiColin/parameters", False],
            ["plugPikiColin/plugPiki", False],
            ["plugPikiColin/titles", False],
            ["plugPikiColin/ninLogo", False],
            ["plugPikiColin/mapMgr", False],
            ["plugPikiColin/dayMgr", False],
            ["plugPikiColin/cinePlayer", False],
            ["plugPikiColin/lightPool", False],
            ["plugPikiColin/memoryCard", False],
            ["plugPikiColin/moviePlayer", False],
            ["plugPikiColin/movSample", False],
        ],
    },
    {
        "lib": "plugPikiKando",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiKando/omake", False],
            ["plugPikiKando/radarInfo", False],
            ["plugPikiKando/interactBattle", False],
            ["plugPikiKando/interactGrab", False],
            ["plugPikiKando/interactEtc", False],
            ["plugPikiKando/interactPullout", False],
            ["plugPikiKando/saiEvents", False],
            ["plugPikiKando/simpleAI", False],
            ["plugPikiKando/formationMgr", False],
            ["plugPikiKando/globalShapes", True],
            ["plugPikiKando/playerState", False],
            ["plugPikiKando/gameDemo", False],
            ["plugPikiKando/demoInvoker", False],
            ["plugPikiKando/demoEvent", False],
            ["plugPikiKando/resultFlag", False],
            ["plugPikiKando/aiConstants", False],
            ["plugPikiKando/kio", False],
            ["plugPikiKando/keyConfig", False],
            ["plugPikiKando/aiPerf", False],
            ["plugPikiKando/courseDebug", False],
            ["plugPikiKando/memStat", False],
            ["plugPikiKando/collInfo", False],
            ["plugPikiKando/complexCreature", False],
            ["plugPikiKando/creature", False],
            ["plugPikiKando/creatureCollision", False],
            ["plugPikiKando/creatureCollPart", False],
            ["plugPikiKando/creatureMove", False],
            ["plugPikiKando/creatureStick", False],
            ["plugPikiKando/dualCreature", False],
            ["plugPikiKando/dynCreature", False],
            ["plugPikiKando/eventListener", True],
            ["plugPikiKando/fastGrid", False],
            ["plugPikiKando/ropeCreature", False],
            ["plugPikiKando/objectTypes", True],
            ["plugPikiKando/pelletMgr", False],
            ["plugPikiKando/animPellet", False],
            ["plugPikiKando/genPellet", False],
            ["plugPikiKando/pelletState", False],
            ["plugPikiKando/workObject", False],
            ["plugPikiKando/routeMgr", False],
            ["plugPikiKando/seMgr", False],
            ["plugPikiKando/seConstants", False],
            ["plugPikiKando/soundMgr", False],
            ["plugPikiKando/updateMgr", False],
            ["plugPikiKando/cPlate", False],
            ["plugPikiKando/aiStone", False],
            ["plugPikiKando/aiActions", False],
            ["plugPikiKando/aiAttack", False],
            ["plugPikiKando/aiBore", False],
            ["plugPikiKando/aiBoMake", False],
            ["plugPikiKando/aiBou", False],
            ["plugPikiKando/aiBridge", False],
            ["plugPikiKando/aiBreakWall", False],
            ["plugPikiKando/aiTransport", False],
            ["plugPikiKando/aiKinoko", False],
            ["plugPikiKando/aiChase", False],
            ["plugPikiKando/aiCrowd", False],
            ["plugPikiKando/aiDecoy", False],
            ["plugPikiKando/aiEnter", False],
            ["plugPikiKando/aiEscape", False],
            ["plugPikiKando/aiExit", False],
            ["plugPikiKando/aiMine", False],
            ["plugPikiKando/aiFormation", False],
            ["plugPikiKando/aiFree", False],
            ["plugPikiKando/aiGoto", False],
            ["plugPikiKando/aiGuard", False],
            ["plugPikiKando/aiPick", False],
            ["plugPikiKando/aiPickCreature", False],
            ["plugPikiKando/aiPullout", False],
            ["plugPikiKando/aiPush", False],
            ["plugPikiKando/aiPut", False],
            ["plugPikiKando/aiRandomBoid", False],
            ["plugPikiKando/aiRescue", False],
            ["plugPikiKando/aiRope", False],
            ["plugPikiKando/aiShoot", False],
            ["plugPikiKando/aiWatch", False],
            ["plugPikiKando/aiWeed", False],
            ["plugPikiKando/aiTable", False],
            ["plugPikiKando/aiAction", False],
            ["plugPikiKando/pikiInf", False],
            ["plugPikiKando/piki", False],
            ["plugPikiKando/odoMeter", True],
            ["plugPikiKando/pikidoKill", False],
            ["plugPikiKando/pikiMgr", False],
            ["plugPikiKando/pikiState", False],
            ["plugPikiKando/viewPiki", False],
            ["plugPikiKando/conditions", False],
            ["plugPikiKando/generator", False],
            ["plugPikiKando/generatorCache", False],
            ["plugPikiKando/objectMgr", False],
            ["plugPikiKando/searchSystem", False],
            ["plugPikiKando/smartPtr", True],
            ["plugPikiKando/itemGem", False],
            ["plugPikiKando/weedsItem", False],
            ["plugPikiKando/kusaItem", False],
            ["plugPikiKando/fishItem", False],
            ["plugPikiKando/ufoItem", False],
            ["plugPikiKando/ufoAnim", False],
            ["plugPikiKando/bombItem", False],
            ["plugPikiKando/goalItem", False],
            ["plugPikiKando/pikiheadItem", False],
            ["plugPikiKando/keyItem", False],
            ["plugPikiKando/ropeItem", False],
            ["plugPikiKando/seedItem", False],
            ["plugPikiKando/genItem", False],
            ["plugPikiKando/itemAI", False],
            ["plugPikiKando/itemMgr", False],
            ["plugPikiKando/itemObject", False],
            ["plugPikiKando/mizuItem", False],
            ["plugPikiKando/paniItemAnimator", False],
            ["plugPikiKando/genNavi", False],
            ["plugPikiKando/navi", False],
            ["plugPikiKando/naviState", False],
            ["plugPikiKando/naviDemoState", False],
            ["plugPikiKando/gameCoreSection", False],
            ["plugPikiKando/gmWin", False],
            ["plugPikiKando/gameStat", False],
            ["plugPikiKando/kmath", False],
            ["plugPikiKando/uteffect", False],
            ["plugPikiKando/kontroller", False],
            ["plugPikiKando/mapcode", True],
            ["plugPikiKando/utkando", False],
            ["plugPikiKando/naviMgr", False],
            ["plugPikiKando/genMapParts", False],
            ["plugPikiKando/mapParts", False],
            ["plugPikiKando/panipikianimator", False],
            ["plugPikiKando/actor", False],
            ["plugPikiKando/actorMgr", False],
            ["plugPikiKando/genActor", False],
            ["plugPikiKando/pikiInfo", True],
            ["plugPikiKando/plantMgr", False],
            ["plugPikiKando/paniPlantAnimator", False],
        ],
    },
    {
        "lib": "plugPikiNakata",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiNakata/genteki", False],
            ["plugPikiNakata/nakatacode", False],
            ["plugPikiNakata/nlibfunction", False],
            ["plugPikiNakata/nlibgeometry", False],
            ["plugPikiNakata/nlibgeometry3d", False],
            ["plugPikiNakata/nlibgraphics", False],
            ["plugPikiNakata/nlibmath", False],
            ["plugPikiNakata/nlibspline", False],
            ["plugPikiNakata/nlibsystem", False],
            ["plugPikiNakata/panianimator", False],
            ["plugPikiNakata/panipikianimmgr", False],
            ["plugPikiNakata/panitekianimator", False],
            ["plugPikiNakata/panitestsection", False],
            ["plugPikiNakata/paraparameters", False],
            ["plugPikiNakata/pcamcamera", False],
            ["plugPikiNakata/pcamcameramanager", False],
            ["plugPikiNakata/pcammotionevents", False],
            ["plugPikiNakata/pcamcameraparameters", False],
            ["plugPikiNakata/peve", False],
            ["plugPikiNakata/peveconditions", False],
            ["plugPikiNakata/pevemotionevents", False],
            ["plugPikiNakata/tai", False],
            ["plugPikiNakata/taiattackactions", False],
            ["plugPikiNakata/taibasicactions", False],
            ["plugPikiNakata/taichappy", False],
            ["plugPikiNakata/taicollec", False],
            ["plugPikiNakata/taicollisionactions", False],
            ["plugPikiNakata/taieffectactions", False],
            ["plugPikiNakata/taiiwagen", False],
            ["plugPikiNakata/taijudgementactions", False],
            ["plugPikiNakata/taikinoko", False],
            ["plugPikiNakata/taimessageactions", False],
            ["plugPikiNakata/taimizinko", False],
            ["plugPikiNakata/taimotionactions", False],
            ["plugPikiNakata/taimoveactions", False],
            ["plugPikiNakata/tainapkid", False],
            ["plugPikiNakata/taiotimoti", False],
            ["plugPikiNakata/taipalm", False],
            ["plugPikiNakata/taireactionactions", False],
            ["plugPikiNakata/taiswallow", False],
            ["plugPikiNakata/taishell", False],
            ["plugPikiNakata/taitimeractions", False],
            ["plugPikiNakata/taiwaitactions", False],
            ["plugPikiNakata/teki", False],
            ["plugPikiNakata/tekianimationmanager", False],
            ["plugPikiNakata/tekibteki", False],
            ["plugPikiNakata/tekiconditions", False],
            ["plugPikiNakata/tekievent", True],
            ["plugPikiNakata/tekiinteraction", False],
            ["plugPikiNakata/tekimgr", False],
            ["plugPikiNakata/tekinakata", False],
            ["plugPikiNakata/tekinteki", False],
            ["plugPikiNakata/tekiparameters", False],
            ["plugPikiNakata/tekipersonality", False],
            ["plugPikiNakata/tekistrategy", False],
        ],
    },
    {
        "lib": "plugPikiNishimura",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiNishimura/genBoss", False],
            ["plugPikiNishimura/Boss", False],
            ["plugPikiNishimura/BossAnimMgr", False],
            ["plugPikiNishimura/BossCnd", False],
            ["plugPikiNishimura/BossMgr", False],
            ["plugPikiNishimura/BossShapeObj", False],
            ["plugPikiNishimura/Spider", False],
            ["plugPikiNishimura/SpiderAi", False],
            ["plugPikiNishimura/SpiderLeg", False],
            ["plugPikiNishimura/Snake", False],
            ["plugPikiNishimura/SnakeAi", False],
            ["plugPikiNishimura/SnakeBody", False],
            ["plugPikiNishimura/Slime", False],
            ["plugPikiNishimura/SlimeAi", False],
            ["plugPikiNishimura/SlimeBody", False],
            ["plugPikiNishimura/SlimeCreature", False],
            ["plugPikiNishimura/King", False],
            ["plugPikiNishimura/KingAi", False],
            ["plugPikiNishimura/KingBody", False],
            ["plugPikiNishimura/Kogane", False],
            ["plugPikiNishimura/KoganeAi", False],
            ["plugPikiNishimura/Pom", False],
            ["plugPikiNishimura/PomAi", False],
            ["plugPikiNishimura/KingBack", False],
            ["plugPikiNishimura/Nucleus", False],
            ["plugPikiNishimura/NucleusAi", False],
            ["plugPikiNishimura/CoreNucleus", False],
            ["plugPikiNishimura/CoreNucleusAi", False],
            ["plugPikiNishimura/Mizu", False],
            ["plugPikiNishimura/MizuAi", False],
            ["plugPikiNishimura/nscalculation", False],
            ["plugPikiNishimura/RumbleData", False],
            ["plugPikiNishimura/HmRumbleMgr", False],
            ["plugPikiNishimura/HmRumbleSample", True],
        ],
    },
    {
        "lib": "plugPikiOgawa",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiOgawa/ogTest", False],
            ["plugPikiOgawa/ogSub", False],
            ["plugPikiOgawa/ogTitle", False],
            ["plugPikiOgawa/ogPause", False],
            ["plugPikiOgawa/ogTutorial", False],
            ["plugPikiOgawa/ogTutorialData", True],
            ["plugPikiOgawa/ogMap", False],
            ["plugPikiOgawa/ogResult", False],
            ["plugPikiOgawa/ogRader", False],
            ["plugPikiOgawa/ogFileSelect", False],
            ["plugPikiOgawa/ogMessage", False],
            ["plugPikiOgawa/ogMemChk", False],
            ["plugPikiOgawa/ogDiary", False],
            ["plugPikiOgawa/ogMenu", False],
            ["plugPikiOgawa/ogFileChkSel", False],
            ["plugPikiOgawa/ogMakeDefault", False],
            ["plugPikiOgawa/ogTotalScore", False],
            ["plugPikiOgawa/ogSave", False],
            ["plugPikiOgawa/ogNitaku", False],
            ["plugPikiOgawa/ogFileCopy", False],
            ["plugPikiOgawa/ogFileDelete", False],
            ["plugPikiOgawa/ogGraph", False],
            ["plugPikiOgawa/ogStart", False],
            ["plugPikiOgawa/ogCallBack", False],
        ],
    },
    {
        "lib": "plugPikiYamashita",
        "cflags": "$cflags_pikmin",
        "mw_version": "1.2.5n",
        "host": True,
        "objects": [
            ["plugPikiYamashita/gameCourseClear", False],
            ["plugPikiYamashita/gameStageClear", False],
            ["plugPikiYamashita/gameCredits", False],
            ["plugPikiYamashita/zenMath", False],
            ["plugPikiYamashita/effectMgr", False],
            ["plugPikiYamashita/particleGenerator", False],
            ["plugPikiYamashita/particleLoader", False],
            ["plugPikiYamashita/solidField", True],
            ["plugPikiYamashita/particleManager", False],
            ["plugPikiYamashita/particleMdlManager", False],
            ["plugPikiYamashita/bBoardColourAnim", False],
            ["plugPikiYamashita/simpleParticle", False],
            ["plugPikiYamashita/tekiyteki", False],
            ["plugPikiYamashita/tekiyamashita", False],
            ["plugPikiYamashita/TAIanimation", True],
            ["plugPikiYamashita/TAItank", False],
            ["plugPikiYamashita/TAImar", False],
            ["plugPikiYamashita/TAIAreaction", False],
            ["plugPikiYamashita/TAIAmove", False],
            ["plugPikiYamashita/TAIAmotion", False],
            ["plugPikiYamashita/TAIAjudge", False],
            ["plugPikiYamashita/TAIAattack", False],
            ["plugPikiYamashita/P2DGrafContext", False],
            ["plugPikiYamashita/P2DOrthoGraph", False],
            ["plugPikiYamashita/P2DPerspGraph", False],
            ["plugPikiYamashita/P2DPane", False],
            ["plugPikiYamashita/P2DPicture", False],
            ["plugPikiYamashita/P2DScreen", False],
            ["plugPikiYamashita/P2DStream", False],
            ["plugPikiYamashita/PSUList", False],
            ["plugPikiYamashita/PUTRect", False],
            ["plugPikiYamashita/P2DWindow", False],
            ["plugPikiYamashita/P2DTextBox", False],
            ["plugPikiYamashita/P2DPrint", False],
            ["plugPikiYamashita/P2DFont", False],
            ["plugPikiYamashita/drawGameInfo", False],
            ["plugPikiYamashita/zenGraphics", False],
            ["plugPikiYamashita/drawContainer", False],
            ["plugPikiYamashita/drawCommon", False],
            ["plugPikiYamashita/zenController", False],
            ["plugPikiYamashita/drawHurryUp", False],
            ["plugPikiYamashita/texAnim", False],
            ["plugPikiYamashita/drawAccount", False],
            ["plugPikiYamashita/drawMenu", False],
            ["plugPikiYamashita/TAIeffectAttack", False],
            ["plugPikiYamashita/TAIbeatle", False],
            ["plugPikiYamashita/menuPanelMgr", False],
            ["plugPikiYamashita/TAIkabekuiA", False],
            ["plugPikiYamashita/TAIkabekuiB", False],
            ["plugPikiYamashita/TAIkabekuiC", False],
            ["plugPikiYamashita/TAItamago", False],
            ["plugPikiYamashita/TAIdororo", False],
            ["plugPikiYamashita/TAIhibaA", False],
            ["plugPikiYamashita/TAIAeffect", False],
            ["plugPikiYamashita/TAImiurin", False],
            ["plugPikiYamashita/ptclGenPack", True],
            ["plugPikiYamashita/drawProgre", False],
            ["plugPikiYamashita/spectrumCursorMgr", False],
            ["plugPikiYamashita/drawWorldMap", False],
            ["plugPikiYamashita/drawCountDown", False],
            ["plugPikiYamashita/drawGameOver", False],
            ["plugPikiYamashita/yai", False],
            ["plugPikiYamashita/effectMgr2D", False],
            ["plugPikiYamashita/drawWMPause", False],
            ["plugPikiYamashita/TAIusuba", False],
            ["plugPikiYamashita/TAIotama", False],
            ["plugPikiYamashita/drawCMcourseSelect", False],
            ["plugPikiYamashita/drawCMtitle", False],
            ["plugPikiYamashita/drawCMscore", False],
            ["plugPikiYamashita/drawCMbest", False],
            ["plugPikiYamashita/drawCMresult", False],
            ["plugPikiYamashita/drawMenuBase", False],
            ["plugPikiYamashita/drawHiScore", False],
            ["plugPikiYamashita/damageEffect", False],
            ["plugPikiYamashita/alphaWipe", False],
            ["plugPikiYamashita/drawUfoParts", False],
            ["plugPikiYamashita/zenSys", False],
            ["plugPikiYamashita/drawSaveMes", False],
            ["plugPikiYamashita/drawSaveFailure", False],
            ["plugPikiYamashita/drawFinalResult", False],
            ["plugPikiYamashita/drawOptionSave", False],
        ],
    },
    {
        "lib": "base",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["base/PPCArch", True],
        ],
    },
    {
        "lib": "os",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["os/OS", False],
            ["os/OSAlarm", False],
            ["os/OSAlloc", True],
            ["os/OSArena", True],
            ["os/OSAudioSystem", False],
            ["os/OSCache", False],
            ["os/OSContext", False],
            ["os/OSError", True],
            ["os/OSExi", False],
            ["os/OSFont", False],
            ["os/OSInterrupt", False],
            ["os/OSLink", True],
            ["os/OSMessage", False],
            ["os/OSMutex", False],
            ["os/OSReboot", False],
            ["os/OSReset", False],
            ["os/OSResetSW", False],
            ["os/OSRtc", False],
            ["os/OSSerial", False],
            ["os/OSSync", False],
            ["os/OSThread", False],
            ["os/OSTime", False],
            ["os/OSUartExi", False],
            ["os/__start", True],
            ["os/__ppc_eabi_init", False],
        ],
    },
    {
        "lib": "db",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["db/db", False],
        ],
    },
    {
        "lib": "mtx",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["mtx/mtx", False],
            ["mtx/mtx44", False],
            ["mtx/vec", False],
        ],
    },
    {
        "lib": "dvd",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["dvd/dvdlow", False],
            ["dvd/dvdfs", False],
            ["dvd/dvd", False],
            ["dvd/dvdqueue", False],
            ["dvd/dvderror", False],
            ["dvd/fstload", False],
        ],
    },
    {
        "lib": "vi",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["vi/vi", False],
        ],
    },
    {
        "lib": "pad",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["pad/Padclamp", False],
            ["pad/Pad", False],
        ],
    },
    {
        "lib": "ai",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["ai/ai", False],
        ],
    },
    {
        "lib": "ar",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["ar/ar", False],
            ["ar/arq", False],
        ],
    },
    {
        "lib": "dsp",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["dsp/dsp", True],
        ],
    },
    {
        "lib": "card",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["card/CARDBios", False],
            ["card/CARDRdwr", False],
            ["card/CARDBlock", False],
            ["card/CARDDir", False],
            ["card/CARDCheck", False],
            ["card/CARDMount", False],
            ["card/CARDFormat", False],
            ["card/CARDOpen", False],
            ["card/CARDCreate", False],
            ["card/CARDRead", False],
            ["card/CARDWrite", False],
            ["card/CARDDelete", False],
            ["card/CARDStat", False],
            ["card/CARDRename", False],
        ],
    },
    {
        "lib": "hio",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["hio/hio", False],
        ],
    },
    {
        "lib": "gx",
        "cflags": "$cflags_base",
        "mw_version": "1.2.5",
        "host": True,
        "objects": [
            ["gx/GXInit", False],
            ["gx/GXFifo", False],
            ["gx/GXAttr", False],
            ["gx/GXMisc", False],
            ["gx/GXGeometry", False],
            ["gx/GXFrameBuf", False],
            ["gx/GXLight", False],
            ["gx/GXTexture", False],
            ["gx/GXBump", False],
            ["gx/GXTev", False],
            ["gx/GXPixel", False],
            ["gx/GXStubs", True],
            ["gx/GXDisplayList", False],
            ["gx/GXTransform", False],
        ],
    },
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["Runtime/PPCEABI/H/__mem", False],
            ["Runtime/PPCEABI/H/__va_arg", False],
            ["Runtime/PPCEABI/H/global_destructor_chain", False],
            ["Runtime/PPCEABI/H/CPlusLibPPC", False],
            ["Runtime/PPCEABI/H/NMWException", False],
            ["Runtime/PPCEABI/H/ptmf", True],
            ["Runtime/PPCEABI/H/ExceptionPPC", False],
            ["Runtime/PPCEABI/H/runtime", False],
            ["Runtime/PPCEABI/H/__init_cpp_exceptions", False],
        ],
    },
    {
        "lib": "MSL_C.PPCEABI.bare.H",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base -fp_contract on",
        "host": True,
        "objects": [
            ["MSL_C/PPCEABI/bare/H/abort_exit", False],
            ["MSL_C/PPCEABI/bare/H/errno", True],
            ["MSL_C/PPCEABI/bare/H/ansi_fp", False],
            ["MSL_C/PPCEABI/bare/H/arith", True],
            ["MSL_C/PPCEABI/bare/H/buffer_io", False],
            ["MSL_C/PPCEABI/bare/H/critical_regions.ppc_eabi", True],
            ["MSL_C/PPCEABI/bare/H/ctype", True],
            ["MSL_C/PPCEABI/bare/H/ansi_files", False],
            ["MSL_C/PPCEABI/bare/H/locale", False],
            ["MSL_C/PPCEABI/bare/H/direct_io", False],
            ["MSL_C/PPCEABI/bare/H/mbstring", False],
            ["MSL_C/PPCEABI/bare/H/mem", False],
            ["MSL_C/PPCEABI/bare/H/mem_funcs", False],
            ["MSL_C/PPCEABI/bare/H/misc_io", True],
            ["MSL_C/PPCEABI/bare/H/printf", False],
            ["MSL_C/PPCEABI/bare/H/rand", True],
            ["MSL_C/PPCEABI/bare/H/scanf", False],
            ["MSL_C/PPCEABI/bare/H/string", False],
            ["MSL_C/PPCEABI/bare/H/strtold", False],
            ["MSL_C/PPCEABI/bare/H/strtoul", False],
            ["MSL_C/PPCEABI/bare/H/uart_console_io", False],
            ["MSL_C/PPCEABI/bare/H/wchar_io", True],
            ["MSL_C/PPCEABI/bare/H/float", True],
            ["MSL_C/PPCEABI/bare/H/e_asin", False],
            ["MSL_C/PPCEABI/bare/H/e_atan2", False],
            ["MSL_C/PPCEABI/bare/H/e_pow", True],
            ["MSL_C/PPCEABI/bare/H/fminmaxdim", False],
            ["MSL_C/PPCEABI/bare/H/s_atan", False],
            ["MSL_C/PPCEABI/bare/H/s_copysign", True],
            ["MSL_C/PPCEABI/bare/H/s_frexp", True],
            ["MSL_C/PPCEABI/bare/H/s_ldexp", False],
            ["MSL_C/PPCEABI/bare/H/w_atan2", False],
            ["MSL_C/PPCEABI/bare/H/w_pow", False],
            ["MSL_C/PPCEABI/bare/H/hyperbolicsf", True],
            ["MSL_C/PPCEABI/bare/H/inverse_trig", False],
            ["MSL_C/PPCEABI/bare/H/trigf", False],
            ["MSL_C/PPCEABI/bare/H/math_inlines", False],
            ["MSL_C/PPCEABI/bare/H/common_float_tables", False],
        ],
    },
    {
        "lib": "TRK_MINNOW_DOLPHIN",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["TRK_MINNOW_DOLPHIN/mainloop", False],
            ["TRK_MINNOW_DOLPHIN/nubevent", False],
            ["TRK_MINNOW_DOLPHIN/nubinit", False],
            ["TRK_MINNOW_DOLPHIN/msg", False],
            ["TRK_MINNOW_DOLPHIN/msgbuf", False],
            ["TRK_MINNOW_DOLPHIN/serpoll", False],
            ["TRK_MINNOW_DOLPHIN/usr_put", True],
            ["TRK_MINNOW_DOLPHIN/dispatch", False],
            ["TRK_MINNOW_DOLPHIN/msghndlr", False],
            ["TRK_MINNOW_DOLPHIN/support", False],
            ["TRK_MINNOW_DOLPHIN/mutex_TRK", True],
            ["TRK_MINNOW_DOLPHIN/notify", False],
            ["TRK_MINNOW_DOLPHIN/flush_cache", False],
            ["TRK_MINNOW_DOLPHIN/mem_TRK", False],
            ["TRK_MINNOW_DOLPHIN/__exception", False],
            ["TRK_MINNOW_DOLPHIN/targimpl", False],
            ["TRK_MINNOW_DOLPHIN/dolphin_trk", False],
            ["TRK_MINNOW_DOLPHIN/mpc_7xx_603e", False],
            ["TRK_MINNOW_DOLPHIN/main_TRK", False],
            ["TRK_MINNOW_DOLPHIN/dolphin_trk_glue", False],
            ["TRK_MINNOW_DOLPHIN/targcont", False],
        ],
    },
    {
        "lib": "amcExi2",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["amcExi2/AmcExi", False],
            ["amcExi2/AmcExi2Comm", False],
        ],
    },
    {
        "lib": "amcnotstub",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["amcnotstub/amcnotstub", True],
        ],
    },
    {
        "lib": "OdemuExi2",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["OdemuExi2/DebuggerDriver", False],
        ],
    },
    {
        "lib": "odenotstub",
        "mw_version": "1.2.5",
        "cflags": "$cflags_base",
        "host": True,
        "objects": [
            ["odenotstub/odenotstub", True],
        ],
    },
]


def main():
    import os
    import io
    import sys
    import argparse
    import json

    from pathlib import Path
    from shutil import which
    from tools import ninja_syntax

    if sys.version_info < (3, 8):
        sys.exit("Python 3.8 or later required.")

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--version",
        "-v",
        dest="version",
        default="usa.1",
        help="version to build (usa.1, usa.0)",
    )
    parser.add_argument(
        "--map",
        "-m",
        dest="map",
        action="store_true",
        help="generate map file",
    )
    parser.add_argument(
        "--no-check",
        dest="check",
        action="store_false",
        help="don't check hash of resulting dol",
    )
    parser.add_argument(
        "--no-static-libs",
        dest="static_libs",
        action="store_false",
        help="don't build and use static libs",
    )
    parser.add_argument(
        "--powerpc",
        dest="powerpc",
        type=Path,
        default=Path("tools/powerpc"),
        help="path to powerpc-eabi tools",
    )
    if os.name != "nt" and not "_NT-" in os.uname().sysname:
        parser.add_argument(
            "--wine",
            dest="wine",
            type=Path,
            help="path to wine (or wibo)",
        )
    parser.add_argument(
        "--build-dtk",
        dest="build_dtk",
        type=Path,
        help="path to decomp-toolkit source",
    )
    parser.add_argument(
        "--debug",
        "-d",
        dest="debug",
        action="store_true",
        help="build with debug info (non-matching)",
    )
    parser.add_argument(
        "--compilers",
        dest="compilers",
        type=Path,
        default=Path("tools/mwcc_compiler"),
        help="path to compilers",
    )
    parser.add_argument(
        "--build-dir",
        dest="build_dir",
        type=Path,
        default=Path("build"),
        help="base build directory",
    )
    parser.add_argument(
        "--context",
        "-c",
        dest="context",
        action="store_true",
        help="generate context files for decomp.me",
    )
    args = parser.parse_args()

    # On Windows, we need this to use && in commands
    chain = "cmd /c " if os.name == "nt" else ""

    out = io.StringIO()
    n = ninja_syntax.Writer(out)

    n.variable("ninja_required_version", "1.3")
    n.newline()

    n.comment("The arguments passed to configure.py, for rerunning it.")
    configure_args = sys.argv[1:]
    n.variable("configure_args", configure_args)
    n.variable("python", f'"{sys.executable}"')
    n.newline()

    ###
    # Variables
    ###
    n.comment("Variables")
    version = args.version.lower()
    if args.version.lower() == "usa.1":
        version_num = "2"
    elif args.version.lower() == "usa.0":
        version_num = "1"
    else:
        sys.exit(f'Invalid version "{args.version}"')
    build_path = args.build_dir / f"pikmin.{version}"

    cflags_base = f"-Cpp_exceptions off -O4,p -fp hard -proc gekko -nodefaults -RTTI on -enum int -sdata 8 -sdata2 8 -str noreadonly -DVERNUM={version_num} -i include -i include/stl -inline auto"
    if args.debug:
        cflags_base += " -sym on -D_DEBUG"
    else:
        cflags_base += " -DNDEBUG -w off"
    n.variable("cflags_base", cflags_base)
    n.variable("cflags_pikmin", "$cflags_base -common on")

    asflags = f"-mgekko -I include --defsym version={version_num} -W --strip-local-absolute -gdwarf-2"
    n.variable("asflags", asflags)

    ldflags = "-fp fmadd -nodefaults -lcf ldscript.lcf"
    if args.map:
        map_path = build_path / "build.map"
        ldflags += f" -map {map_path} -mapunused"
    if args.debug:
        ldflags += " -g"
    else:
        ldflags += " -w off"
    n.variable("ldflags", ldflags)

    mw_link_version = "1.2.5"
    n.variable("mw_version", mw_link_version)
    if os.name == "nt":
        exe = ".exe"
        wine = ""
    else:
        if "_NT-" in os.uname().sysname:
            # MSYS2
            wine = ""
        elif args.wine:
            wine = f"{args.wine} "
        elif which("wibo") is not None:
            wine = "wibo "
        else:
            wine = "wine "
        exe = ""
    n.newline()

    ###
    # Tooling
    ###
    tools_path = Path("tools")

    def path(input):
        if input is None:
            return None
        elif isinstance(input, list):
            return list(map(str, input))
        else:
            return [str(input)]

    n.comment("decomp-toolkit")
    if args.build_dtk:
        dtk = tools_path / "release" / f"dtk{exe}"
        n.rule(
            name="cargo",
            command="cargo build --release --manifest-path $in --bin $bin --target-dir $target",
            description="CARGO $bin",
            depfile=path(Path("$target") / "release" / "$bin.d"),
            deps="gcc",
        )
        n.build(
            outputs=path(dtk),
            rule="cargo",
            inputs=path(args.build_dtk / "Cargo.toml"),
            variables={
                "bin": "dtk",
                "target": tools_path,
            },
        )
    else:
        dtk = tools_path / f"dtk{exe}"
        download_dtk = tools_path / "download_dtk.py"
        n.rule(
            name="download_dtk",
            command=f"$python {download_dtk} $in $out",
            description="DOWNLOAD $out",
        )
        n.build(
            outputs=path(dtk),
            rule="download_dtk",
            inputs=path([tools_path / "dtk_version"]),
            implicit=path([download_dtk]),
        )
    n.newline()

    # FIXME: Manual downloads because ninja doesn't play nice with directories,
    # replace with automated system like dtk uses if workaround is found
    if args.powerpc == Path("tools/powerpc") and not Path("tools/powerpc").exists():
        import tools.download_ppc

        tools.download_ppc.main()

    if args.compilers == Path("tools/mwcc_compiler") and not Path("tools/mwcc_compiler").exists():
        import tools.download_mwcc

        tools.download_mwcc.main()

    ###
    # Rules
    ###
    compiler_path = args.compilers / "$mw_version"
    mwcc = compiler_path / "mwcceppc.exe"
    mwld = compiler_path / "mwldeppc.exe"
    gnu_as = args.powerpc / f"powerpc-eabi-as{exe}"

    mwcc_cmd = f"{chain}{wine}{mwcc} $cflags -MMD -c $in -o $basedir"
    if args.context:
        mwcc_cmd += " && $python tools/decompctx.py $cfile -r -q"
    mwld_cmd = f"{wine}{mwld} $ldflags -o $out @$out.rsp"
    as_cmd = (
        f"{chain}{gnu_as} $asflags -o $out $in -MD $out.d"
        + f" && {dtk} elf fixup $out $out"
    )
    ar_cmd = f"{dtk} ar create $out @$out.rsp"

    if os.name != "nt":
        transform_dep = tools_path / "transform-dep.py"
        transform_dep_cmd = f" && $python {transform_dep} $basefile.d $basefile.d"
        mwcc_cmd += transform_dep_cmd

    n.comment("Link ELF file")
    n.rule(
        name="link",
        command=mwld_cmd,
        description="LINK $out",
        rspfile="$out.rsp",
        rspfile_content="$in_newline",
    )
    n.newline()

    n.comment("MWCC build")
    n.rule(
        name="mwcc",
        command=mwcc_cmd,
        description="MWCC $out",
        depfile="$basefile.d",
        deps="gcc",
    )
    n.newline()

    n.comment("Assemble asm")
    n.rule(
        name="as",
        command=as_cmd,
        description="AS $out",
        depfile="$out.d",
        deps="gcc",
    )
    n.newline()

    n.comment("Create static library")
    n.rule(
        name="ar",
        command=ar_cmd,
        description="AR $out",
        rspfile="$out.rsp",
        rspfile_content="$in_newline",
    )
    n.newline()

    n.comment("Host build")
    n.variable("host_cflags", "-I include -Wno-trigraphs")
    n.variable(
        "host_cppflags",
        "-std=c++98 -I include -fno-exceptions -fno-rtti -D_CRT_SECURE_NO_WARNINGS -Wno-trigraphs -Wno-c++11-extensions",
    )
    n.rule(
        name="host_cc",
        command="clang $host_cflags -c -o $out $in",
        description="CC $out",
    )
    n.rule(
        name="host_cpp",
        command="clang++ $host_cppflags -c -o $out $in",
        description="CXX $out",
    )
    n.newline()

    ###
    # Rules for source files
    ###
    n.comment("Source files")
    src_path = Path("src")
    asm_path = Path("asm")
    build_src_path = build_path / "src"
    build_host_path = build_path / "host"
    build_asm_path = build_path / "asm"
    build_lib_path = build_path / "lib"

    objdiff_config = {
        "min_version": "0.4.3",
        "custom_make": "ninja",
        "build_target": True,
        "watch_patterns": [
            "*.c",
            "*.cp",
            "*.cpp",
            "*.h",
            "*.hpp",
            "*.py",
        ],
        "units": [],
    }

    source_inputs = []
    host_source_inputs = []
    link_inputs = []
    used_compiler_versions = set()
    for lib in LIBS:
        inputs = []
        if "lib" in lib:
            lib_name = lib["lib"]
            n.comment(f"{lib_name}.a")
        else:
            n.comment("Loose files")

        for object in lib["objects"]:
            completed = False
            options = {
                "add_to_all": True,
                "mw_version": None,
                "cflags": None,
            }
            if type(object) is list:
                if len(object) > 1:
                    completed = object[1]
                if len(object) > 2:
                    options.update(object[2])
                object = object[0]

            cflags = options["cflags"] or lib["cflags"]
            mw_version = options["mw_version"] or lib["mw_version"]
            used_compiler_versions.add(mw_version)

            # objdiff config
            unit_config = {
                "name": object,
                "complete": completed,
            }

            c_file = None
            if os.path.exists(src_path / f"{object}.cpp"):
                c_file = src_path / f"{object}.cpp"
            elif os.path.exists(src_path / f"{object}.cp"):
                c_file = src_path / f"{object}.cp"
            elif os.path.exists(src_path / f"{object}.c"):
                c_file = src_path / f"{object}.c"
            elif os.path.exists(src_path / f"{object}.C"):
                c_file = src_path / f"{object}.C"
            elif os.path.exists(src_path / f"{object}.s"): # specifically for __exception.s
                n.build(
                    outputs=path(build_src_path / f"{object}.o"),
                    rule="as",
                    inputs=path(src_path / f"{object}.s"),
                    implicit=path(dtk),
                )
            if c_file is not None:
                n.build(
                    outputs=path(build_src_path / f"{object}.o"),
                    rule="mwcc",
                    inputs=path(c_file),
                    variables={
                        "mw_version": mw_version,
                        "cflags": options["cflags"] or lib["cflags"],
                        "basedir": os.path.dirname(build_src_path / f"{object}"),
                        "basefile": path(build_src_path / f"{object}"),
                        "cfile": path(c_file),
                    },
                    implicit_outputs = None if not args.context else (str(c_file) + ".ctx")
                )
                if lib["host"]:
                    n.build(
                        outputs=path(build_host_path / f"{object}.o"),
                        rule="host_cc" if c_file.suffix == ".c" else "host_cpp",
                        inputs=path(c_file),
                        variables={
                            "basedir": os.path.dirname(build_host_path / object),
                            "basefile": path(build_host_path / object),
                        },
                    )
                    if options["add_to_all"]:
                        host_source_inputs.append(build_host_path / f"{object}.o")
                if options["add_to_all"]:
                    source_inputs.append(build_src_path / f"{object}.o")
                unit_config["base_path"] = str(build_src_path / f"{object}.o")
            if os.path.exists(asm_path / f"{object}.s"):
                n.build(
                    outputs=path(build_asm_path / f"{object}.o"),
                    rule="as",
                    inputs=path(asm_path / f"{object}.s"),
                    implicit=path(dtk),
                )
            unit_config["target_path"] = str(build_asm_path / f"{object}.o")
            objdiff_config["units"].append(unit_config)
            if completed:
                inputs.append(build_src_path / f"{object}.o")
            else:
                inputs.append(build_asm_path / f"{object}.o")
        if args.static_libs and "lib" in lib:
            lib_name = lib["lib"]
            n.build(
                outputs=path(build_lib_path / f"{lib_name}.a"),
                rule="ar",
                inputs=path(inputs),
                implicit=path(dtk),
            )
            link_inputs.append(build_lib_path / f"{lib_name}.a")
        else:
            link_inputs.extend(inputs)
        n.newline()

    # Check if all compiler versions exist
    for mw_version in used_compiler_versions:
        mw_path = args.compilers / mw_version / "mwcceppc.exe"
        if not os.path.exists(mw_path):
            print(f"Compiler {mw_path} does not exist")
            exit(1)

    # Check if linker exists
    mw_path = args.compilers / mw_link_version / "mwldeppc.exe"
    if not os.path.exists(mw_path):
        print(f"Linker {mw_path} does not exist")
        exit(1)

    ###
    # Link
    ###
    n.comment("Link")
    if args.map:
        n.build(
            outputs=path(build_path / "main.elf"),
            rule="link",
            inputs=path(link_inputs),
            implicit_outputs=path(map_path),
        )
    else:
        n.build(
            outputs=path(build_path / "main.elf"),
            rule="link",
            inputs=path(link_inputs),
        )
    n.newline()

    ###
    # Helper rule for building all source files
    ###
    n.comment("Build all source files")
    n.build(
        outputs="all_source",
        rule="phony",
        inputs=path(source_inputs),
    )
    n.newline()

    ###
    # Helper rule for building all source files, with a host compiler
    ###
    n.comment("Build all source files with a host compiler")
    n.build(
        outputs="all_source_host",
        rule="phony",
        inputs=path(host_source_inputs),
    )
    n.newline()

    ###
    # Generate DOL
    ###
    n.comment("Generate DOL")
    n.rule(
        name="elf2dol",
        command=f"{dtk} elf2dol $in $out",
        description="DOL $out",
    )
    n.build(
        outputs=path(build_path / "main.dol"),
        rule="elf2dol",
        inputs=path(build_path / "main.elf"),
        implicit=path(dtk),
    )
    n.newline()

    ###
    # Check DOL hash
    ###
    if args.check:
        n.comment("Check DOL hash")
        n.rule(
            name="check",
            command=f"{dtk} shasum -c $in -o $out",
            description="CHECK $in",
        )
        n.build(
            outputs=path(build_path / "main.dol.ok"),
            rule="check",
            inputs=f"sha1/pikmin.{version}.sha1",
            implicit=path([build_path / "main.dol", dtk]),
        )
        n.newline()

    ###
    # Progress script
    ###
    if args.map:
        n.comment("Check progress")
        calc_progress = tools_path / "calcprogress.py"
        n.rule(
            name="progress",
            command=f"$python {calc_progress} $in -o $out",
            description="PROGRESS $in",
        )
        n.build(
            outputs=path(build_path / "main.dol.progress"),
            rule="progress",
            inputs=path([build_path / "main.dol", map_path]),
            implicit=path([calc_progress, build_path / "main.dol.ok"]),
        )
        n.newline()

    ###
    # Regenerate on change
    ###
    n.comment("Reconfigure on change")
    n.rule(
        name="configure",
        command="$python configure.py $configure_args",
        generator=True,
    )
    n.build(
        outputs="build.ninja",
        rule="configure",
        implicit=path(["configure.py", tools_path / "ninja_syntax.py"]),
    )
    n.newline()

    ###
    # Default rule
    ###
    n.comment("Default rule")
    if args.check:
        dol_out = build_path / "main.dol.ok"
    else:
        dol_out = build_path / "main.dol"
    if args.map:
        n.default(path([dol_out, build_path / "main.dol.progress"]))
    else:
        n.default(path([dol_out]))

    ###
    # Write build.ninja
    ###
    with open("build.ninja", "w") as f:
        f.write(out.getvalue())
    n.close()

    ###
    # Write objdiff config
    ###
    with open("objdiff.json", "w") as w:
        json.dump(objdiff_config, w, indent=4)


if __name__ == "__main__":
    main()
