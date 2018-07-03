#ifndef __JSVARSTRING_H__
#define __JSVARSTRING_H__

#include "jsvar.h"

#include <string>

class JSVarString : public JSVar {
	private:
		std::string value;
	public:
		JSVarString(std::string value);

		std::string getValue();
		void setValue(std::string value);

		void* getValuePtr();
};

#endif
