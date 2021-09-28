.include "macros.inc"
.section ._dtors, "wa"  # 0x80221FC0 - 0x80221FE0
.global __destroy_global_chain_reference
__destroy_global_chain_reference:
	.incbin "baserom.dol", 0x21EFC0, 0x4
.global __fini_cpp_exceptions_reference
__fini_cpp_exceptions_reference:
	.incbin "baserom.dol", 0x21EFC4, 0x4
.global __destroy_global_chain_reference_1
__destroy_global_chain_reference_1:
	.incbin "baserom.dol", 0x21EFC8, 0x18
	