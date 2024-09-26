#include "PowerPC_EABI_Support/Runtime/NMWException.h"
#include "PowerPC_EABI_Support/Runtime/MWCPlusLib.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void __destroy_new_array2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802149F4
 * Size:	00007C
 */
void __destroy_new_array(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r26, 0x10(r1)
  mr.       r26, r3
  addi      r27, r4, 0
  beq-      .loc_0x68
  cmplwi    r27, 0
  beq-      .loc_0x60
  lwz       r30, -0x8(r26)
  li        r29, 0
  lwz       r31, -0x4(r26)
  mullw     r0, r30, r31
  add       r28, r26, r0
  b         .loc_0x58

.loc_0x3C:
  addi      r12, r27, 0
  sub       r28, r28, r30
  mtlr      r12
  addi      r3, r28, 0
  li        r4, -0x1
  blrl
  addi      r29, r29, 0x1

.loc_0x58:
  cmplw     r29, r31
  blt+      .loc_0x3C

.loc_0x60:
  subi      r3, r26, 0x8
  bl        -0x1CD8A8

.loc_0x68:
  lmw       r26, 0x10(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void __destroy_arr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80214A70
 * Size:	000100
 */
void __construct_array(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  stw       r30, 0x38(r1)
  addi      r30, r7, 0
  stw       r29, 0x34(r1)
  addi      r29, r6, 0
  stw       r28, 0x30(r1)
  addi      r28, r4, 0
  stw       r3, 0x1C(r1)
  stw       r29, 0x20(r1)
  stw       r30, 0x24(r1)
  stw       r5, 0x28(r1)
  lwz       r3, 0x24(r1)
  stw       r3, 0x2C(r1)
  stw       r0, 0x2C(r1)
  b         .loc_0x74

.loc_0x50:
  addi      r12, r28, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0x1
  blrl
  lwz       r3, 0x2C(r1)
  add       r31, r31, r29
  addi      r0, r3, 0x1
  stw       r0, 0x2C(r1)

.loc_0x74:
  lwz       r4, 0x2C(r1)
  cmplw     r4, r30
  blt+      .loc_0x50
  lwz       r0, 0x24(r1)
  cmplw     r4, r0
  bge-      .loc_0xE0
  lwz       r0, 0x28(r1)
  cmplwi    r0, 0
  beq-      .loc_0xE0
  lwz       r0, 0x20(r1)
  lwz       r3, 0x1C(r1)
  mullw     r0, r0, r4
  add       r31, r3, r0
  b         .loc_0xD4

.loc_0xAC:
  lwz       r0, 0x20(r1)
  li        r4, -0x1
  lwz       r12, 0x28(r1)
  sub       r31, r31, r0
  mtlr      r12
  addi      r3, r31, 0
  blrl
  lwz       r3, 0x2C(r1)
  subi      r0, r3, 0x1
  stw       r0, 0x2C(r1)

.loc_0xD4:
  lwz       r0, 0x2C(r1)
  cmplwi    r0, 0
  bne+      .loc_0xAC

.loc_0xE0:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  mtlr      r0
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  blr
*/
}

class __partial_array_destructor {
private:
	void* p;
	size_t size;
	size_t n;
	ConstructorDestructor dtor;

public:
	size_t i;

	__partial_array_destructor(void* array, size_t elementsize, size_t nelements, ConstructorDestructor destructor)
	{
		p    = array;
		size = elementsize;
		n    = nelements;
		dtor = destructor;
		i    = n;
	}

	~__partial_array_destructor()
	{
		char* ptr;

		if (i < n && dtor) {
			for (ptr = (char*)p + size * i; i > 0; i--) {
				ptr -= size;
				DTORCALL_COMPLETE(dtor, ptr);
			}
		}
	}
};

/*
 * --INFO--
 * Address:	80214C28
 * Size:	000108
 */
void __construct_new_array(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r27, 0x34(r1)
  mr.       r30, r3
  addi      r27, r4, 0
  addi      r28, r6, 0
  addi      r29, r7, 0
  beq-      .loc_0xF0
  stw       r28, 0x0(r30)
  cmplwi    r27, 0
  stw       r29, 0x4(r30)
  addi      r30, r30, 0x8
  beq-      .loc_0xF0
  stw       r30, 0x1C(r1)
  li        r0, 0
  addi      r31, r30, 0
  stw       r28, 0x20(r1)
  stw       r29, 0x24(r1)
  stw       r5, 0x28(r1)
  lwz       r3, 0x24(r1)
  stw       r3, 0x2C(r1)
  stw       r0, 0x2C(r1)
  b         .loc_0x84

.loc_0x60:
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0x1
  blrl
  lwz       r3, 0x2C(r1)
  add       r31, r31, r28
  addi      r0, r3, 0x1
  stw       r0, 0x2C(r1)

.loc_0x84:
  lwz       r4, 0x2C(r1)
  cmplw     r4, r29
  blt+      .loc_0x60
  lwz       r0, 0x24(r1)
  cmplw     r4, r0
  bge-      .loc_0xF0
  lwz       r0, 0x28(r1)
  cmplwi    r0, 0
  beq-      .loc_0xF0
  lwz       r0, 0x20(r1)
  lwz       r3, 0x1C(r1)
  mullw     r0, r0, r4
  add       r31, r3, r0
  b         .loc_0xE4

.loc_0xBC:
  lwz       r0, 0x20(r1)
  li        r4, -0x1
  lwz       r12, 0x28(r1)
  sub       r31, r31, r0
  mtlr      r12
  addi      r3, r31, 0
  blrl
  lwz       r3, 0x2C(r1)
  subi      r0, r3, 0x1
  stw       r0, 0x2C(r1)

.loc_0xE4:
  lwz       r0, 0x2C(r1)
  cmplwi    r0, 0
  bne+      .loc_0xBC

.loc_0xF0:
  mr        r3, r30
  lmw       r27, 0x34(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void __throw_catch_compare(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void std::unexpected()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
unexpected_handler std::set_unexpected(void (*) ())
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void std::terminate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
terminate_handler std::set_terminate(void (*) ())
{
	// UNUSED FUNCTION
}

extern "C" {
extern void abort();
}

namespace std {
/**
 * @note Address: N/A
 * @note Size: 0x28
 */
static void duhandler() { terminate(); }

static unexpected_handler uhandler = duhandler;


/**
 * @note Address: N/A
 * @note Size: 0x20
 */
static void dthandler() { abort(); }

static terminate_handler thandler = dthandler;
} // namespace std
