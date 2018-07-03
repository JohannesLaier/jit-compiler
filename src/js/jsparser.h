#ifndef __JSPARSER_H__
#define __JSPARSER_H__

#include "../parser.h"
#include "jslexer.h"
#include "jslexem.h"
#include "jsscope.h"
#include "jslexem.h"
#include "jslexer.h"

#include "jsvarnumber.h"
#include "jsvarstring.h"
#include "jsvararray.h"
#include "jsvarfunction.h"

#include <cstdlib>

#include <iostream>
#include <string>

#define SYNTAX_ERROR(msg) {\
	std::cout << "Syntax error: " << msg << " in line " << lineNumber << ":" << lineCleft << std::endl;\
	exit(-1); \
}

class JSParser : public JSLexer {
	private:
		JSVarFunction mainFunction;
		JSScope scope;

		JSLexem lexem;
		JSLexem nextLexem;
	public:
		JSParser(const std::string& file);

		void parse();
		void parseVar();
		void parseScope();

		JSVarNumber* parseVarNumber();
		JSVarString* parseVarString();
		JSVarArray* parseVarArray();
		//JSVarObject* parseVarObject();

		/*JSVarNumber* parseVarValue();

		void parse();

		void parseVar();
		void parseVarValue(const std::string &varName);
		void parseScope();*/

		bool isNext(LexemType type);

		void match(LexemType type);
		JSLexem get();
		JSLexem next();	
		JSLexem read();
		
};

#endif
