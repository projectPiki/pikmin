.include "macros.inc"
.section ._exidx, "wa"  # 0x80005500 - 0x80005560
	.incbin "baserom.dol", 0x21EF00, 0x30
.global lbl_80005530
lbl_80005530:
	.incbin "baserom.dol", 0x21EF30, 0x30
