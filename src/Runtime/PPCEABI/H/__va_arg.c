#include "PowerPC_EABI_Support/Runtime/__va_arg.h"

/*
 * --INFO--
 * Address:	80214870
 * Size:	0000F4
 */
void* __va_arg(struct va_list* v_list, u8 type)
{
	char* addr;
	char* reg      = &(v_list->mG_register);
	s32 g_reg      = v_list->mG_register;
	s32 maxsize    = 8;
	s32 size       = 4;
	s32 increment  = 1;
	s32 even       = 0;
	s32 fpr_offset = 0;
	s32 regsize    = 4;

	if (type == 4) {
		addr                    = (char*)(((int)v_list->mInput_arg_area + 0xf) & 0xfffffff0);
		v_list->mInput_arg_area = addr + 0x10;
		return addr;
	}
	if (type == 3) {
		reg        = &(v_list->mFloat_register);
		g_reg      = v_list->mFloat_register;
		size       = 8;
		fpr_offset = 32;
		regsize    = 8;
	}
	if (type == 2) {
		size = 8;
		maxsize--;
		if (g_reg & 1)
			even = 1;
		increment = 2;
	}
	if (g_reg < maxsize) {
		g_reg += even;
		addr = v_list->mReg_save_area + fpr_offset + (g_reg * regsize);
		*reg = g_reg + increment;
	} else {
		*reg                    = 8;
		addr                    = v_list->mInput_arg_area;
		addr                    = (char*)(((u32)(addr) + ((size)-1)) & ~((size)-1));
		v_list->mInput_arg_area = addr + size;
	}
	if (type == 0)
		addr = *((char**)addr);

	return addr;
}
