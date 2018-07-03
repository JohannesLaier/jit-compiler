#ifndef __JSVARFUNCTION_H__
#define __JSVARFUNCTION_H__

#include "../code.h"

#include "jsvar.h"
#include "jsscope.h"

class JSScope;

class JSVarFunction : public JSVar {
	private:
		JSScope* scope;
		Code code;
	public:
		JSVarFunction();
		JSVarFunction(JSScope* scope);

		JSScope* getScope();
		Code* getCode();

		void setScope(JSScope* scope);

		int execute();
};

#endif
