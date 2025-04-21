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

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

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
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
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
config.generate_compile_commands = False
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20240706"
config.dtk_tag = "v1.3.0"
config.objdiff_tag = "v2.4.0"
config.sjiswrap_tag = "v1.2.0"
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

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = 62  # Pikmin

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
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.extend(["-DNDEBUG=1", "-w off"]) # no I DO not want to talk about my car's extended warranty.

# JAudio flags
cflags_jaudio = [
    "-nodefaults",
    "-proc 750",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    # "-W all",
    "-O4,s",
    "-inline off",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse, readonly",
    "-multibyte",
    "-i include",
    "-i include/stl",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
    "-common on",
    "-func_align 32",
    "-lang c++",
    "-DNDEBUG=1", 
    "-w off",
    "-use_lmw_stmw on",
]

# Game code flags
cflags_pikmin = [
    *cflags_base,
    "-fp_contract off",
    "-RTTI on",
]

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,readonly",
    "-common off",
    "-inline auto",
]

# Dolphin mtx library flags
cflags_mtx = [
    *cflags_base,
    "-fp_contract off",
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


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "sysBootup",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Matching, "sysBootup.cpp"),
        ],
    },
    {
        "lib": "jaudio",
        "cflags": cflags_jaudio,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "jaudio",
        "objects": [
            Object(Matching, "jaudio/dummyprobe.c"),
            Object(Matching, "jaudio/memory.c"),
            Object(NonMatching, "jaudio/aictrl.c"),
            Object(Matching, "jaudio/sample.c"),
            Object(Matching, "jaudio/dummyrom.c"),
            Object(Matching, "jaudio/audiothread.c"),
            Object(Matching, "jaudio/streamctrl.c"),
            Object(Matching, "jaudio/dspbuf.c"),
            Object(Matching, "jaudio/cpubuf.c"),
            Object(Matching, "jaudio/playercall.c"),
            Object(Matching, "jaudio/dvdthread.c"),
            Object(Matching, "jaudio/rate.c"),
            Object(Matching, "jaudio/audiomesg.c"),
            Object(Matching, "jaudio/stackchecker.c"),
            Object(Matching, "jaudio/dspboot.c"),
            Object(Matching, "jaudio/dspproc.c"),
            Object(Matching, "jaudio/ipldec.c"),
            Object(Matching, "jaudio/dsp_cardunlock.c"),
            Object(NonMatching, "jaudio/driverinterface.c"),
            Object(NonMatching, "jaudio/dspdriver.c"),
            Object(Equivalent, "jaudio/dspinterface.c"),
            Object(Matching, "jaudio/fxinterface.c"),
            Object(NonMatching, "jaudio/bankread.c"),
            Object(NonMatching, "jaudio/waveread.c"),
            Object(NonMatching, "jaudio/connect.c"),
            Object(Matching, "jaudio/tables.c"),
            Object(NonMatching, "jaudio/bankdrv.c"),
            Object(Matching, "jaudio/random.c"),
            Object(NonMatching, "jaudio/aramcall.c"),
            Object(Matching, "jaudio/ja_calc.c"),
            Object(NonMatching, "jaudio/fat.c"),
            Object(NonMatching, "jaudio/cmdstack.c"),
            Object(NonMatching, "jaudio/virload.c"),
            Object(NonMatching, "jaudio/heapctrl.c"),
            Object(NonMatching, "jaudio/jammain_2.c"),
            Object(NonMatching, "jaudio/midplay.c"),
            Object(NonMatching, "jaudio/noteon.c"),
            Object(NonMatching, "jaudio/seqsetup.c"),
            Object(Matching, "jaudio/centcalc.c"),
            Object(NonMatching, "jaudio/jamosc.c"),
            Object(NonMatching, "jaudio/oneshot.c"),
            Object(Matching, "jaudio/interface.c"),
            Object(Equivalent, "jaudio/verysimple.c"),
            Object(Matching, "jaudio/app_inter.c"),
            Object(NonMatching, "jaudio/pikiinter.c"),
            Object(NonMatching, "jaudio/piki_player.c"),
            Object(NonMatching, "jaudio/piki_bgm.c"),
            Object(NonMatching, "jaudio/piki_scene.c"),
            Object(NonMatching, "jaudio/pikidemo.c"),
            Object(NonMatching, "jaudio/file_seq.c"),
            Object(Equivalent, "jaudio/cmdqueue.c"),
            Object(Matching, "jaudio/filter3d.c"),
            Object(NonMatching, "jaudio/syncstream.c"),
            Object(NonMatching, "jaudio/bankloader.c"),
            Object(NonMatching, "jaudio/interleave.c"),
            Object(Matching, "jaudio/pikiseq.c"),
            Object(NonMatching, "jaudio/hplaybss.c"),
            Object(NonMatching, "jaudio/hplaybss2.c"),
            Object(NonMatching, "jaudio/hvqm_play.c"),
        ],
    },
    {
        "lib": "hvqm4dec",
        "cflags": cflags_base,
        "mw_version": "GC/1.2.5",
        "progress_category" : "hvqm4dec",
        "objects": [
            Object(NonMatching, "hvqm4dec/hvqm4dec.c"),
        ],
    },
    {
        "lib": "sysCommon",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(NonMatching, "sysCommon/ayuStack.cpp"),
            Object(Matching, "sysCommon/baseApp.cpp"),
            Object(Matching, "sysCommon/stream.cpp"),
            Object(Matching, "sysCommon/streamBufferedInput.cpp"),
            Object(Matching, "sysCommon/string.cpp"),
            Object(NonMatching, "sysCommon/graphics.cpp"),
            Object(Matching, "sysCommon/grLight.cpp"),
            Object(Equivalent, "sysCommon/shapeBase.cpp"),
            Object(Matching, "sysCommon/shpLightFlares.cpp"),
            Object(Matching, "sysCommon/shpObjColl.cpp"),
            Object(NonMatching, "sysCommon/shpRoutes.cpp"),
            Object(Matching, "sysCommon/sysMath.cpp"),
            Object(Matching, "sysCommon/matMath.cpp"),
            Object(Matching, "sysCommon/stdSystem.cpp"),
            Object(Matching, "sysCommon/node.cpp"),
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
        "progress_category" : "game",
        "objects": [
            Object(NonMatching, "sysDolphin/texture.cpp"),
            Object(NonMatching, "sysDolphin/system.cpp"),
            Object(NonMatching, "sysDolphin/sysNew.cpp"),
            Object(Matching, "sysDolphin/controllerMgr.cpp"),
            Object(NonMatching, "sysDolphin/dgxGraphics.cpp"),
            Object(Matching, "sysDolphin/gameApp.cpp"),
        ],
    },
    {
        "lib": "plugPikiColin",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(NonMatching, "plugPikiColin/cardutil.cpp"),
            Object(NonMatching, "plugPikiColin/dynsimulator.cpp"),
            Object(NonMatching, "plugPikiColin/animMgr.cpp"),
            Object(NonMatching, "plugPikiColin/gameflow.cpp"),
            Object(NonMatching, "plugPikiColin/game.cpp"),
            Object(NonMatching, "plugPikiColin/gamePrefs.cpp"),
            Object(NonMatching, "plugPikiColin/gameSetup.cpp"),
            Object(Matching, "plugPikiColin/cardSelect.cpp"),
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
            Object(Matching, "plugPikiColin/ninLogo.cpp"),
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
        "progress_category" : "game",
        "objects": [
            Object(Equivalent, "plugPikiKando/omake.cpp"),
            Object(Matching, "plugPikiKando/radarInfo.cpp"),
            Object(Matching, "plugPikiKando/interactBattle.cpp"),
            Object(Matching, "plugPikiKando/interactGrab.cpp"),
            Object(Matching, "plugPikiKando/interactEtc.cpp"),
            Object(Matching, "plugPikiKando/interactPullout.cpp"),
            Object(Matching, "plugPikiKando/saiEvents.cpp"),
            Object(Equivalent, "plugPikiKando/simpleAI.cpp"),
            Object(Equivalent, "plugPikiKando/formationMgr.cpp"),
            Object(Matching, "plugPikiKando/globalShapes.cpp"),
            Object(Equivalent, "plugPikiKando/playerState.cpp"),
            Object(Matching, "plugPikiKando/gameDemo.cpp"),
            Object(Matching, "plugPikiKando/demoInvoker.cpp"),
            Object(Matching, "plugPikiKando/demoEvent.cpp"),
            Object(Matching, "plugPikiKando/resultFlag.cpp"),
            Object(Matching, "plugPikiKando/aiConstants.cpp"),
            Object(Matching, "plugPikiKando/kio.cpp"),
            Object(Matching, "plugPikiKando/keyConfig.cpp"),
            Object(Matching, "plugPikiKando/aiPerf.cpp"),
            Object(Matching, "plugPikiKando/courseDebug.cpp"),
            Object(Equivalent, "plugPikiKando/memStat.cpp"),
            Object(Matching, "plugPikiKando/collInfo.cpp"),
            Object(Matching, "plugPikiKando/complexCreature.cpp"),
            Object(Matching, "plugPikiKando/creature.cpp"),
            Object(Matching, "plugPikiKando/creatureCollision.cpp"),
            Object(Matching, "plugPikiKando/creatureCollPart.cpp"),
            Object(Equivalent, "plugPikiKando/creatureMove.cpp"),
            Object(Matching, "plugPikiKando/creatureStick.cpp"),
            Object(Matching, "plugPikiKando/dualCreature.cpp"),
            Object(Matching, "plugPikiKando/dynCreature.cpp"),
            Object(Matching, "plugPikiKando/eventListener.cpp"),
            Object(Matching, "plugPikiKando/fastGrid.cpp"),
            Object(Matching, "plugPikiKando/ropeCreature.cpp"),
            Object(Matching, "plugPikiKando/objectTypes.cpp"),
            Object(Matching, "plugPikiKando/pelletMgr.cpp"),
            Object(Matching, "plugPikiKando/animPellet.cpp"),
            Object(Matching, "plugPikiKando/genPellet.cpp"),
            Object(Matching, "plugPikiKando/pelletState.cpp"),
            Object(Equivalent, "plugPikiKando/workObject.cpp"),
            Object(Matching, "plugPikiKando/routeMgr.cpp"),
            Object(Matching, "plugPikiKando/seMgr.cpp"),
            Object(Matching, "plugPikiKando/seConstants.cpp"),
            Object(Matching, "plugPikiKando/soundMgr.cpp"),
            Object(Matching, "plugPikiKando/updateMgr.cpp"),
            Object(Matching, "plugPikiKando/cPlate.cpp"),
            Object(Equivalent, "plugPikiKando/aiStone.cpp"),
            Object(Equivalent, "plugPikiKando/aiActions.cpp"),
            Object(Equivalent, "plugPikiKando/aiAttack.cpp"),
            Object(Matching, "plugPikiKando/aiBore.cpp"),
            Object(Equivalent, "plugPikiKando/aiBoMake.cpp"),
            Object(Matching, "plugPikiKando/aiBou.cpp"),
            Object(Equivalent, "plugPikiKando/aiBridge.cpp"),
            Object(Matching, "plugPikiKando/aiBreakWall.cpp"),
            Object(Equivalent, "plugPikiKando/aiTransport.cpp"),
            Object(Equivalent, "plugPikiKando/aiKinoko.cpp"),
            Object(Matching, "plugPikiKando/aiChase.cpp"),
            Object(Equivalent, "plugPikiKando/aiCrowd.cpp"),
            Object(Equivalent, "plugPikiKando/aiDecoy.cpp"),
            Object(Matching, "plugPikiKando/aiEnter.cpp"),
            Object(Matching, "plugPikiKando/aiEscape.cpp"),
            Object(Matching, "plugPikiKando/aiExit.cpp"),
            Object(Matching, "plugPikiKando/aiMine.cpp"),
            Object(Matching, "plugPikiKando/aiFormation.cpp"),
            Object(Matching, "plugPikiKando/aiFree.cpp"),
            Object(Matching, "plugPikiKando/aiGoto.cpp"),
            Object(Matching, "plugPikiKando/aiGuard.cpp"),
            Object(Matching, "plugPikiKando/aiPick.cpp"),
            Object(Matching, "plugPikiKando/aiPickCreature.cpp"),
            Object(Equivalent, "plugPikiKando/aiPullout.cpp"),
            Object(Matching, "plugPikiKando/aiPush.cpp"),
            Object(Matching, "plugPikiKando/aiPut.cpp"),
            Object(Equivalent, "plugPikiKando/aiRandomBoid.cpp"),
            Object(Matching, "plugPikiKando/aiRescue.cpp"),
            Object(Matching, "plugPikiKando/aiRope.cpp"),
            Object(Matching, "plugPikiKando/aiShoot.cpp"),
            Object(Matching, "plugPikiKando/aiWatch.cpp"),
            Object(Equivalent, "plugPikiKando/aiWeed.cpp"),
            Object(Matching, "plugPikiKando/aiTable.cpp"),
            Object(Matching, "plugPikiKando/aiAction.cpp"),
            Object(Matching, "plugPikiKando/pikiInf.cpp"),
            Object(Equivalent, "plugPikiKando/piki.cpp"),
            Object(Matching, "plugPikiKando/odoMeter.cpp"),
            Object(Matching, "plugPikiKando/pikidoKill.cpp"),
            Object(Matching, "plugPikiKando/pikiMgr.cpp"),
            Object(Matching, "plugPikiKando/pikiState.cpp"),
            Object(Matching, "plugPikiKando/viewPiki.cpp"),
            Object(Matching, "plugPikiKando/conditions.cpp"),
            Object(Equivalent, "plugPikiKando/generator.cpp"),
            Object(Equivalent, "plugPikiKando/generatorCache.cpp"),
            Object(Matching, "plugPikiKando/objectMgr.cpp"),
            Object(Matching, "plugPikiKando/searchSystem.cpp"),
            Object(Matching, "plugPikiKando/smartPtr.cpp"),
            Object(Matching, "plugPikiKando/itemGem.cpp"),
            Object(Matching, "plugPikiKando/weedsItem.cpp"),
            Object(Matching, "plugPikiKando/kusaItem.cpp"),
            Object(Matching, "plugPikiKando/fishItem.cpp"),
            Object(Equivalent, "plugPikiKando/ufoItem.cpp"),
            Object(Matching, "plugPikiKando/ufoAnim.cpp"),
            Object(Matching, "plugPikiKando/bombItem.cpp"),
            Object(Equivalent, "plugPikiKando/goalItem.cpp"),
            Object(Matching, "plugPikiKando/pikiheadItem.cpp"),
            Object(Matching, "plugPikiKando/keyItem.cpp"),
            Object(Matching, "plugPikiKando/ropeItem.cpp"),
            Object(Matching, "plugPikiKando/seedItem.cpp"),
            Object(Matching, "plugPikiKando/genItem.cpp"),
            Object(Matching, "plugPikiKando/itemAI.cpp"),
            Object(Equivalent, "plugPikiKando/itemMgr.cpp"),
            Object(Matching, "plugPikiKando/itemObject.cpp"),
            Object(Matching, "plugPikiKando/mizuItem.cpp"),
            Object(Matching, "plugPikiKando/paniItemAnimator.cpp"),
            Object(Matching, "plugPikiKando/genNavi.cpp"),
            Object(Equivalent, "plugPikiKando/navi.cpp"),
            Object(Equivalent, "plugPikiKando/naviState.cpp"),
            Object(Matching, "plugPikiKando/naviDemoState.cpp"),
            Object(Matching, "plugPikiKando/gameCoreSection.cpp"),
            Object(Matching, "plugPikiKando/gmWin.cpp"),
            Object(Matching, "plugPikiKando/gameStat.cpp"),
            Object(Matching, "plugPikiKando/kmath.cpp"),
            Object(Equivalent, "plugPikiKando/uteffect.cpp"),
            Object(Equivalent, "plugPikiKando/kontroller.cpp"),
            Object(Matching, "plugPikiKando/mapcode.cpp"),
            Object(Matching, "plugPikiKando/utkando.cpp"),
            Object(Matching, "plugPikiKando/naviMgr.cpp"),
            Object(Matching, "plugPikiKando/genMapParts.cpp"),
            Object(Equivalent, "plugPikiKando/mapParts.cpp"),
            Object(Matching, "plugPikiKando/panipikianimator.cpp"),
            Object(Matching, "plugPikiKando/actor.cpp"),
            Object(Matching, "plugPikiKando/actorMgr.cpp"),
            Object(Matching, "plugPikiKando/genActor.cpp"),
            Object(Matching, "plugPikiKando/pikiInfo.cpp"),
            Object(Matching, "plugPikiKando/plantMgr.cpp"),
            Object(Matching, "plugPikiKando/paniPlantAnimator.cpp"),
        ],
    },
    {
        "lib": "plugPikiNakata",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Matching, "plugPikiNakata/genteki.cpp"),
            Object(Matching, "plugPikiNakata/nakatacode.cpp"),
            Object(Matching, "plugPikiNakata/nlibfunction.cpp"),
            Object(Equivalent, "plugPikiNakata/nlibgeometry.cpp"),
            Object(Matching, "plugPikiNakata/nlibgeometry3d.cpp"),
            Object(Matching, "plugPikiNakata/nlibgraphics.cpp"),
            Object(Matching, "plugPikiNakata/nlibmath.cpp"),
            Object(Matching, "plugPikiNakata/nlibspline.cpp"),
            Object(Equivalent, "plugPikiNakata/nlibsystem.cpp"),
            Object(Matching, "plugPikiNakata/panianimator.cpp"),
            Object(Matching, "plugPikiNakata/panipikianimmgr.cpp"),
            Object(Matching, "plugPikiNakata/panitekianimator.cpp"),
            Object(Matching, "plugPikiNakata/panitestsection.cpp"),
            Object(Matching, "plugPikiNakata/paraparameters.cpp"),
            Object(Matching, "plugPikiNakata/pcamcamera.cpp"),
            Object(Matching, "plugPikiNakata/pcamcameramanager.cpp"),
            Object(Matching, "plugPikiNakata/pcammotionevents.cpp"),
            Object(Matching, "plugPikiNakata/pcamcameraparameters.cpp"),
            Object(Matching, "plugPikiNakata/peve.cpp"),
            Object(Matching, "plugPikiNakata/peveconditions.cpp"),
            Object(Matching, "plugPikiNakata/pevemotionevents.cpp"),
            Object(Equivalent, "plugPikiNakata/tai.cpp"),
            Object(Matching, "plugPikiNakata/taiattackactions.cpp"),
            Object(Matching, "plugPikiNakata/taibasicactions.cpp"),
            Object(Matching, "plugPikiNakata/taichappy.cpp"),
            Object(Matching, "plugPikiNakata/taicollec.cpp"),
            Object(Matching, "plugPikiNakata/taicollisionactions.cpp"),
            Object(Matching, "plugPikiNakata/taieffectactions.cpp"),
            Object(Matching, "plugPikiNakata/taiiwagen.cpp"),
            Object(Matching, "plugPikiNakata/taijudgementactions.cpp"),
            Object(Matching, "plugPikiNakata/taikinoko.cpp"),
            Object(Matching, "plugPikiNakata/taimessageactions.cpp"),
            Object(Equivalent, "plugPikiNakata/taimizinko.cpp"),
            Object(Matching, "plugPikiNakata/taimotionactions.cpp"),
            Object(Matching, "plugPikiNakata/taimoveactions.cpp"),
            Object(NonMatching, "plugPikiNakata/tainapkid.cpp"),
            Object(Matching, "plugPikiNakata/taiotimoti.cpp"),
            Object(Matching, "plugPikiNakata/taipalm.cpp"),
            Object(Matching, "plugPikiNakata/taireactionactions.cpp"),
            Object(Matching, "plugPikiNakata/taiswallow.cpp"),
            Object(Matching, "plugPikiNakata/taishell.cpp"),
            Object(Matching, "plugPikiNakata/taitimeractions.cpp"),
            Object(Matching, "plugPikiNakata/taiwaitactions.cpp"),
            Object(Matching, "plugPikiNakata/teki.cpp"),
            Object(Matching, "plugPikiNakata/tekianimationmanager.cpp"),
            Object(Matching, "plugPikiNakata/tekibteki.cpp"),
            Object(Matching, "plugPikiNakata/tekiconditions.cpp"),
            Object(Matching, "plugPikiNakata/tekievent.cpp"),
            Object(Matching, "plugPikiNakata/tekiinteraction.cpp"),
            Object(Matching, "plugPikiNakata/tekimgr.cpp"),
            Object(Matching, "plugPikiNakata/tekinakata.cpp"),
            Object(Matching, "plugPikiNakata/tekinteki.cpp"),
            Object(Matching, "plugPikiNakata/tekiparameters.cpp"),
            Object(Matching, "plugPikiNakata/tekipersonality.cpp"),
            Object(Matching, "plugPikiNakata/tekistrategy.cpp"),
        ],
    },
    {
        "lib": "plugPikiNishimura",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Matching, "plugPikiNishimura/genBoss.cpp"),
            Object(Matching, "plugPikiNishimura/Boss.cpp"),
            Object(Matching, "plugPikiNishimura/BossAnimMgr.cpp"),
            Object(Matching, "plugPikiNishimura/BossCnd.cpp"),
            Object(Matching, "plugPikiNishimura/BossMgr.cpp"),
            Object(Matching, "plugPikiNishimura/BossShapeObj.cpp"),
            Object(Matching, "plugPikiNishimura/Spider.cpp"),
            Object(Matching, "plugPikiNishimura/SpiderAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/SpiderLeg.cpp"),
            Object(Matching, "plugPikiNishimura/Snake.cpp"),
            Object(NonMatching, "plugPikiNishimura/SnakeAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/SnakeBody.cpp"),
            Object(Matching, "plugPikiNishimura/Slime.cpp"),
            Object(Matching, "plugPikiNishimura/SlimeAi.cpp"),
            Object(Matching, "plugPikiNishimura/SlimeBody.cpp"),
            Object(Matching, "plugPikiNishimura/SlimeCreature.cpp"),
            Object(Matching, "plugPikiNishimura/King.cpp"),
            Object(NonMatching, "plugPikiNishimura/KingAi.cpp"),
            Object(Matching, "plugPikiNishimura/KingBody.cpp"),
            Object(Matching, "plugPikiNishimura/Kogane.cpp"),
            Object(Matching, "plugPikiNishimura/KoganeAi.cpp"),
            Object(Matching, "plugPikiNishimura/Pom.cpp"),
            Object(Matching, "plugPikiNishimura/PomAi.cpp"),
            Object(Matching, "plugPikiNishimura/KingBack.cpp"),
            Object(Matching, "plugPikiNishimura/Nucleus.cpp"),
            Object(Matching, "plugPikiNishimura/NucleusAi.cpp"),
            Object(Matching, "plugPikiNishimura/CoreNucleus.cpp"),
            Object(Matching, "plugPikiNishimura/CoreNucleusAi.cpp"),
            Object(Matching, "plugPikiNishimura/Mizu.cpp"),
            Object(Matching, "plugPikiNishimura/MizuAi.cpp"),
            Object(NonMatching, "plugPikiNishimura/nscalculation.cpp"),
            Object(NonMatching, "plugPikiNishimura/RumbleData.cpp"),
            Object(Matching, "plugPikiNishimura/HmRumbleMgr.cpp"),
            Object(Matching, "plugPikiNishimura/HmRumbleSample.cpp"),
        ],
    },
    {
        "lib": "plugPikiOgawa",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(NonMatching, "plugPikiOgawa/ogTest.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogSub.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogTitle.cpp"),
            Object(Matching, "plugPikiOgawa/ogPause.cpp"),
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
            Object(Matching, "plugPikiOgawa/ogFileChkSel.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogMakeDefault.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogTotalScore.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogSave.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogNitaku.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileCopy.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogFileDelete.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogGraph.cpp"),
            Object(Matching, "plugPikiOgawa/ogStart.cpp"),
            Object(NonMatching, "plugPikiOgawa/ogCallBack.cpp"),
        ],
    },
    {
        "lib": "plugPikiYamashita",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(NonMatching, "plugPikiYamashita/gameCourseClear.cpp"),
            Object(Matching, "plugPikiYamashita/gameStageClear.cpp"),
            Object(Matching, "plugPikiYamashita/gameCredits.cpp"),
            Object(Matching, "plugPikiYamashita/zenMath.cpp"),
            Object(Matching, "plugPikiYamashita/effectMgr.cpp"),
            Object(Equivalent, "plugPikiYamashita/particleGenerator.cpp"),
            Object(Matching, "plugPikiYamashita/particleLoader.cpp"),
            Object(Matching, "plugPikiYamashita/solidField.cpp"),
            Object(Matching, "plugPikiYamashita/particleManager.cpp"),
            Object(Matching, "plugPikiYamashita/particleMdlManager.cpp"),
            Object(Matching, "plugPikiYamashita/bBoardColourAnim.cpp"),
            Object(Matching, "plugPikiYamashita/simpleParticle.cpp"),
            Object(Matching, "plugPikiYamashita/tekiyteki.cpp"),
            Object(Matching, "plugPikiYamashita/tekiyamashita.cpp"),
            Object(Matching, "plugPikiYamashita/TAIanimation.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAItank.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAImar.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAreaction.cpp"),
            Object(Equivalent, "plugPikiYamashita/TAIAmove.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAmotion.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAjudge.cpp"),
            Object(Equivalent, "plugPikiYamashita/TAIAattack.cpp"),
            Object(Matching, "plugPikiYamashita/P2DGrafContext.cpp"),
            Object(Matching, "plugPikiYamashita/P2DOrthoGraph.cpp"),
            Object(Matching, "plugPikiYamashita/P2DPerspGraph.cpp"),
            Object(Matching, "plugPikiYamashita/P2DPane.cpp"),
            Object(Equivalent, "plugPikiYamashita/P2DPicture.cpp"),
            Object(Matching, "plugPikiYamashita/P2DScreen.cpp"),
            Object(Matching, "plugPikiYamashita/P2DStream.cpp"),
            Object(Matching, "plugPikiYamashita/PSUList.cpp"),
            Object(Matching, "plugPikiYamashita/PUTRect.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DWindow.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DTextBox.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DPrint.cpp"),
            Object(NonMatching, "plugPikiYamashita/P2DFont.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawGameInfo.cpp"),
            Object(NonMatching, "plugPikiYamashita/zenGraphics.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawContainer.cpp"),
            Object(Matching, "plugPikiYamashita/drawCommon.cpp"),
            Object(Matching, "plugPikiYamashita/zenController.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawHurryUp.cpp"),
            Object(Matching, "plugPikiYamashita/texAnim.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawAccount.cpp"),
            Object(Equivalent, "plugPikiYamashita/drawMenu.cpp"),
            Object(Equivalent, "plugPikiYamashita/TAIeffectAttack.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIbeatle.cpp"),
            Object(NonMatching, "plugPikiYamashita/menuPanelMgr.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiA.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiB.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiC.cpp"),
            Object(Matching, "plugPikiYamashita/TAItamago.cpp"),
            Object(Equivalent, "plugPikiYamashita/TAIdororo.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIhibaA.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAeffect.cpp"),
            Object(Matching, "plugPikiYamashita/TAImiurin.cpp"),
            Object(Matching, "plugPikiYamashita/ptclGenPack.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawProgre.cpp"),
            Object(NonMatching, "plugPikiYamashita/spectrumCursorMgr.cpp"),
            Object(Equivalent, "plugPikiYamashita/drawWorldMap.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCountDown.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawGameOver.cpp"),
            Object(Matching, "plugPikiYamashita/yai.cpp"),
            Object(Matching, "plugPikiYamashita/effectMgr2D.cpp"),
            Object(Matching, "plugPikiYamashita/drawWMPause.cpp"),
            Object(Matching, "plugPikiYamashita/TAIusuba.cpp"),
            Object(NonMatching, "plugPikiYamashita/TAIotama.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMcourseSelect.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMtitle.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMscore.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMbest.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawCMresult.cpp"),
            Object(Matching, "plugPikiYamashita/drawMenuBase.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawHiScore.cpp"),
            Object(Matching, "plugPikiYamashita/damageEffect.cpp"),
            Object(Matching, "plugPikiYamashita/alphaWipe.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawUfoParts.cpp"),
            Object(Matching, "plugPikiYamashita/zenSys.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawSaveMes.cpp"),
            Object(Matching, "plugPikiYamashita/drawSaveFailure.cpp"),
            Object(NonMatching, "plugPikiYamashita/drawFinalResult.cpp"),
            Object(Matching, "plugPikiYamashita/drawOptionSave.cpp"),
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
            Object(Matching, "os/OS.c"),
            Object(Matching, "os/OSAlarm.c"),
            Object(Matching, "os/OSAlloc.c"),
            Object(Matching, "os/OSArena.c"),
            Object(Matching, "os/OSAudioSystem.c"),
            Object(Matching, "os/OSCache.c"),
            Object(Matching, "os/OSContext.c"),
            Object(Matching, "os/OSError.c"),
            Object(Matching, "os/OSExi.c"),
            Object(Matching, "os/OSFont.c"),
            Object(Matching, "os/OSInterrupt.c"),
            Object(Matching, "os/OSLink.c"),
            Object(Matching, "os/OSMessage.c"),
            Object(Matching, "os/OSMemory.c"),
            Object(Matching, "os/OSMutex.c"),
            Object(Matching, "os/OSReboot.c"),
            Object(Matching, "os/OSReset.c"),
            Object(Matching, "os/OSResetSW.c"),
            Object(Matching, "os/OSRtc.c"),
            Object(Matching, "os/OSSerial.c"),
            Object(Matching, "os/OSSync.c"),
            Object(Matching, "os/OSThread.c"),
            Object(Matching, "os/OSTime.c"),
            Object(Matching, "os/OSUartExi.c"),
            Object(Matching, "os/__start.c"),
            Object(Matching, "os/__ppc_eabi_init.cpp"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(Matching, "db/db.c"),
        ]
    ),
    {
        "lib": "mtx",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_mtx,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "mtx/mtx.c"),
            Object(Matching, "mtx/mtx44.c"),
            Object(Matching, "mtx/vec.c"),
        ]
    },
    DolphinLib(
        "dvd",
        [
            Object(Matching, "dvd/dvdlow.c"),
            Object(Matching, "dvd/dvdfs.c"),
            Object(Matching, "dvd/dvd.c"),
            Object(Matching, "dvd/dvdqueue.c"),
            Object(Matching, "dvd/dvderror.c"),
            Object(Matching, "dvd/fstload.c"),
        ]
    ),
    DolphinLib(
        "vi",
        [
            Object(Matching, "vi/vi.c"),
        ]
    ),
    DolphinLib(
        "pad",
        [
            Object(Matching, "pad/Padclamp.c"),
            Object(Matching, "pad/Pad.c"),
        ]
    ),
    DolphinLib(
        "ai",
        [
            Object(Matching, "ai/ai.c"),
        ]
    ),
    DolphinLib(
        "ar",
        [
            Object(Matching, "ar/ar.c"),
            Object(Matching, "ar/arq.c"),
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
            Object(Matching, "card/CARDBios.c"),
            Object(Matching, "card/CARDRdwr.c"),
            Object(Matching, "card/CARDBlock.c"),
            Object(Matching, "card/CARDDir.c"),
            Object(Matching, "card/CARDCheck.c"),
            Object(Matching, "card/CARDMount.c"),
            Object(Matching, "card/CARDFormat.c"),
            Object(Matching, "card/CARDOpen.c"),
            Object(Matching, "card/CARDCreate.c"),
            Object(Matching, "card/CARDRead.c"),
            Object(Matching, "card/CARDWrite.c"),
            Object(Matching, "card/CARDDelete.c"),
            Object(Matching, "card/CARDStat.c"),
            Object(Matching, "card/CARDRename.c"),
        ]
    ),
    DolphinLib(
        "hio",
        [
            Object(Matching, "hio/hio.c"),
        ]
    ),
    DolphinLib(
        "gx",
        [
            Object(Matching, "gx/GXInit.c"),
            Object(Matching, "gx/GXFifo.c"),
            Object(Equivalent, "gx/GXAttr.c"),
            Object(Matching, "gx/GXMisc.c"),
            Object(Matching, "gx/GXGeometry.c"),
            Object(Matching, "gx/GXFrameBuf.c"),
            Object(NonMatching, "gx/GXLight.c"),
            Object(Equivalent, "gx/GXTexture.c"),
            Object(Matching, "gx/GXBump.c"),
            Object(Matching, "gx/GXTev.c"),
            Object(Matching, "gx/GXPixel.c"),
            Object(Matching, "gx/GXStubs.c"),
            Object(Matching, "gx/GXDisplayList.c"),
            Object(NonMatching, "gx/GXTransform.c"),
        ]
    ),
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
        "cflags": [*cflags_runtime, "-inline deferred"],
        "objects": [
            Object(Matching, "Runtime/PPCEABI/H/__mem.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/__va_arg.c"),
            Object(Matching, "Runtime/PPCEABI/H/global_destructor_chain.c"),
            Object(Matching, "Runtime/PPCEABI/H/CPlusLibPPC.cp"),
            Object(NonMatching, "Runtime/PPCEABI/H/NMWException.cp"),
            Object(Matching, "Runtime/PPCEABI/H/ptmf.c"),
            Object(NonMatching, "Runtime/PPCEABI/H/ExceptionPPC.cp"),
            Object(NonMatching, "Runtime/PPCEABI/H/runtime.c"),
            Object(Matching, "Runtime/PPCEABI/H/__init_cpp_exceptions.cpp"),
        ],
    },
    {
        "lib": "MSL_C.PPCEABI.bare.H",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
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
            Object(Matching, "MSL_C/PPCEABI/bare/H/mem.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/mem_funcs.c"),
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
            Object(Matching, "MSL_C/PPCEABI/bare/H/w_atan2.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/w_pow.c"),
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
        "progress_category" : "sdk",
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
        "progress_category" : "sdk",
        "cflags": cflags_base,
        "objects": [
            Object(Matching, "amcExi2/AmcExi.c"),
            Object(Matching, "amcExi2/AmcExi2Comm.c"),
        ],
    },
    {
        "lib": "amcnotstub",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
        "cflags": cflags_base,
        "objects": [
            Object(Matching, "amcnotstub/amcnotstub.c"),
        ],
    },
    {
        "lib": "OdemuExi2",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
        "cflags": cflags_base,
        "objects": [
            Object(NonMatching, "OdemuExi2/DebuggerDriver.c"),
        ],
    },
    {
        "lib": "odenotstub",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
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
    ProgressCategory("jaudio", "JAudio Code"),
    ProgressCategory("hvqm4dec", "HVQM4 Decoder Code"),
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
