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
DEFAULT_VERSION = 5
VERSIONS = [
    "DPIJ01_PIKIDEMO",  # 店頭ゲームデモディスク Oct'2001 (Pikmin Jitsuen-you Sample Disc) "zz_pikmin_game/PikiDemo.tgc"
    "GPIJ01_01"      ,  # JPN Rev 1
    "GPIJ01_02"      ,  # JPN Rev 2
    "G98E01_PIKIDEMO",  # USA Interactive Multi-Game Demo Disc - January 2002 "zz_PikminDemo-1210.tgc"
    "GPIE01_00"      ,  # USA Rev 0
    "GPIE01_01"      ,  # USA Rev 1
    "G98P01_PIKIDEMO",  # PAL Interactive Multi-Game Demo Disc - May 2002 "zz_PikiDemo.tgc"
    "GPIP01_00"      ,  # PAL Rev 0
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

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20250520"
config.dtk_tag = "v1.6.2"
config.objdiff_tag = "v3.0.0-beta.8"
config.sjiswrap_tag = "v1.2.1"
config.wibo_tag = "0.6.16"

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
    "-fp_contract off",
    "-str reuse",
    "-multibyte",
    "-i include",
    "-i include/stl",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
    # "-DBUGFIX",
    # "-DDEVELOP",
]

# Debug flags
if args.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.extend(["-DNDEBUG=1", "-w off"]) # no I DO not want to talk about my car's extended warranty.

