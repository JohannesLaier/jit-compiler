#ifndef __CODE_H__
#define __CODE_H__

#include <sys/mman.h>
#include <string>
#include <vector>

class Code {
	private:
		std::vector<unsigned char> opcodes;	
	public:
		bool eval(std::string code);

		int execute();

		void push(unsigned char c);
		void push(unsigned char c1, unsigned char c2);
		void push(unsigned char c1, unsigned char c2, unsigned char c3);
		void push(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4);

		void pushShort(unsigned short);
		void pushInt(unsigned int);
		void pushPointer(void*);
};

#endif
