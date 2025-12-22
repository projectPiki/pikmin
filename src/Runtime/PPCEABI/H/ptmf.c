#include "types.h"

// presumably, ptmf = pointer to member function

typedef struct PTMF {
	s32 this_delta; // self-explanatory
	s32 v_offset;   // vtable offset
	union {
		void* f_addr;  // function address
		s32 ve_offset; // virtual function entry offset (of vtable)
	} f_data;
} PTMF;

const PTMF __ptmf_null = { 0, 0, 0 };

void __ptmf_scall(...);

/*
 * --INFO--
 * Address: ........
 * Size:    000030
 */
void __ptmf_test(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    00003C
 */
void __ptmf_cmpr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000034
 */
void __ptmf_call(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000034
 */
void __ptmf_call4(void)
{
	// UNUSED FUNCTION
}

ASM void __ptmf_scall(...)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	lwz     r0, PTMF.this_delta(r12)
	lwz     r11, PTMF.v_offset(r12)
	lwz     r12, PTMF.f_data(r12)
	add     r3, r3, r0
	cmpwi   r11, 0
	blt-    cr0, loc_0x20
	lwzx    r12, r3, r12
	lwzx    r12, r12, r11

loc_0x20:
	mtctr   r12
	bctr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000028
 */
void __ptmf_scall4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000024
 */
void __ptmf_cast(void)
{
	// UNUSED FUNCTION
}
