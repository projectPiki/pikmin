.include "macros.inc"
.section ._extab, "wa"  # 0x800054C0 - 0x80005500
.global extab
extab:
	.incbin "baserom.dol", 0x21EEC0, 0x40
	