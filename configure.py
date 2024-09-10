#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List
from tools.project import *

# Game versions
DEFAULT_VERSION = 4
VERSIONS = [
    "DPIJ01",  # PikiDemo / Jitsuen-you Sample
    "GPIJ01_01",  # JPN Rev 1
    "GPIJ01_02",  # JPN Rev 2
    "GPIE01_00",  # USA Rev 0
    "GPIE01_01",  # USA Rev 1
    "GPIP01_00",  # PAL Rev 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20240706"
config.dtk_tag = "v0.9.6"
config.objdiff_tag = "v2.0.0"
config.sjiswrap_tag = "v1.1.1"
config.wibo_tag = "0.6.11"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym version={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")
if args.map:
    config.ldflags.append("-mapunused")
# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Progress configuration
config.progress_all = False
config.progress_use_fancy = True
config.progress_code_fancy_frac = 30
config.progress_code_fancy_item = "ship parts"
config.progress_data_fancy_frac = 100
config.progress_data_fancy_item = "Pikmin"

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    # "-W all",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",
    "-i include",
    "-i include/stl",
    f"-i build/{config.version}/include",
    f"-DVERSION={version_num}",
]

# Debug flags
if args.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# JAudio flags
cflags_jaudio = [
    *cflags_base,
    "-common on",
    "-func_align 32",
    "-lang c++",
]

# Game code flags
cflags_pikmin = [
    *cflags_base,
    "-fp_contract off",
    "-common on",
    "-RTTI on",
]

config.linker_version = "GC/1.2.5"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    mw_version = "GC/1.2.5"
    if version_num == 0:
        mw_version = "GC/1.2.5n"
    return {
        "lib": lib_name,
        "mw_version": mw_version,
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching

config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "sysBootup",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(Matching, "sysBootup.cpp"),
        ],
    },
    {
        "lib": "jaudio",
        "cflags": cflags_jaudio,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(Matching, "jaudio/dummyprobe.c"),
            Object(NonMatching, "jaudio/memory.c"),
            Object(NonMatching, "jaudio/aictrl.c"),
            Object(NonMatching, "jaudio/sample.c"),
            Object(NonMatching, "jaudio/dummyrom.c"),
            Object(NonMatching, "jaudio/audiothread.c"),
            Object(NonMatching, "jaudio/audiothread_fakebss.o"),
            Object(NonMatching, "jaudio/streamctrl.c"),
            Object(NonMatching, "jaudio/dspbuf.c"),
            Object(NonMatching, "jaudio/cpubuf.c"),
            Object(NonMatching, "jaudio/playercall.c"),
            Object(NonMatching, "jaudio/dvdthread.c"),
            Object(NonMatching, "jaudio/audiomesg.c"),
            Object(NonMatching, "jaudio/rate.c"),
            Object(NonMatching, "jaudio/stackchecker.c"),
            Object(NonMatching, "jaudio/dspboot.c"),
            Object(NonMatching, "jaudio/dspproc.c"),
            Object(NonMatching, "jaudio/ipldec.c"),
            Object(NonMatching, "jaudio/dsp_cardunlock.c"),
            Object(NonMatching, "jaudio/driverinterface.c"),
            Object(NonMatching, "jaudio/dspdriver.c"),
            Object(NonMatching, "jaudio/dspinterface.c"),
            Object(NonMatching, "jaudio/fxinterface.c"),
            Object(NonMatching, "jaudio/bankread.c"),
            Object(NonMatching, "jaudio/waveread.c"),
            Object(NonMatching, "jaudio/connect.c"),
            Object(NonMatching, "jaudio/tables.c"),
            Object(NonMatching, "jaudio/bankdrv.c"),
            Object(NonMatching, "jaudio/random.c"),
            Object(NonMatching, "jaudio/aramcall.c"),
            Object(NonMatching, "jaudio/ja_calc.c"),
            Object(NonMatching, "jaudio/fat.c"),
            Object(NonMatching, "jaudio/cmdstack.c"),
            Object(NonMatching, "jaudio/virload.c"),
            Object(NonMatching, "jaudio/heapctrl.c"),
            Object(NonMatching, "jaudio/jammain_2.c"),
            Object(NonMatching, "jaudio/midplay.c"),
            Object(NonMatching, "jaudio/noteon.c"),
            Object(NonMatching, "jaudio/seqsetup.c"),
            Object(NonMatching, "jaudio/centcalc.c"),
            Object(NonMatching, "jaudio/jamosc.c"),
            Object(NonMatching, "jaudio/oneshot.c"),
            Object(NonMatching, "jaudio/interface.c"),
            Object(NonMatching, "jaudio/verysimple.c"),
            Object(NonMatching, "jaudio/app_inter.c"),
            Object(NonMatching, "jaudio/pikiinter.c"),
            Object(NonMatching, "jaudio/piki_player.c"),
            Object(NonMatching, "jaudio/piki_bgm.c"),
            Object(NonMatching, "jaudio/piki_scene.c"),
            Object(NonMatching, "jaudio/pikidemo.c"),
            Object(NonMatching, "jaudio/file_seq.c"),
            Object(NonMatching, "jaudio/cmdqueue.c"),
            Object(Matching, "jaudio/filter3d.c"),
            Object(NonMatching, "jaudio/syncstream.c"),
            Object(NonMatching, "jaudio/bankloader.c"),
            Object(NonMatching, "jaudio/interleave.c"),
            Object(NonMatching, "jaudio/pikiseq.c"),
            Object(NonMatching, "jaudio/hplaybss.c"),
            Object(NonMatching, "jaudio/hplaybss2.c"),
            Object(NonMatching, "jaudio/hvqm_play.c"),
        ],
    },
    {
        "lib": "hvqm4dec",
        "cflags": cflags_base,
        "mw_version": "GC/1.2.5",
        "objects": [
            Object(NonMatching, "hvqm4dec/hvqm4dec.c"),
        ],
    },
    {
        "lib": "sysCommon",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "sysCommon/ayuStack.cpp"),
            Object(Matching, "sysCommon/baseApp.cpp"),
            Object(Matching, "sysCommon/stream.cpp"),
            Object(NonMatching, "sysCommon/streamBufferedInput.cpp"),
            Object(Matching, "sysCommon/string.cpp"),
            Object(NonMatching, "sysCommon/graphics.cpp"),
            Object(NonMatching, "sysCommon/grLight.cpp"),
            Object(NonMatching, "sysCommon/shapeBase.cpp"),
            Object(NonMatching, "sysCommon/shpLightFlares.cpp"),
            Object(Matching, "sysCommon/shpObjColl.cpp"),
            Object(NonMatching, "sysCommon/shpRoutes.cpp"),
            Object(NonMatching, "sysCommon/sysMath.cpp"),
            Object(NonMatching, "sysCommon/matMath.cpp"),
            Object(NonMatching, "sysCommon/stdSystem.cpp"),
            Object(NonMatching, "sysCommon/node.cpp"),
            Object(Matching, "sysCommon/timers.cpp"),
            Object(Matching, "sysCommon/controller.cpp"),
            Object(Matching, "sysCommon/cmdStream.cpp"),
            Object(NonMatching, "sysCommon/camera.cpp"),
            Object(Matching, "sysCommon/atx.cpp"),
            Object(Matching, "sysCommon/id32.cpp"),
        ],
    },
    {
        "lib": "sysDolphin",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "sysDolphin/texture.cpp"),
            Object(NonMatching, "sysDolphin/system.cpp"),
            Object(NonMatching, "sysDolphin/sysNew.cpp"),
            Object(NonMatching, "sysDolphin/controllerMgr.cpp"),
            Object(NonMatching, "sysDolphin/dgxGraphics.cpp"),
            Object(Matching, "sysDolphin/gameApp.cpp"),
        ],
    },
    {
        "lib": "plugPikiColin",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "plugPikiColin/cardutil.cpp"),
            Object(NonMatching, "plugPikiColin/dynsimulator.cpp"),
            Object(NonMatching, "plugPikiColin/animMgr.cpp"),
            Object(NonMatching, "plugPikiColin/gameflow.cpp"),
            Object(NonMatching, "plugPikiColin/game.cpp"),
            Object(NonMatching, "plugPikiColin/gamePrefs.cpp"),
            Object(NonMatching, "plugPikiColin/gameSetup.cpp"),
            Object(NonMatching, "plugPikiColin/cardSelect.cpp"),
            Object(NonMatching, "plugPikiColin/mapSelect.cpp"),
            Object(NonMatching, "plugPikiColin/newPikiGame.cpp"),
            Object(NonMatching, "plugPikiColin/introGame.cpp"),
            Object(Matching, "plugPikiColin/gameExit.cpp"),
            Object(NonMatching, "plugPikiColin/gauges.cpp"),
            Object(NonMatching, "plugPikiColin/genMapObject.cpp"),
            Object(NonMatching, "plugPikiColin/gui.cpp"),
            Object(NonMatching, "plugPikiColin/parameters.cpp"),
            Object(NonMatching, "plugPikiColin/plugPiki.cpp"),
            Object(NonMatching, "plugPikiColin/titles.cpp"),
            Object(NonMatching, "plugPikiColin/ninLogo.cpp"),
            Object(NonMatching, "plugPikiColin/mapMgr.cpp"),
            Object(NonMatching, "plugPikiColin/dayMgr.cpp"),
            Object(NonMatching, "plugPikiColin/cinePlayer.cpp"),
            Object(NonMatching, "plugPikiColin/lightPool.cpp"),
            Object(NonMatching, "plugPikiColin/memoryCard.cpp"),
            Object(NonMatching, "plugPikiColin/moviePlayer.cpp"),
            Object(NonMatching, "plugPikiColin/movSample.cpp"),
        ],
    },
    {
        "lib": "plugPikiKando",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "plugPikiKando/omake.cpp"),
            Object(NonMatching, "plugPikiKando/radarInfo.cpp"),
            Object(NonMatching, "plugPikiKando/interactBattle.cpp"),
            Object(NonMatching, "plugPikiKando/interactGrab.cpp"),
            Object(NonMatching, "plugPikiKando/interactEtc.cpp"),
            Object(NonMatching, "plugPikiKando/interactPullout.cpp"),
            Object(NonMatching, "plugPikiKando/saiEvents.cpp"),
            Object(NonMatching, "plugPikiKando/simpleAI.cpp"),
            Object(NonMatching, "plugPikiKando/formationMgr.cpp"),
            Object(Matching, "plugPikiKando/globalShapes.cpp"),
            Object(NonMatching, "plugPikiKando/playerState.cpp"),
            Object(NonMatching, "plugPikiKando/gameDemo.cpp"),
            Object(NonMatching, "plugPikiKando/demoInvoker.cpp"),
            Object(NonMatching, "plugPikiKando/demoEvent.cpp"),
            Object(NonMatching, "plugPikiKando/resultFlag.cpp"),
            Object(NonMatching, "plugPikiKando/aiConstants.cpp"),
            Object(NonMatching, "plugPikiKando/kio.cpp"),
            Object(NonMatching, "plugPikiKando/keyConfig.cpp"),
            Object(NonMatching, "plugPikiKando/aiPerf.cpp"),
            Object(NonMatching, "plugPikiKando/courseDebug.cpp"),
            Object(NonMatching, "plugPikiKando/memStat.cpp"),
            Object(NonMatching, "plugPikiKando/collInfo.cpp"),
            Object(NonMatching, "plugPikiKando/complexCreature.cpp"),
            Object(NonMatching, "plugPikiKando/creature.cpp"),
            Object(NonMatching, "plugPikiKando/creatureCollision.cpp"),
            Object(NonMatching, "plugPikiKando/creatureCollPart.cpp"),
            Object(NonMatching, "plugPikiKando/creatureMove.cpp"),
            Object(NonMatching, "plugPikiKando/creatureStick.cpp"),
            Object(NonMatching, "plugPikiKando/dualCreature.cpp"),
            Object(NonMatching, "plugPikiKando/dynCreature.cpp"),
            Object(Matching, "plugPikiKando/eventListener.cpp"),
            Object(NonMatching, "plugPikiKando/fastGrid.cpp"),
            Object(NonMatching, "plugPikiKando/ropeCreature.cpp"),
            Object(Matching, "plugPikiKando/objectTypes.cpp"),
            Object(NonMatching, "plugPikiKando/pelletMgr.cpp"),
            Object(NonMatching, "plugPikiKando/animPellet.cpp"),
            Object(NonMatching, "plugPikiKando/genPellet.cpp"),
            Object(NonMatching, "plugPikiKando/pelletState.cpp"),
            Object(NonMatching, "plugPikiKando/workObject.cpp"),
            Object(NonMatching, "plugPikiKando/routeMgr.cpp"),
            Object(NonMatching, "plugPikiKando/seMgr.cpp"),
            Object(NonMatching, "plugPikiKando/seConstants.cpp"),
            Object(NonMatching, "plugPikiKando/soundMgr.cpp"),
            Object(NonMatching, "plugPikiKando/updateMgr.cpp"),
            Object(NonMatching, "plugPikiKando/cPlate.cpp"),
            Object(NonMatching, "plugPikiKando/aiStone.cpp"),
            Object(NonMatching, "plugPikiKando/aiActions.cpp"),
            Object(NonMatching, "plugPikiKando/aiAttack.cpp"),
            Object(NonMatching, "plugPikiKando/aiBore.cpp"),
            Object(NonMatching, "plugPikiKando/aiBoMake.cpp"),
            Object(NonMatching, "plugPikiKando/aiBou.cpp"),
            Object(NonMatching, "plugPikiKando/aiBridge.cpp"),
            Object(NonMatching, "plugPikiKando/aiBreakWall.cpp"),
            Object(NonMatching, "plugPikiKando/aiTransport.cpp"),
            Object(NonMatching, "plugPikiKando/aiKinoko.cpp"),
            Object(NonMatching, "plugPikiKando/aiChase.cpp"),
            Object(NonMatching, "plugPikiKando/aiCrowd.cpp"),
            Object(NonMatching, "plugPikiKando/aiDecoy.cpp"),
            Object(NonMatching, "plugPikiKando/aiEnter.cpp"),
            Object(NonMatching, "plugPikiKando/aiEscape.cpp"),
            Object(NonMatching, "plugPikiKando/aiExit.cpp"),
            Object(NonMatching, "plugPikiKando/aiMine.cpp"),
            Object(NonMatching, "plugPikiKando/aiFormation.cpp"),
            Object(NonMatching, "plugPikiKando/aiFree.cpp"),
            Object(NonMatching, "plugPikiKando/aiGoto.cpp"),
            Object(NonMatching, "plugPikiKando/aiGuard.cpp"),
            Object(NonMatching, "plugPikiKando/aiPick.cpp"),
            Object(NonMatching, "plugPikiKando/aiPickCreature.cpp"),
            Object(NonMatching, "plugPikiKando/aiPullout.cpp"),
            Object(NonMatching, "plugPikiKando/aiPush.cpp"),
            Object(NonMatching, "plugPikiKando/aiPut.cpp"),
            Object(NonMatching, "plugPikiKando/aiRandomBoid.cpp"),
            Object(NonMatching, "plugPikiKando/aiRescue.cpp"),
            Object(NonMatching, "plugPikiKando/aiRope.cpp"),
            Object(NonMatching, "plugPikiKando/aiShoot.cpp"),
            Object(NonMatching, "plugPikiKando/aiWatch.cpp"),
            Object(NonMatching, "plugPikiKando/aiWeed.cpp"),
            Object(NonMatching, "plugPikiKando/aiTable.cpp"),
            Object(NonMatching, "plugPikiKando/aiAction.cpp"),
            Object(NonMatching, "plugPikiKando/pikiInf.cpp"),
            Object(NonMatching, "plugPikiKando/piki.cpp"),
            Object(Matching, "plugPikiKando/odoMeter.cpp"),
            Object(NonMatching, "plugPikiKando/pikidoKill.cpp"),
            Object(NonMatching, "plugPikiKando/pikiMgr.cpp"),
            Object(NonMatching, "plugPikiKando/pikiState.cpp"),
            Object(NonMatching, "plugPikiKando/viewPiki.cpp"),
            Object(Matching, "plugPikiKando/conditions.cpp"),
            Object(NonMatching, "plugPikiKando/generator.cpp"),
            Object(NonMatching, "plugPikiKando/generatorCache.cpp"),
            Object(NonMatching, "plugPikiKando/objectMgr.cpp"),
            Object(NonMatching, "plugPikiKando/searchSystem.cpp"),
            Object(Matching, "plugPikiKando/smartPtr.cpp"),
            Object(NonMatching, "plugPikiKando/itemGem.cpp"),
            Object(NonMatching, "plugPikiKando/weedsItem.cpp"),
            Object(NonMatching, "plugPikiKando/kusaItem.cpp"),
            Object(NonMatching, "plugPikiKando/fishItem.cpp"),
            Object(NonMatching, "plugPikiKando/ufoItem.cpp"),
            Object(NonMatching, "plugPikiKando/ufoAnim.cpp"),
            Object(NonMatching, "plugPikiKando/bombItem.cpp"),
            Object(NonMatching, "plugPikiKando/goalItem.cpp"),
            Object(NonMatching, "plugPikiKando/pikiheadItem.cpp"),
            Object(NonMatching, "plugPikiKando/keyItem.cpp"),
            Object(NonMatching, "plugPikiKando/ropeItem.cpp"),
            Object(NonMatching, "plugPikiKando/seedItem.cpp"),
            Object(NonMatching, "plugPikiKando/genItem.cpp"),
            Object(NonMatching, "plugPikiKando/itemAI.cpp"),
            Object(NonMatching, "plugPikiKando/itemMgr.cpp"),
            Object(NonMatching, "plugPikiKando/itemObject.cpp"),
            Object(NonMatching, "plugPikiKando/mizuItem.cpp"),
            Object(NonMatching, "plugPikiKando/paniItemAnimator.cpp"),
            Object(NonMatching, "plugPikiKando/genNavi.cpp"),
            Object(NonMatching, "plugPikiKando/navi.cpp"),
            Object(NonMatching, "plugPikiKando/naviState.cpp"),
            Object(NonMatching, "plugPikiKando/naviDemoState.cpp"),
            Object(NonMatching, "plugPikiKando/gameCoreSection.cpp"),
            Object(NonMatching, "plugPikiKando/gmWin.cpp"),
            Object(NonMatching, "plugPikiKando/gameStat.cpp"),
            Object(NonMatching, "plugPikiKando/kmath.cpp"),
            Object(NonMatching, "plugPikiKando/uteffect.cpp"),
            Object(NonMatching, "plugPikiKando/kontroller.cpp"),
            Object(Matching, "plugPikiKando/mapcode.cpp"),
            Object(NonMatching, "plugPikiKando/utkando.cpp"),
            Object(NonMatching, "plugPikiKando/naviMgr.cpp"),
            Object(NonMatching, "plugPikiKando/genMapParts.cpp"),
            Object(NonMatching, "plugPikiKando/mapParts.cpp"),
            Object(NonMatching, "plugPikiKando/panipikianimator.cpp"),
            Object(NonMatching, "plugPikiKando/actor.cpp"),
            Object(Matching, "plugPikiKando/actorMgr.cpp"),
            Object(NonMatching, "plugPikiKando/genActor.cpp"),
            Object(Matching, "plugPikiKando/pikiInfo.cpp"),
            Object(NonMatching, "plugPikiKando/plantMgr.cpp"),
            Object(NonMatching, "plugPikiKando/paniPlantAnimator.cpp"),
        ],
    },
    {
        "lib": "plugPikiNakata",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "plugPikiNakata/genteki.cpp"),
            Object(Matching, "plugPikiNakata/nakatacode.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibfunction.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibgeometry.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibgeometry3d.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibgraphics.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibmath.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibspline.cpp"),
            Object(NonMatching, "plugPikiNakata/nlibsystem.cpp"),
            Object(NonMatching, "plugPikiNakata/panianimator.cpp"),
            Object(NonMatching, "plugPikiNakata/panipikianimmgr.cpp"),
            Object(NonMatching, "plugPikiNakata/panitekianimator.cpp"),
            Object(NonMatching, "plugPikiNakata/panitestsection.cpp"),
            Object(NonMatching, "plugPikiNakata/paraparameters.cpp"),
            Object(NonMatching, "plugPikiNakata/pcamcamera.cpp"),
            Object(NonMatching, "plugPikiNakata/pcamcameramanager.cpp"),
            Object(NonMatching, "plugPikiNakata/pcammotionevents.cpp"),
            Object(NonMatching, "plugPikiNakata/pcamcameraparameters.cpp"),
            Object(NonMatching, "plugPikiNakata/peve.cpp"),
            Object(NonMatching, "plugPikiNakata/peveconditions.cpp"),
            Object(NonMatching, "plugPikiNakata/pevemotionevents.cpp"),
            Object(NonMatching, "plugPikiNakata/tai.cpp"),
            Object(NonMatching, "plugPikiNakata/taiattackactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taibasicactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taichappy.cpp"),
            Object(NonMatching, "plugPikiNakata/taicollec.cpp"),
            Object(NonMatching, "plugPikiNakata/taicollisionactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taieffectactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taiiwagen.cpp"),
            Object(NonMatching, "plugPikiNakata/taijudgementactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taikinoko.cpp"),
            Object(NonMatching, "plugPikiNakata/taimessageactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taimizinko.cpp"),
            Object(NonMatching, "plugPikiNakata/taimotionactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taimoveactions.cpp"),
            Object(NonMatching, "plugPikiNakata/tainapkid.cpp"),
            Object(NonMatching, "plugPikiNakata/taiotimoti.cpp"),
            Object(NonMatching, "plugPikiNakata/taipalm.cpp"),
            Object(NonMatching, "plugPikiNakata/taireactionactions.cpp"),
            Object(NonMatching, "plugPikiNakata/taiswallow.cpp"),
            Object(NonMatching, "plugPikiNakata/taishell.cpp"),
            Object(NonMatching, "plugPikiNakata/taitimeractions.cpp"),
            Object(NonMatching, "plugPikiNakata/taiwaitactions.cpp"),
            Object(NonMatching, "plugPikiNakata/teki.cpp"),
            Object(NonMatching, "plugPikiNakata/tekianimationmanager.cpp"),
            Object(NonMatching, "plugPikiNakata/tekibteki.cpp"),
            Object(NonMatching, "plugPikiNakata/tekiconditions.cpp"),
            Object(Matching, "plugPikiNakata/tekievent.cpp"),
            Object(NonMatching, "plugPikiNakata/tekiinteraction.cpp"),
            Object(NonMatching, "plugPikiNakata/tekimgr.cpp"),
            Object(NonMatching, "plugPikiNakata/tekinakata.cpp"),
            Object(NonMatching, "plugPikiNakata/tekinteki.cpp"),
            Object(NonMatching, "plugPikiNakata/tekiparameters.cpp"),
            Object(NonMatching, "plugPikiNakata/tekipersonality.cpp"),
            Object(NonMatching, "plugPikiNakata/tekistrategy.cpp"),
        ],
    },
    {
        "lib": "plugPikiNishimura",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "host": True,
        "objects": [
            Object(NonMatching, "plugPikiNishimura/genBoss.cpp"),
            Object(NonMatching, "plugPikiNishimura/Boss.cpp"),
            Object(NonMatching, "plugPikiNishimura/BossAnimMgr.cpp"),
            Object(NonMatching, "plugPikiNishimura/BossCnd.cpp"),
            Object(NonMatching, "plugPikiNishimura/BossMgr.cpp"),
            Object(NonMatching, "plugPikiNishimura/BossShapeObj.cpp"),
            Object(NonMatching, "plugPikiNishimura/Spider.cpp"),
            Object(NonMatching, "plugPikiNishimura/SpiderAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/SpiderLeg.cpp"),
            Object(NonMatching, "plugPikiNishimura/Snake.cpp"),
            Object(NonMatching, "plugPikiNishimura/SnakeAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/SnakeBody.cpp"),
            Object(NonMatching, "plugPikiNishimura/Slime.cpp"),
            Object(NonMatching, "plugPikiNishimura/SlimeAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/SlimeBody.cpp"),
            Object(NonMatching, "plugPikiNishimura/SlimeCreature.cpp"),
            Object(NonMatching, "plugPikiNishimura/King.cpp"),
            Object(NonMatching, "plugPikiNishimura/KingAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/KingBody.cpp"),
            Object(NonMatching, "plugPikiNishimura/Kogane.cpp"),
            Object(NonMatching, "plugPikiNishimura/KoganeAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/Pom.cpp"),
            Object(NonMatching, "plugPikiNishimura/PomAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/KingBack.cpp"),
            Object(NonMatching, "plugPikiNishimura/Nucleus.cpp"),
            Object(NonMatching, "plugPikiNishimura/NucleusAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/CoreNucleus.cpp"),
            Object(NonMatching, "plugPikiNishimura/CoreNucleusAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/Mizu.cpp"),
            Object(NonMatching, "plugPikiNishimura/MizuAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/nscalculation.cpp"),
            Object(NonMatching, "plugPikiNishimura/RumbleData.cpp"),
            Object(NonMatching, "plugPikiNishimura/HmRumbleMgr.cpp"),
            Object(Matching, "plugPikiNishimura/HmRumbleSample.cpp"),
        ],
    },
    {
        "lib": "plugPikiOgawa",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "host": True,
        "objects": [
            Object(NonMatching, "plugPikiOgawa/ogTest.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogSub.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogTitle.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogPause.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogTutorial.cpp"),
            Object(Matching, "plugPikiOgawa/ogTutorialData.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMap.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogResult.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogRader.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileSelect.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMessage.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMemChk.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogDiary.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMenu.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileChkSel.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMakeDefault.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogTotalScore.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogSave.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogNitaku.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileCopy.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileDelete.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogGraph.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogStart.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogCallBack.cpp"),
        ],
    },
    {
        "lib": "plugPikiYamashita",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "objects": [
            Object(NonMatching, "plugPikiYamashita/gameCourseClear.cpp"),
            Object(NonMatching, "plugPikiYamashita/gameStageClear.cpp"),
            Object(NonMatching, "plugPikiYamashita/gameCredits.cpp"),
            Object(NonMatching, "plugPikiYamashita/zenMath.cpp"),
            Object(NonMatching, "plugPikiYamashita/effectMgr.cpp"),
            Object(NonMatching, "plugPikiYamashita/particleGenerator.cpp"),
            Object(NonMatching, "plugPikiYamashita/particleLoader.cpp"),
            Object(Matching, "plugPikiYamashita/solidField.cpp"),
            Object(NonMatching, "plugPikiYamashita/particleManager.cpp"),
            Object(NonMatching, "plugPikiYamashita/particleMdlManager.cpp"),
            Object(NonMatching, "plugPikiYamashita/bBoardColourAnim.cpp"),
            Object(NonMatching, "plugPikiYamashita/simpleParticle.cpp"),
            Object(NonMatching, "plugPikiYamashita/tekiyteki.cpp"),
            Object(NonMatching, "plugPikiYamashita/tekiyamashita.cpp"),
            Object(Matching, "plugPikiYamashita/TAIanimation.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAItank.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAImar.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAreaction.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAmove.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAmotion.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAjudge.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAattack.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DGrafContext.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DOrthoGraph.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DPerspGraph.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DPane.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DPicture.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DScreen.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DStream.cpp"),
            Object(NonMatching, "plugPikiYamashita/PSUList.cpp"),
            Object(NonMatching, "plugPikiYamashita/PUTRect.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DWindow.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DTextBox.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DPrint.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DFont.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawGameInfo.cpp"),
            Object(NonMatching, "plugPikiYamashita/zenGraphics.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawContainer.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCommon.cpp"),
            Object(NonMatching, "plugPikiYamashita/zenController.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawHurryUp.cpp"),
            Object(NonMatching, "plugPikiYamashita/texAnim.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawAccount.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawMenu.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIeffectAttack.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIbeatle.cpp"),
            Object(NonMatching, "plugPikiYamashita/menuPanelMgr.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIkabekuiA.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIkabekuiB.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIkabekuiC.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAItamago.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIdororo.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIhibaA.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIAeffect.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAImiurin.cpp"),
            Object(Matching, "plugPikiYamashita/ptclGenPack.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawProgre.cpp"),
            Object(NonMatching, "plugPikiYamashita/spectrumCursorMgr.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawWorldMap.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCountDown.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawGameOver.cpp"),
            Object(NonMatching, "plugPikiYamashita/yai.cpp"),
            Object(NonMatching, "plugPikiYamashita/effectMgr2D.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawWMPause.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIusuba.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIotama.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMcourseSelect.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMtitle.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMscore.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMbest.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMresult.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawMenuBase.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawHiScore.cpp"),
            Object(NonMatching, "plugPikiYamashita/damageEffect.cpp"),
            Object(NonMatching, "plugPikiYamashita/alphaWipe.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawUfoParts.cpp"),
            Object(NonMatching, "plugPikiYamashita/zenSys.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawSaveMes.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawSaveFailure.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawFinalResult.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawOptionSave.cpp"),
        ],
    },
    DolphinLib(
        "base",
        [
            Object(Matching, "base/PPCArch.c"),
        ],
    ),
    DolphinLib(
        "os",
        [
            Object(NonMatching, "os/OS.c"),
            Object(NonMatching, "os/OSAlarm.c"),
            Object(Matching, "os/OSAlloc.c"),
            Object(Matching, "os/OSArena.c"),
            Object(NonMatching, "os/OSAudioSystem.c"),
            Object(NonMatching, "os/OSCache.c"),
            Object(NonMatching, "os/OSContext.c"),
            Object(Matching, "os/OSError.c"),
            Object(NonMatching, "os/OSExi.c"),
            Object(NonMatching, "os/OSFont.c"),
            Object(NonMatching, "os/OSInterrupt.c"),
            Object(Matching, "os/OSLink.c"),
            Object(NonMatching, "os/OSMessage.c"),
            Object(NonMatching, "os/OSMemory.c"),
            Object(NonMatching, "os/OSMutex.c"),
            Object(NonMatching, "os/OSReboot.c"),
            Object(NonMatching, "os/OSReset.c"),
            Object(NonMatching, "os/OSResetSW.c"),
            Object(NonMatching, "os/OSRtc.c"),
            Object(NonMatching, "os/OSSerial.c"),
            Object(NonMatching, "os/OSSync.c"),
            Object(NonMatching, "os/OSThread.c"),
            Object(NonMatching, "os/OSTime.c"),
            Object(NonMatching, "os/OSUartExi.c"),
            Object(Matching, "os/__start.c"),
            Object(NonMatching, "os/__ppc_eabi_init.cpp"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(NonMatching, "db/db.c"),
        ]
    ),
    DolphinLib(
        "mtx",
        [
            Object(NonMatching, "mtx/mtx.c"),
            Object(NonMatching, "mtx/mtx44.c"),
            Object(NonMatching, "mtx/vec.c"),
        ]
    ),
    DolphinLib(
        "dvd",
        [
            Object(NonMatching, "dvd/dvdlow.c"),
            Object(NonMatching, "dvd/dvdfs.c"),
            Object(NonMatching, "dvd/dvd.c"),
            Object(NonMatching, "dvd/dvdqueue.c"),
            Object(NonMatching, "dvd/dvderror.c"),
            Object(NonMatching, "dvd/fstload.c"),
        ]
    ),
    DolphinLib(
        "vi",
        [
            Object(NonMatching, "vi/vi.c"),
        ]
    ),
    DolphinLib(
        "pad",
        [
            Object(NonMatching, "pad/Padclamp.c"),
            Object(NonMatching, "pad/Pad.c"),
        ]
    ),
    DolphinLib(
        "ai",
        [
            Object(NonMatching, "ai/ai.c"),
        ]
    ),
    DolphinLib(
        "ar",
        [
            Object(NonMatching, "ar/ar.c"),
        ]
    ),
    DolphinLib(
        "arq",
        [
            Object(NonMatching, "ar/arq.c"),
        ]
    ),
    DolphinLib(
        "dsp",
        [
            Object(Matching, "dsp/dsp.c"),
        ]
    ),
    DolphinLib(
        "card",
        [
            Object(NonMatching, "card/CARDBios.c"),
            Object(NonMatching, "card/CARDRdwr.c"),
            Object(NonMatching, "card/CARDBlock.c"),
            Object(NonMatching, "card/CARDDir.c"),
            Object(NonMatching, "card/CARDCheck.c"),
            Object(NonMatching, "card/CARDMount.c"),
            Object(NonMatching, "card/CARDFormat.c"),
            Object(NonMatching, "card/CARDOpen.c"),
            Object(NonMatching, "card/CARDCreate.c"),
            Object(NonMatching, "card/CARDRead.c"),
            Object(NonMatching, "card/CARDWrite.c"),
            Object(NonMatching, "card/CARDDelete.c"),
            Object(NonMatching, "card/CARDStat.c"),
            Object(NonMatching, "card/CARDRename.c"),
        ]
    ),
    DolphinLib(
        "hio",
        [
            Object(NonMatching, "hio/hio.c"),
        ]
    ),
    DolphinLib(
        "gx",
        [
            Object(NonMatching, "gx/GXInit.c"),
            Object(NonMatching, "gx/GXFifo.c"),
            Object(NonMatching, "gx/GXAttr.c"),
            Object(NonMatching, "gx/GXMisc.c"),
            Object(NonMatching, "gx/GXGeometry.c"),
            Object(NonMatching, "gx/GXFrameBuf.c"),
            Object(NonMatching, "gx/GXLight.c"),
            Object(NonMatching, "gx/GXTexture.c"),
            Object(NonMatching, "gx/GXBump.c"),
            Object(NonMatching, "gx/GXTev.c"),
            Object(NonMatching, "gx/GXPixel.c"),
            Object(Matching, "gx/GXStubs.c"),
            Object(NonMatching, "gx/GXDisplayList.c"),
            Object(NonMatching, "gx/GXTransform.c"),
            Object(NonMatching, "gx/GXPerf.c"),
        ]
    ),
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "Runtime/PPCEABI/H/__mem.o"),
            Object(NonMatching, "Runtime/PPCEABI/H/__va_arg.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/CPlusLibPPC.cp"),
            Object(NonMatching, "Runtime/PPCEABI/H/NMWException.cp"),
            Object(Matching, "Runtime/PPCEABI/H/ptmf.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/ExceptionPPC.cp"),
            Object(NonMatching, "Runtime/PPCEABI/H/runtime.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/__init_cpp_exceptions.cpp"),
        ],
    },
    {
        "lib": "MSL_C.PPCEABI.bare.H",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/abort_exit.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/errno.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/ansi_fp.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/arith.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/buffer_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/critical_regions.ppc_eabi.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/ctype.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/ansi_files.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/locale.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/direct_io.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/mbstring.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/mem.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/mem_funcs.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/misc_io.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/printf.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/rand.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/scanf.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/string.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/strtold.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/strtoul.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/uart_console_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/wchar_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/float.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/e_asin.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/e_atan2.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/e_pow.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/fminmaxdim.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/s_atan.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_copysign.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_frexp.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/s_ldexp.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/w_atan2.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/w_pow.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/hyperbolicsf.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/inverse_trig.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/trigf.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/math_inlines.c"),
            Object(NonMatching, "MSL_C/PPCEABI/bare/H/common_float_tables.c"),
        ],
    },
    {
        "lib": "TRK_MINNOW_DOLPHIN",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mainloop.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/nubevent.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/nubinit.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msg.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msgbuf.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/serpoll.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/usr_put.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dispatch.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/msghndlr.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/support.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mutex_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/notify.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/flush_cache.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mem_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/__exception.s"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targimpl.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dolphin_trk.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/main_TRK.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
            Object(NonMatching, "TRK_MINNOW_DOLPHIN/targcont.c"),
        ],
    },
    {
        "lib": "amcExi2",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "amcExi2/AmcExi.c"),
            Object(NonMatching, "amcExi2/AmcExi2Comm.c"),
        ],
    },
    {
        "lib": "amcnotstub",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(Matching, "amcnotstub/amcnotstub.c"),
        ],
    },
    {
        "lib": "OdemuExi2",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "OdemuExi2/DebuggerDriver.c"),
        ],
    },
    {
        "lib": "odenotstub",
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "objects": [
            Object(Matching, "odenotstub/odenotstub.c"),
        ],
    },
]

# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
