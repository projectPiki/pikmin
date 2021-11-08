.include "macros.inc"
.section .ctors, "wa"  # 0x80221F60 - 0x80221FC0
.global __init_cpp_exceptions_reference
__init_cpp_exceptions_reference:
	.4byte __init_cpp_exceptions
	.4byte __sinit_shapeBase_cpp
	.4byte __sinit_matMath_cpp
	.4byte __sinit_system_cpp
	.4byte __sinit_dgxGraphics_cpp
	.4byte __sinit_gameflow_cpp
	.4byte __sinit_game_cpp
	.4byte __sinit_gauges_cpp
	.4byte __sinit_mapMgr_cpp
	.4byte __sinit_collInfo_cpp
	.4byte __sinit_pikiInf_cpp
	.4byte __sinit_piki_cpp
	.4byte __sinit_gameStat_cpp
	.4byte __sinit_TAItank_cpp
	.4byte __sinit_TAImar_cpp
	.4byte __sinit_TAIhibaA_cpp
	.4byte __sinit_trigf_c
	.4byte 0x00000000
