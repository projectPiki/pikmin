.include "macros.inc"
.section .ctors, "wa"  # 0x80221F60 - 0x80221FC0
.global __init_cpp_exceptions_reference
__init_cpp_exceptions_reference:
	.incbin "baserom.dol", 0x21EF60, 0x60
