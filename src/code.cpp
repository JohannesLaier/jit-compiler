#include "code.h"
#include "memory.h"

#include <stdio.h>
#include <iostream>

bool Code::eval(std::string code) {
	return true;
}

void Code::push(unsigned char c) {
	opcodes.push_back(c);
}

void Code::push(unsigned char c1, unsigned char c2) {
	push(c1);
	push(c2);
}

void Code::push(unsigned char c1, unsigned char c2, unsigned char c3) {
	push(c1);
	push(c2);
	push(c3);
}

void Code::push(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4) {
	push(c1);
	push(c2);
	push(c3);
	push(c4);
}

void Code::pushShort(unsigned short value) {
	push((unsigned char) (value));
	push((unsigned char) (value >> 8));
}

void Code::pushInt(unsigned int value) {
	push((unsigned char) (value));
	push((unsigned char) (value >> 8));
	push((unsigned char) (value >> 16));
	push((unsigned char) (value) >> 24);
}

void Code::pushPointer(void* ptr) {
	long value = reinterpret_cast<long>(ptr);
	push((unsigned char) (value));
	push((unsigned char) (value >> 8));
	push((unsigned char) (value >> 16));
	push((unsigned char) (value >> 24));
	push((unsigned char) (value >> 32));
	push((unsigned char) (value >> 40));
	push((unsigned char) (value >> 48));
	push((unsigned char) (value >> 56));
}

int Code::execute() {
	void* segment = (void*) Memory::alloc(opcodes.size());
	Memory::zero(segment, opcodes.size());
	Memory::copy(segment, &opcodes[0], opcodes.size());

	int (*func)(void) = (int(*)(void))segment;
	int ret = func();
	Memory::free(segment, opcodes.size());
	opcodes.clear();
	return ret;
}
