#include "jsvararray.h"

JSVar* JSVarArray::getValue(unsigned int index) {
	return values[index];
}

void JSVarArray::addValue(JSVar* var) {
	values.push_back(var);
}

void* JSVarArray::getValuePtr() {
	return &values;
}
