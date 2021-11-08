.include "macros.inc"
.section ._dtors, "wa"  # 0x80221FC0 - 0x80221FE0
.global __destroy_global_chain_reference
__destroy_global_chain_reference:
	.4byte __destroy_global_chain
.global __fini_cpp_exceptions_reference
__fini_cpp_exceptions_reference:
	.4byte __fini_cpp_exceptions
.global __destroy_global_chain_reference_1
__destroy_global_chain_reference_1:
	.4byte __destroy_global_chain
	.4byte 0x00000000
