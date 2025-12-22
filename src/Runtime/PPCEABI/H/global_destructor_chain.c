#include "PowerPC_EABI_Support/Runtime/global_destructor_chain.h"

DestructorChain* __global_destructor_chain;

/**
 * @TODO: Documentation
 */
void* __register_global_object(void* object, void* destructor, void* regmem)
{
	((DestructorChain*)regmem)->next       = __global_destructor_chain;
	((DestructorChain*)regmem)->destructor = destructor;
	((DestructorChain*)regmem)->object     = object;
	__global_destructor_chain              = (DestructorChain*)regmem;

	return object;
}

/**
 * @TODO: Documentation
 */
void __destroy_global_chain(void)
{
	DestructorChain* iter;

	while ((iter = __global_destructor_chain) != 0) {
		__global_destructor_chain = iter->next;
		DTORCALL_COMPLETE(iter->destructor, iter->object);
	}
}

DECL_SECT(".dtors") static void* const __destroy_global_chain_reference = __destroy_global_chain;
