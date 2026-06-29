#include "PowerPC_EABI_Support/Runtime/MWCPlusLib.h"
#include "PowerPC_EABI_Support/Runtime/NMWException.h"
#include <stdlib.h>

#pragma exceptions on

#define ARRAY_HEADER_SIZE 8 // This is 16 in Pikmin 2

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

namespace std {

/**
 * @todo Documentation
 * @note UNUSED Size: 0x20
 */
static void dthandler()
{
	abort();
}

static terminate_handler thandler = dthandler;

/**
 * @todo Documentation
 * @note UNUSED Size: 0x28
 */
static void duhandler()
{
	terminate();
}

static unexpected_handler uhandler = duhandler;

/**
 * @todo Documentation
 * @note UNUSED Size: 000010 (Matching by size)
 */
terminate_handler set_terminate(terminate_handler newHandler)
{
	terminate_handler oldHandler = thandler;

	thandler = newHandler;
	return oldHandler;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000028
 */
void terminate()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000010 (Matching by size)
 */
unexpected_handler set_unexpected(unexpected_handler newHandler)
{
	unexpected_handler oldHandler = uhandler;

	uhandler = newHandler;
	return oldHandler;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000028
 */
void unexpected()
{
	TRAP_UNIMPLEMENTED;
}

} // namespace std

/**
 * @todo Documentation
 * @note UNUSED Size: 00022C
 */
char __throw_catch_compare(const char* throwtype, const char* catchtype, s32* offset_result)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 */
extern void* __construct_new_array(void* block, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size, size_t n)
{
	char* ptr;

	if ((ptr = (char*)block) != 0L) {
		size_t* p = (size_t*)ptr;

		p[0] = size;
		p[1] = n;
		ptr += ARRAY_HEADER_SIZE;

		if (ctor) {
			__partial_array_destructor pad(ptr, size, n, dtor);
			char* p;

			for (pad.i = 0, p = (char*)ptr; pad.i < n; pad.i++, p += size) {
				CTORCALL_COMPLETE(ctor, p);
			}
		}
	}
	return ptr;
}

/**
 * @todo Documentation
 */
extern void __construct_array(void* ptr, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size, size_t n)
{
	__partial_array_destructor pad(ptr, size, n, dtor);
	char* p;

	for (pad.i = 0, p = (char*)ptr; pad.i < n; pad.i++, p += size) {
		CTORCALL_COMPLETE(ctor, p);
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000078
 */
extern void __destroy_arr(void* block, ConstructorDestructor* dtor, size_t size, size_t n)
{
	char* p;

	for (p = (char*)block + size * n; n > 0; n--) {
		p -= size;
		DTORCALL_COMPLETE(dtor, p);
	}
}

/**
 * @todo Documentation
 */
extern void __destroy_new_array(void* block, ConstructorDestructor dtor)
{
	if (block) {
		if (dtor) {
			size_t i, objects, objectsize;
			char* p;

			objectsize = *(size_t*)((char*)block - ARRAY_HEADER_SIZE);
			objects    = ((size_t*)((char*)block - ARRAY_HEADER_SIZE))[1];
			p          = (char*)block + (objectsize * objects);

			for (i = 0; i < objects; i++) {
				p -= objectsize;
				DTORCALL_COMPLETE(dtor, p);
			}
		}

		::operator delete[]((char*)block - ARRAY_HEADER_SIZE);
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000080
 */
void __destroy_new_array2(void)
{
	TRAP_UNIMPLEMENTED;
}
