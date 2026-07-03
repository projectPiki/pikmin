#include "PowerPC_EABI_Support/Runtime/Gecko_ExceptionPPC.h"
#include "PowerPC_EABI_Support/Runtime/MWCPlusLib.h"
#include "PowerPC_EABI_Support/Runtime/NMWException.h"

typedef struct ThrowContext ThrowContext;
typedef struct MWExceptionInfo MWExceptionInfo;
typedef struct ex_specification ex_specification;
typedef struct ex_deletepointercond ex_deletepointercond;

#define RETURN_ADDRESS 4

union MWE_GeckoVector64 {
	f64 d;
	f32 f[2];
};

typedef union MWE_GeckoVector64 MWE_GeckoVector64;

struct GeckoFPRContext {
	f64 d;
	MWE_GeckoVector64 v;
};

typedef struct GeckoFPRContext GeckoFPRContext;

typedef struct ThrowContext {
	GeckoFPRContext FPR[32];
	s32 GPR[32];
	s32 CR;
	char* SP;
	char* FP;
	char* throwSP;
	char* returnaddr;
	char* throwtype;
	void* location;
	void* dtor;
	CatchInfo* catchinfo;
} ThrowContext;

typedef ThrowContext* ThrowContextPtr;

typedef struct MWExceptionInfo {
	ExceptionTableSmall* exception_record;
	char* current_function;
	char* action_pointer;
	char* code_section;
	char* data_section;
	char* TOC;
} MWExceptionInfo;

typedef struct FragmentInfo {
	ExceptionTableIndex* exception_start;
	ExceptionTableIndex* exception_end;
	char* code_start;
	char* code_end;
	char* data_start;
	char* data_end;
	char* TOC;
	int active;
} FragmentInfo;

typedef struct ProcessInfo {
	__eti_init_info* exception_info;
	char* TOC;
	int active;
} ProcessInfo;

typedef struct ActionIterator {
	MWExceptionInfo info;
	char* current_SP;
	char* current_FP;
	s32 current_R31;
} ActionIterator;

#define MAXFRAGMENTS 1
static ProcessInfo fragmentinfo[MAXFRAGMENTS];

typedef void (*DeleteFunc)(void*);

#pragma peephole off

/**
 * @todo Documentation
 * @note UNUSED Size: 00000C
 */
// void std::bad_exception::what() const
// {
// 	// This function is defined inline in the `std::bad_exception` class.
// }

/**
 * @todo Documentation
 */
int __register_fragment(struct __eti_init_info* info, char* TOC)
{
	ProcessInfo* f = fragmentinfo;
	int i;

	for (i = 0; i < MAXFRAGMENTS; i++, f++) {
		if (f->active == 0) {
			f->exception_info = info;
			f->TOC            = TOC;
			f->active         = 1;
			return i;
		}
	}

	return -1;
}

/**
 * @todo Documentation
 */
void __unregister_fragment(int fragmentID)
{
	ProcessInfo* f;

	if (fragmentID >= 0 && fragmentID < MAXFRAGMENTS) {
		f                 = &fragmentinfo[fragmentID];
		f->exception_info = 0;
		f->TOC            = 0;
		f->active         = 0;
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000098
 */
void ExPPC_FindExceptionFragment(char*, FragmentInfo*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0001D4
 */
void ExPPC_FindExceptionRecord(char*, MWExceptionInfo*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00002C
 */
void ExPPC_PopR31(char*, MWExceptionInfo*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000020
 */
void ExPPC_CurrentAction(const ActionIterator*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00021C
 */
void ExPPC_NextAction(ActionIterator*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0001F0
 */
void ExPPC_PopStackFrame(ThrowContext*, MWExceptionInfo*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00003C
 */
void ExPPC_DestroyLocal(ThrowContext*, const ex_destroylocal*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00007C
 */
void ExPPC_DestroyLocalCond(ThrowContext*, const ex_destroylocalcond*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000060
 */
void ExPPC_DestroyLocalPointer(ThrowContext*, const ex_destroylocalpointer*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000090
 */
void ExPPC_DestroyLocalArray(ThrowContext*, const ex_destroylocalarray*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000068
 */
void ExPPC_DestroyMember(ThrowContext*, const ex_destroymember*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000068
 */
void ExPPC_DestroyBase(ThrowContext*, const ex_destroymember*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000A4
 */
void ExPPC_DestroyMemberCond(ThrowContext*, const ex_destroymembercond*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000BC
 */
void ExPPC_DestroyMemberArray(ThrowContext*, const ex_destroymemberarray*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00005C
 */
void ExPPC_DeletePointer(ThrowContext*, const ex_deletepointer*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000098
 */
void ExPPC_DeletePointerCond(ThrowContext*, const ex_deletepointercond*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000574
 */
void ExPPC_UnwindStack(ThrowContext*, MWExceptionInfo*, void*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000098
 */
void ExPPC_IsInSpecification(char*, ex_specification*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000084
 */
// std::bad_exception::~bad_exception()
// {
// 	// This function is defined inline in the `std::bad_exception` class.
// }

/**
 * @todo Documentation
 * @note UNUSED Size: 0001C8
 */
void __unexpected(CatchInfo* catchinfo)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000090
 */
void ExPPC_HandleUnexpected(ThrowContext*, MWExceptionInfo*, ex_specification*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000450
 */
void ExPPC_ThrowHandler(ThrowContext*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000044
 */
void __end__catch(CatchInfo* catchinfo)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000B4
 */
void __throw(char* throwtype, void* location, void* dtor)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000074
 */
void ExPPC_LongJump(ThrowContext*, void*, void*)
{
	TRAP_UNIMPLEMENTED;
}
