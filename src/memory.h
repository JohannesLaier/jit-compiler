#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <cstring>

class Memory {
	public:
		static void* alloc(size_t size);
		static void* alloc(size_t size, int prot, int flags);
		static int protect(void* buf, size_t size, int prot);
		static void zero(void* buf, size_t size);
		static void copy(void* buf, void* buf2, size_t size);
		static void free(void* buf, size_t size);
};

#endif
