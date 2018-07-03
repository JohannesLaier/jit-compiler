#include <iostream>

#include "js/jsparser.h"

#include "code.h"
#include "opcodes.h"
#include "js/jsvarnumber.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Just in Time Compiler <JohannesLaier@gmail.com> V0.1" << std::endl;
		std::cout << "Usage: " << argv[0] << " [sourcefile]" << std::endl;
		return -1;
	}

	JSParser jsparser(argv[1]);

	return 0;
}
