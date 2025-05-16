#pragma once
#include "GMacro.h"

template <typename T, typename... Args>
T* xnew(Args... args)
{
	T* memory = static_cast<T*>(xalloc(sizeof(T))); 

	new(memory)T(std::forward<Args>(args)...);

	return memory;
}

template <typename T>
void xdelete(T* ptr)
{
	ptr-> ~T();
	xrelease(ptr);
}


