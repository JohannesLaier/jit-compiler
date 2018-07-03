#ifndef __JSVARNUMBER_H__
#define __JSVARNUMBER_H__

#include "jsvar.h"

class JSVarNumber : public JSVar {
	private:
		long value;
	public:
		JSVarNumber(long value);

		long getValue();
		void setValue(long value);

		void* getValuePtr();
};

#endif
