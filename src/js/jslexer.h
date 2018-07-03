#ifndef __JSLEXER_H__
#define __JSLEXER_H__

#include "../parser.h"
#include "jslexem.h"

#include <cstdlib>

#include <iostream>
#include <string>

class JSLexer : private Parser {
	public:
		JSLexer(const std::string& file);
		JSLexem getLexem();
};

#endif
