#include "jsvarstring.h"

JSVarString::JSVarString(std::string v) : JSVar(STRING) {
	value = v;
}

std::string JSVarString::getValue() {
	return value;
}

void JSVarString::setValue(std::string v) {
	value = v;
}

void* JSVarString::getValuePtr() {
	return (void*) value.c_str();
}
