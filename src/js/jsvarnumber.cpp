#include "jsvarnumber.h"

JSVarNumber::JSVarNumber(long v) : JSVar(NUMBER) {
	value = v;
}

long JSVarNumber::getValue() {
	return value;
}

void JSVarNumber::setValue(long v) {
	value = v;
}

void* JSVarNumber::getValuePtr() {
	return &value;
}
