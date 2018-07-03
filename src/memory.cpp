#include "memory.h"

#include <sys/mman.h>
#include <sys/types.h>

void* Memory::alloc(size_t size) {
	return mmap(NULL, size, PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE | MAP_EXECUTABLE, -1, 0);
}

void* Memory::alloc(size_t size, int prot, int flags) {	
	return mmap(NULL, size, prot, flags, -1, 0);
}

int Memory::protect(void* buffer, size_t size, int prot) {
	return mprotect(buffer, size, prot);
}

void Memory::copy(void* buffer,  void* buffer2, size_t size) {
	memcpy(buffer, buffer2, size);
}

void Memory::zero(void* buffer, size_t size) {
	memset(buffer, 0x00, size);
}

void Memory::free(void* buffer, size_t size) {
	munmap(buffer, size);
}
