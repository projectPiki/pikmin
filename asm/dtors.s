.include "macros.inc"
.section ._dtors, "wa"  # 0x80221FC0 - 0x80221FE0
.global __destroy_global_chain_reference
__destroy_global_chain_reference:
	.4byte 0x80214964
.global __fini_cpp_exceptions_reference
__fini_cpp_exceptions_reference:
	.4byte 0x802154C8
.global __destroy_global_chain_reference_1
__destroy_global_chain_reference_1:
	.4byte 0x80214964
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	
