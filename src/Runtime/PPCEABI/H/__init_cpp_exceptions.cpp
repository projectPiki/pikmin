#include "PowerPC_EABI_Support/Runtime/NMWException.h"
#include "PowerPC_EABI_Support/Runtime/__ppc_eabi_linker.h"

static int fragmentID = -2;

/*
 * --INFO--
 * Address:	802154C0
 * Size:	000008
 */
ASM static char* GetR2()
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mr r3, r2
	blr
#endif // clang-format on
}
extern "C" {
/*
 * --INFO--
 * Address:	802154FC
 * Size:	000040
 */
void __init_cpp_exceptions(void)
{
	if ((s32)fragmentID == -2) {
		char* R2   = GetR2();
		fragmentID = __register_fragment(_eti_init_info, R2);
	}
}

/*
 * --INFO--
 * Address:	802154C8
 * Size:	000034
 */
void __fini_cpp_exceptions(void)
{
	if ((s32)fragmentID != -2) {
		__unregister_fragment(fragmentID);
		fragmentID = -2;
	}
}
}

DECL_SECT(".ctors") extern void* const __init_cpp_exceptions_reference  = __init_cpp_exceptions;
DECL_SECT(".dtors") extern void* const __destroy_global_chain_reference = __destroy_global_chain;
DECL_SECT(".dtors") extern void* const __fini_cpp_exceptions_reference  = __fini_cpp_exceptions;
