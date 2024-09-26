#include "PowerPC_EABI_Support/Runtime/NMWException.h"
#include "PowerPC_EABI_Support/Runtime/MWCPlusLib.h"

typedef struct ThrowContext ThrowContext;
typedef struct MWExceptionInfo MWExceptionInfo;
typedef struct ex_specification ex_specification;
typedef struct ex_deletepointercond ex_deletepointercond;

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void ExPPC_LongJump(ThrowContext *, void *, void *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void __throw(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void __end__catch(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000450
 */
void ExPPC_ThrowHandler(ThrowContext *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void ExPPC_HandleUnexpected(ThrowContext *, MWExceptionInfo *, ex_specification *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C8
 */
void __unexpected(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
// std::bad_exception::~bad_exception()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void ExPPC_IsInSpecification(char *, ex_specification *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000574
 */
void ExPPC_UnwindStack(ThrowContext *, MWExceptionInfo *, void *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void ExPPC_DeletePointerCond(ThrowContext *, const ex_deletepointercond *)
{
	// UNUSED FUNCTION
}

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00005C
//  */
// void ExPPC_DeletePointer(ThrowContext *, const ex_deletepointer *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	0000BC
//  */
// void ExPPC_DestroyMemberArray(ThrowContext *, const ex_destroymemberarray *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	0000A4
//  */
// void ExPPC_DestroyMemberCond(ThrowContext *, const ex_destroymembercond *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000068
//  */
// void ExPPC_DestroyBase(ThrowContext *, const ex_destroymember *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000068
//  */
// void ExPPC_DestroyMember(ThrowContext *, const ex_destroymember *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000090
//  */
// void ExPPC_DestroyLocalArray(ThrowContext *, const ex_destroylocalarray *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000060
//  */
// void ExPPC_DestroyLocalPointer(ThrowContext *, const ex_destroylocalpointer *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00007C
//  */
// void ExPPC_DestroyLocalCond(ThrowContext *, const ex_destroylocalcond *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00003C
//  */
// void ExPPC_DestroyLocal(ThrowContext *, const ex_destroylocal *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	0001F0
//  */
// void ExPPC_PopStackFrame(ThrowContext *, MWExceptionInfo *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00021C
//  */
// void ExPPC_NextAction(ActionIterator *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000020
//  */
// void ExPPC_CurrentAction(const ActionIterator *)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void ExPPC_PopR31(char *, MWExceptionInfo *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001D4
 */
void ExPPC_FindExceptionRecord(char *, MWExceptionInfo *)
{
	// UNUSED FUNCTION
}

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000098
//  */
// void ExPPC_FindExceptionFragment(char *, FragmentInfo *)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	80214D58
 * Size:	000034
 */
void __unregister_fragment(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0
  blt-      .loc_0x30
  cmpwi     r3, 0x1
  bge-      .loc_0x30
  mulli     r4, r3, 0xC
  lis       r3, 0x803D
  addi      r0, r3, 0x40E0
  add       r3, r0, r4
  li        r0, 0
  stw       r0, 0x0(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x8(r3)

.loc_0x30:
  blr
*/
}

/*
 * --INFO--
 * Address:	80214D8C
 * Size:	00003C
 */
void __register_fragment(void)
{
/*
.loc_0x0:
  lis       r5, 0x803D
  addi      r5, r5, 0x40E0
  b         .loc_0xC

.loc_0xC:
  b         .loc_0x10

.loc_0x10:
  lwz       r0, 0x8(r5)
  cmpwi     r0, 0
  bne-      .loc_0x34
  stw       r3, 0x0(r5)
  li        r0, 0x1
  li        r3, 0
  stw       r4, 0x4(r5)
  stw       r0, 0x8(r5)
  b         .loc_0x38

.loc_0x34:
  li        r3, -0x1

.loc_0x38:
  blr
*/
}

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00000C
//  */
// void std::bad_exception::what() const
// {
// 	// UNUSED FUNCTION
// }
