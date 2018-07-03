#ifndef __JSVARARRAY_H__
#define __JSVARARRAY_H__

#include "jsvar.h"

#include <vector>

class JSVarArray : public JSVar {
	private:
		std::vector<JSVar*> values;
	public:
		JSVar* getValue(unsigned int index);
		void addValue(JSVar* var);

		void* getValuePtr();
};

#endif
