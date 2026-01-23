#include "PowerPC_EABI_Support/Runtime/MWCPlusLib.h"
#include "PowerPC_EABI_Support/Runtime/NMWException.h"

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

/*
 * --INFO--
 * Address:	80214C28
 * Size:	000108
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

/*
 * --INFO--
 * Address:	80214A70
 * Size:	000100
 */
extern void __construct_array(void* ptr, ConstructorDestructor ctor, ConstructorDestructor dtor, size_t size, size_t n)
{
	__partial_array_destructor pad(ptr, size, n, dtor);
	char* p;

	for (pad.i = 0, p = (char*)ptr; pad.i < n; pad.i++, p += size) {
		CTORCALL_COMPLETE(ctor, p);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
extern void __destroy_arr(void* block, ConstructorDestructor* dtor, size_t size, size_t n)
{
	char* p;

	for (p = (char*)block + size * n; n > 0; n--) {
		p -= size;
		DTORCALL_COMPLETE(dtor, p);
	}
}

/*
 * --INFO--
 * Address:	802149F4
 * Size:	00007C
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

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void __destroy_new_array2(void)
{
	// UNUSED FUNCTION
}

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00022C
//  */
// void __throw_catch_compare(void)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000028
//  */
// void std::unexpected()
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000010
//  */
// unexpected_handler std::set_unexpected(void (*)())
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000028
//  */
// void std::terminate()
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000010
//  */
// terminate_handler std::set_terminate(void (*)())
// {
// 	// UNUSED FUNCTION
// }

// extern "C" {
// extern void abort();
// }

// namespace std {
// /**
//  * @note Address: N/A
//  * @note Size: 0x28
//  */
// static void duhandler()
// {
// 	terminate();
// }

// static unexpected_handler uhandler = duhandler;

// /**
//  * @note Address: N/A
//  * @note Size: 0x20
//  */
// static void dthandler()
// {
// 	abort();
// }

// static terminate_handler thandler = dthandler;
// } // namespace std
