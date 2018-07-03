#ifndef __JSSCOPE_H__
#define __JSSCOPE_H__

#include <string>
#include <map>

#include "jsvar.h"
#include "jsvarnumber.h"
#include "jsvarfunction.h"

class JSVarFunction;

class JSScope {
	private:
		std::map<std::string, JSVar*> elements;

		JSScope* parent = NULL;
	public:
		JSScope();
		JSScope(JSScope* parent);

		bool add(std::string name, JSVar* var);

		JSVar* getVar(std::string name);
		JSVarNumber* getNumber(std::string name);
		JSVarFunction* getFunction(std::string name);

		JSScope* getParent();

		~JSScope();
};

#endif