# JAudio flags
cflags_jaudio = [
    "-nodefaults",
    "-proc gekko",
    '-pragma "scheduling 7400"',
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
    "-RTTI on",
    "-char unsigned",
]

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,readonly",
    "-common off",
    "-inline auto",
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
            Object(Matching, "jaudio/aictrl.c"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/dspboot.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/dspproc.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/ipldec.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/dsp_cardunlock.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/driverinterface.c"),
            Object(Matching, "jaudio/dspdriver.c"),
            Object(Matching, "jaudio/dspinterface.c"),
            Object(Matching, "jaudio/fxinterface.c"),
            Object(Matching, "jaudio/bankread.c"),
            Object(Matching, "jaudio/waveread.c"),
            Object(Matching, "jaudio/connect.c"),
            Object(Matching, "jaudio/tables.c"),
            Object(Matching, "jaudio/bankdrv.c"),
            Object(Matching, "jaudio/random.c"),
            Object(Matching, "jaudio/aramcall.c"),
            Object(Matching, "jaudio/ja_calc.c"),
            Object(Matching, "jaudio/fat.c"),
            Object(Matching, "jaudio/cmdstack.c"),
            Object(Matching, "jaudio/virload.c"),
            Object(Matching, "jaudio/heapctrl.c"),
            Object(Matching, "jaudio/jammain_2.c"),
            Object(Matching, "jaudio/midplay.c"),
            Object(Matching, "jaudio/noteon.c"),
            Object(Matching, "jaudio/seqsetup.c"),
            Object(Matching, "jaudio/centcalc.c"),
            Object(Matching, "jaudio/jamosc.c"),
            Object(Matching, "jaudio/oneshot.c"),
            Object(Matching, "jaudio/interface.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/verysimple.c"),
            Object(Matching, "jaudio/app_inter.c"),
            Object(Matching, "jaudio/pikiinter.c"),
            Object(Matching, "jaudio/piki_player.c"),
            Object(Matching, "jaudio/piki_bgm.c"),
            Object(Matching, "jaudio/piki_scene.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "jaudio/pikidemo.c"),
            Object(Matching, "jaudio/file_seq.c"),
            Object(Matching, "jaudio/cmdqueue.c"),
            Object(Matching, "jaudio/filter3d.c"),
            Object(Matching, "jaudio/syncstream.c"),
            Object(Matching, "jaudio/bankloader.c"),
            Object(Matching, "jaudio/interleave.c"),
            Object(Matching, "jaudio/pikiseq.c"),
            Object(Matching, "jaudio/hvqm_play.c"),
        ],
    },
    {
        "lib": "hvqm4dec",
        "cflags": cflags_base,
        "mw_version": "GC/1.2.5",
        "progress_category" : "hvqm4dec",
        "objects": [
            Object(Matching, "hvqm4dec/hvqm4dec.c"),
        ],
    },
    {
        "lib": "sysCommon",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Matching, "sysCommon/ayuStack.cpp"),
            Object(Matching, "sysCommon/baseApp.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/stream.cpp"),
            Object(Matching, "sysCommon/streamBufferedInput.cpp"),
            Object(Matching, "sysCommon/string.cpp"),
            Object(Matching, "sysCommon/graphics.cpp"),
            Object(Matching, "sysCommon/grLight.cpp"),
            Object(Equivalent, "sysCommon/shapeBase.cpp"),
            Object(Matching, "sysCommon/shpLightFlares.cpp"),
            Object(Matching, "sysCommon/shpObjColl.cpp"),
            Object(Matching, "sysCommon/shpRoutes.cpp"),
            Object(Matching, "sysCommon/sysMath.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/matMath.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/stdSystem.cpp"),
            Object(Matching, "sysCommon/node.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/timers.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/controller.cpp"),
            Object(Matching, "sysCommon/cmdStream.cpp"),
            Object(Matching, "sysCommon/camera.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysCommon/atx.cpp"),
            Object(Matching, "sysCommon/id32.cpp"),
        ],
    },
    {
        "lib": "sysDolphin",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Equivalent, "sysDolphin/texture.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysDolphin/system.cpp"),
            Object(Matching, "sysDolphin/sysNew.cpp"),
            Object(Matching, "sysDolphin/controllerMgr.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "sysDolphin/dgxGraphics.cpp"),
            Object(Matching, "sysDolphin/gameApp.cpp"),
        ],
    },
    {
        "lib": "plugPikiColin",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Equivalent, "plugPikiColin/cardutil.cpp"),
            Object(Matching, "plugPikiColin/dynsimulator.cpp"),
            Object(Matching, "plugPikiColin/animMgr.cpp"),
            Object(Equivalent, "plugPikiColin/gameflow.cpp"),
            Object(Equivalent, "plugPikiColin/game.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/gamePrefs.cpp"),
            Object(Equivalent, "plugPikiColin/gameSetup.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/cardSelect.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/mapSelect.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/newPikiGame.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/introGame.cpp"),
            Object(Matching, "plugPikiColin/gameExit.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/gauges.cpp"),
            Object(Matching, "plugPikiColin/genMapObject.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/gui.cpp"),
            Object(Matching, "plugPikiColin/parameters.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/plugPiki.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/titles.cpp"),
            Object(Matching, "plugPikiColin/ninLogo.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/mapMgr.cpp"),
            Object(Matching, "plugPikiColin/dayMgr.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/cinePlayer.cpp"),
            Object(Matching, "plugPikiColin/lightPool.cpp"),
            Object(Equivalent, "plugPikiColin/memoryCard.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiColin/moviePlayer.cpp"),
            Object(Equivalent, "plugPikiColin/movSample.cpp"),
        ],
    },
    {
        "lib": "plugPikiKando",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(Matching, "plugPikiKando/omake.cpp"),
            Object(Matching, "plugPikiKando/radarInfo.cpp"),
            Object(Matching, "plugPikiKando/interactBattle.cpp"),
            Object(Matching, "plugPikiKando/interactGrab.cpp"),
            Object(Matching, "plugPikiKando/interactEtc.cpp"),
            Object(Matching, "plugPikiKando/interactPullout.cpp"),
            Object(Matching, "plugPikiKando/saiEvents.cpp"),
            Object(Equivalent, "plugPikiKando/simpleAI.cpp"),
            Object(Matching, "plugPikiKando/formationMgr.cpp"),
            Object(Matching, "plugPikiKando/globalShapes.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/playerState.cpp"),
            Object(Matching, "plugPikiKando/gameDemo.cpp"),
            Object(Matching, "plugPikiKando/demoInvoker.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/demoEvent.cpp"),
            Object(Matching, "plugPikiKando/resultFlag.cpp"),
            Object(Matching, "plugPikiKando/aiConstants.cpp"),
            Object(Matching, "plugPikiKando/kio.cpp"),
            Object(Matching, "plugPikiKando/keyConfig.cpp"),
            Object(Matching, "plugPikiKando/aiPerf.cpp"),
            Object(Matching, "plugPikiKando/courseDebug.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/memStat.cpp"),
            Object(Matching, "plugPikiKando/collInfo.cpp"),
            Object(Matching, "plugPikiKando/complexCreature.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/creature.cpp"),
            Object(Matching, "plugPikiKando/creatureCollision.cpp"),
            Object(Matching, "plugPikiKando/creatureCollPart.cpp"),
            Object(Matching, "plugPikiKando/creatureMove.cpp"),
            Object(Matching, "plugPikiKando/creatureStick.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/dualCreature.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/dynCreature.cpp"),
            Object(Matching, "plugPikiKando/eventListener.cpp"),
            Object(Matching, "plugPikiKando/fastGrid.cpp"),
            Object(Matching, "plugPikiKando/ropeCreature.cpp"),
            Object(Matching, "plugPikiKando/objectTypes.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/pelletMgr.cpp"),
            Object(Matching, "plugPikiKando/animPellet.cpp"),
            Object(Matching, "plugPikiKando/genPellet.cpp"),
            Object(Matching, "plugPikiKando/pelletState.cpp"),
            Object(Matching, "plugPikiKando/workObject.cpp"),
            Object(Matching, "plugPikiKando/routeMgr.cpp"),
            Object(Matching, "plugPikiKando/seMgr.cpp"),
            Object(Matching, "plugPikiKando/seConstants.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/soundMgr.cpp"),
            Object(Matching, "plugPikiKando/updateMgr.cpp"),
            Object(Matching, "plugPikiKando/cPlate.cpp"),
            Object(Matching, "plugPikiKando/aiStone.cpp"),
            Object(Matching, "plugPikiKando/aiActions.cpp"),
            Object(Matching, "plugPikiKando/aiAttack.cpp"),
            Object(Matching, "plugPikiKando/aiBore.cpp"),
            Object(Matching, "plugPikiKando/aiBoMake.cpp"),
            Object(Matching, "plugPikiKando/aiBou.cpp"),
            Object(Equivalent, "plugPikiKando/aiBridge.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/aiBreakWall.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/aiTransport.cpp"),
            Object(Matching, "plugPikiKando/aiKinoko.cpp"),
            Object(Matching, "plugPikiKando/aiChase.cpp"),
            Object(Matching, "plugPikiKando/aiCrowd.cpp"),
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
            Object(Matching, "plugPikiKando/aiPullout.cpp"),
            Object(Matching, "plugPikiKando/aiPush.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/aiPut.cpp"),
            Object(Matching, "plugPikiKando/aiRandomBoid.cpp"),
            Object(Matching, "plugPikiKando/aiRescue.cpp"),
            Object(Matching, "plugPikiKando/aiRope.cpp"),
            Object(Matching, "plugPikiKando/aiShoot.cpp"),
            Object(Matching, "plugPikiKando/aiWatch.cpp"),
            Object(Matching, "plugPikiKando/aiWeed.cpp"),
            Object(Matching, "plugPikiKando/aiTable.cpp"),
            Object(Matching, "plugPikiKando/aiAction.cpp"),
            Object(Matching, "plugPikiKando/pikiInf.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/piki.cpp"),
            Object(Matching, "plugPikiKando/odoMeter.cpp"),
            Object(Matching, "plugPikiKando/pikidoKill.cpp"),
            Object(Matching, "plugPikiKando/pikiMgr.cpp"),
            Object(Matching, "plugPikiKando/pikiState.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/viewPiki.cpp"),
            Object(Matching, "plugPikiKando/conditions.cpp"),
            Object(Matching, "plugPikiKando/generator.cpp"),
            Object(Matching, "plugPikiKando/generatorCache.cpp"),
            Object(Matching, "plugPikiKando/objectMgr.cpp"),
            Object(Matching, "plugPikiKando/searchSystem.cpp"),
            Object(Matching, "plugPikiKando/smartPtr.cpp"),
            Object(Matching, "plugPikiKando/itemGem.cpp"),
            Object(Matching, "plugPikiKando/weedsItem.cpp"),
            Object(Matching, "plugPikiKando/kusaItem.cpp"),
            Object(Matching, "plugPikiKando/fishItem.cpp"),
            Object(Matching, "plugPikiKando/ufoItem.cpp"),
            Object(Matching, "plugPikiKando/ufoAnim.cpp"),
            Object(Matching, "plugPikiKando/bombItem.cpp"),
            Object(Matching, "plugPikiKando/goalItem.cpp"),
            Object(Matching, "plugPikiKando/pikiheadItem.cpp"),
            Object(Matching, "plugPikiKando/keyItem.cpp"),
            Object(Matching, "plugPikiKando/ropeItem.cpp"),
            Object(Matching, "plugPikiKando/seedItem.cpp"),
            Object(Matching, "plugPikiKando/genItem.cpp"),
            Object(Matching, "plugPikiKando/itemAI.cpp"),
            Object(Matching, "plugPikiKando/itemMgr.cpp"),
            Object(Matching, "plugPikiKando/itemObject.cpp"),
            Object(Matching, "plugPikiKando/mizuItem.cpp"),
            Object(Matching, "plugPikiKando/paniItemAnimator.cpp"),
            Object(Matching, "plugPikiKando/genNavi.cpp"),
            Object(Matching, "plugPikiKando/navi.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/naviState.cpp"),
            Object(Matching, "plugPikiKando/naviDemoState.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiKando/gameCoreSection.cpp"),
            Object(Matching, "plugPikiKando/gmWin.cpp"),
            Object(Matching, "plugPikiKando/gameStat.cpp"),
            Object(Matching, "plugPikiKando/kmath.cpp"),
            Object(Matching, "plugPikiKando/uteffect.cpp"),
            Object(Matching, "plugPikiKando/kontroller.cpp"),
            Object(Matching, "plugPikiKando/mapcode.cpp"),
            Object(Matching, "plugPikiKando/utkando.cpp"),
            Object(Matching, "plugPikiKando/naviMgr.cpp"),
            Object(Matching, "plugPikiKando/genMapParts.cpp"),
            Object(Matching, "plugPikiKando/mapParts.cpp"),
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
            Object(Matching, "plugPikiNakata/tai.cpp"),
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
            Object(Matching, "plugPikiNakata/taimizinko.cpp"),
            Object(Matching, "plugPikiNakata/taimotionactions.cpp"),
            Object(Matching, "plugPikiNakata/taimoveactions.cpp"),
            Object(Matching, "plugPikiNakata/tainapkid.cpp"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNakata/tekimgr.cpp"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/BossMgr.cpp"),
            Object(Matching, "plugPikiNishimura/BossShapeObj.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/Spider.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/SpiderAi.cpp"),
            Object(Equivalent, "plugPikiNishimura/SpiderLeg.cpp"),
            Object(Matching, "plugPikiNishimura/Snake.cpp"),
            Object(Matching, "plugPikiNishimura/SnakeAi.cpp"),
            Object(Equivalent, "plugPikiNishimura/SnakeBody.cpp"),
            Object(Matching, "plugPikiNishimura/Slime.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/SlimeAi.cpp"),
            Object(Matching, "plugPikiNishimura/SlimeBody.cpp"),
            Object(Matching, "plugPikiNishimura/SlimeCreature.cpp"),
            Object(Matching, "plugPikiNishimura/King.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/KingAi.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/KingBody.cpp"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiNishimura/MizuAi.cpp"),
            Object(Matching, "plugPikiNishimura/nscalculation.cpp"),
            Object(Matching, "plugPikiNishimura/RumbleData.cpp"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogTest.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogSub.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogTitle.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogPause.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogTutorial.cpp"),
            Object(Matching, "plugPikiOgawa/ogTutorialData.cpp"),
            Object(Matching, "plugPikiOgawa/ogMap.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogResult.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogRader.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogFileSelect.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogMessage.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogMemChk.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogDiary.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogMenu.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogFileChkSel.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogMakeDefault.cpp"),
            Object(Matching, "plugPikiOgawa/ogTotalScore.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogSave.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogNitaku.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogFileCopy.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogFileDelete.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiOgawa/ogGraph.cpp"),
            Object(Matching, "plugPikiOgawa/ogStart.cpp"),
            Object(Matching, "plugPikiOgawa/ogCallBack.cpp"),
        ],
    },
    {
        "lib": "plugPikiYamashita",
        "cflags": cflags_pikmin,
        "mw_version": "GC/1.2.5n",
        "progress_category" : "game",
        "objects": [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/gameCourseClear.cpp"),
            Object(Matching, "plugPikiYamashita/gameStageClear.cpp"),
            Object(Matching, "plugPikiYamashita/gameCredits.cpp"),
            Object(Matching, "plugPikiYamashita/zenMath.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/effectMgr.cpp"),
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
            Object(Matching, "plugPikiYamashita/TAItank.cpp"),
            Object(Matching, "plugPikiYamashita/TAImar.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAreaction.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAmove.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAmotion.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAjudge.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAattack.cpp"),
            Object(Matching, "plugPikiYamashita/P2DGrafContext.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/P2DOrthoGraph.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/P2DPerspGraph.cpp"),
            Object(Matching, "plugPikiYamashita/P2DPane.cpp"),
            Object(Equivalent, "plugPikiYamashita/P2DPicture.cpp"),
            Object(Matching, "plugPikiYamashita/P2DScreen.cpp"),
            Object(Matching, "plugPikiYamashita/P2DStream.cpp"),
            Object(Matching, "plugPikiYamashita/PSUList.cpp"),
            Object(Matching, "plugPikiYamashita/PUTRect.cpp"),
            Object(Matching, "plugPikiYamashita/P2DWindow.cpp"),
            Object(Matching, "plugPikiYamashita/P2DTextBox.cpp"),
            Object(Matching, "plugPikiYamashita/P2DPrint.cpp"),
            Object(Matching, "plugPikiYamashita/P2DFont.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/drawGameInfo.cpp"),
            Object(Matching, "plugPikiYamashita/zenGraphics.cpp"),
            Object(Matching, "plugPikiYamashita/drawContainer.cpp"),
            Object(Matching, "plugPikiYamashita/drawCommon.cpp"),
            Object(Matching, "plugPikiYamashita/zenController.cpp"),
            Object(Matching, "plugPikiYamashita/drawHurryUp.cpp"),
            Object(Matching, "plugPikiYamashita/texAnim.cpp"),
            Object(Matching, "plugPikiYamashita/drawAccount.cpp"),
            Object(Matching, "plugPikiYamashita/drawMenu.cpp"),
            Object(Matching, "plugPikiYamashita/TAIeffectAttack.cpp"),
            Object(Equivalent, "plugPikiYamashita/TAIbeatle.cpp"),
            Object(Matching, "plugPikiYamashita/menuPanelMgr.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiA.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiB.cpp"),
            Object(Matching, "plugPikiYamashita/TAIkabekuiC.cpp"),
            Object(Matching, "plugPikiYamashita/TAItamago.cpp"),
            Object(Matching, "plugPikiYamashita/TAIdororo.cpp"),
            Object(Matching, "plugPikiYamashita/TAIhibaA.cpp"),
            Object(Matching, "plugPikiYamashita/TAIAeffect.cpp"),
            Object(Matching, "plugPikiYamashita/TAImiurin.cpp"),
            Object(Matching, "plugPikiYamashita/ptclGenPack.cpp"),
            Object(Matching, "plugPikiYamashita/drawProgre.cpp"),
            Object(Matching, "plugPikiYamashita/spectrumCursorMgr.cpp"),
            Object(Equivalent, "plugPikiYamashita/drawWorldMap.cpp"),
            Object(Matching, "plugPikiYamashita/drawCountDown.cpp"),
            Object(Matching, "plugPikiYamashita/drawGameOver.cpp"),
            Object(Matching, "plugPikiYamashita/yai.cpp"),
            Object(Matching, "plugPikiYamashita/effectMgr2D.cpp"),
            Object(Matching, "plugPikiYamashita/drawWMPause.cpp"),
            Object(Matching, "plugPikiYamashita/TAIusuba.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/TAIotama.cpp"),
            Object(Matching, "plugPikiYamashita/drawCMcourseSelect.cpp"),
            Object(Matching, "plugPikiYamashita/drawCMtitle.cpp"),
            Object(Matching, "plugPikiYamashita/drawCMscore.cpp"),
            Object(Matching, "plugPikiYamashita/drawCMbest.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/drawCMresult.cpp"),
            Object(Matching, "plugPikiYamashita/drawMenuBase.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/drawHiScore.cpp"),
            Object(Matching, "plugPikiYamashita/damageEffect.cpp"),
            Object(Matching, "plugPikiYamashita/alphaWipe.cpp"),
            Object(Matching, "plugPikiYamashita/drawUfoParts.cpp"),
            Object(Matching, "plugPikiYamashita/zenSys.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/drawSaveMes.cpp"),
            Object(Matching, "plugPikiYamashita/drawSaveFailure.cpp"),
            Object(Matching, "plugPikiYamashita/drawFinalResult.cpp"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "plugPikiYamashita/drawOptionSave.cpp"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OS.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSAlarm.c"),
            Object(Matching, "os/OSAlloc.c"),
            Object(Matching, "os/OSArena.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSAudioSystem.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSCache.c"),
            Object(Matching, "os/OSContext.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSError.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSExi.c"),
            Object(Matching, "os/OSFont.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSInterrupt.c"),
            Object(Matching, "os/OSLink.c"),
            Object(Matching, "os/OSMessage.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSMemory.c"),
            Object(Matching, "os/OSMutex.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSReboot.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSReset.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSResetSW.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSRtc.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSSerial.c"),
            Object(Matching, "os/OSSync.c"),
            Object(Matching, "os/OSThread.c"),
            Object(Matching, "os/OSTime.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/OSUartExi.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "os/__start.c"),
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
        "mw_version": "GC/1.2.5",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "mtx/mtx.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "mtx/mtx44.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "mtx/vec.c"),
        ]
    },
    DolphinLib(
        "dvd",
        [
            Object(Matching, "dvd/dvdlow.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "dvd/dvdfs.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "dvd/dvd.c"),
            Object(Matching, "dvd/dvdqueue.c"),
            Object(Matching, "dvd/dvderror.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "dvd/fstload.c"),
        ]
    ),
    DolphinLib(
        "vi",
        [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "vi/vi.c"),
        ]
    ),
    DolphinLib(
        "pad",
        [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "pad/Padclamp.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "pad/Pad.c"),
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
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDBios.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDRdwr.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDBlock.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDDir.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDCheck.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDMount.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDFormat.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDOpen.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDCreate.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDRead.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDWrite.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDDelete.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDStat.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDRename.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "card/CARDNet.c"),
        ]
    ),
    DolphinLib(
        "hio",
        [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "hio/hio.c"),
        ]
    ),
    DolphinLib(
        "gx",
        [
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXInit.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXFifo.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXAttr.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXMisc.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXGeometry.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXFrameBuf.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXLight.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXTexture.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXBump.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXTev.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXPixel.c"),
            Object(Matching, "gx/GXStubs.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXDisplayList.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXTransform.c"),
            Object(not MatchingFor("G98E01_PIKIDEMO"), "gx/GXPerf.c"),
        ]
    ),
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
        "cflags": [*cflags_runtime, "-inline deferred"],
        "objects": [
            Object(Matching, "Runtime/PPCEABI/H/__mem.c"),
            Object(Matching, "Runtime/PPCEABI/H/__va_arg.c"),
            Object(Matching, "Runtime/PPCEABI/H/global_destructor_chain.c"),
            Object(Matching, "Runtime/PPCEABI/H/CPlusLibPPC.cp"),
            Object(Matching, "Runtime/PPCEABI/H/NMWException.cp"),
            Object(Matching, "Runtime/PPCEABI/H/ptmf.c"),
            Object(Matching, "Runtime/PPCEABI/H/ExceptionPPC.cp"),
            Object(Matching, "Runtime/PPCEABI/H/runtime.c"),
            Object(Matching, "Runtime/PPCEABI/H/__init_cpp_exceptions.cpp"),
        ],
    },
    {
        "lib": "MSL_C.PPCEABI.bare.H",
        "mw_version": "GC/1.2.5",
        "progress_category" : "sdk",
        "cflags": [*cflags_base, "-fp_contract on", "-inline auto,deferred", "-str pool,readonly"],
        "objects": [
            Object(Matching, "MSL_C/PPCEABI/bare/H/ansi_files.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/abort_exit.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/errno.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/ansi_fp.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/arith.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/buffer_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/critical_regions.ppc_eabi.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/ctype.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/locale.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/direct_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/mbstring.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/mem.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/mem_funcs.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/misc_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/printf.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/rand.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/scanf.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/string.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/strtold.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/strtoul.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/uart_console_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/wchar_io.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/float.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/e_asin.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/e_atan2.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/e_pow.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/fminmaxdim.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_atan.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_copysign.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_frexp.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/s_ldexp.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/w_atan2.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/w_pow.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/hyperbolicsf.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/inverse_trig.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/trigf.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/math_inlines.c"),
            Object(Matching, "MSL_C/PPCEABI/bare/H/common_float_tables.c"),
        ],
    },
    {
        "lib": "TRK_MINNOW_DOLPHIN",
        "mw_version": "GC/1.1p1",
        "progress_category" : "sdk",
        "cflags": [*cflags_runtime, "-rostr", "-sdata 0", "-sdata2 0", "-pool off", "-inline on,noauto"],
        "objects": [
            Object(Matching, "TRK_MINNOW_DOLPHIN/mainloop.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/nubevent.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/nubinit.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msg.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msgbuf.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/serpoll.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/usr_put.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dispatch.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/msghndlr.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/support.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mutex_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/notify.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/flush_cache.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mem_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/__exception.s"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/targimpl.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dolphin_trk.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/main_TRK.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
            Object(Matching, "TRK_MINNOW_DOLPHIN/targcont.c"),
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
            Object(Matching, "OdemuExi2/DebuggerDriver.c"),
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

# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects

# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback

# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
    ProgressCategory("jaudio", "JAudio Code"),
    ProgressCategory("hvqm4dec", "HVQM4 Decoder Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
