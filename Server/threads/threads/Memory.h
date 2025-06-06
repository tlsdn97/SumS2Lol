#pragma once
#include "GMacro.h"

class MemoryPool;

class Memory
{
	enum
	{
		POOL_COUNT = (1024/ 32) + (1024 / 128) + (2048/ 256),
		MAX_ALLOC_SIZE = 4096
	};

public:
	Memory();
	~Memory();

	void* Allcate(int32 size);
	void Release(void* ptr);

private:
	vector<MemoryPool> _pools;

	MemoryPool* _pooltable[MAX_ALLOC_SIZE - 1];
};

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


