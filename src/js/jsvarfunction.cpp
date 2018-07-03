#include "jsvarfunction.h"

JSVarFunction::JSVarFunction() : JSVar(FUNCTION) {}

JSVarFunction::JSVarFunction(JSScope* s) : JSVar(FUNCTION) {
	scope = s;
}

JSScope* JSVarFunction::getScope() {
	return scope;
}

int JSVarFunction::execute() {
	return code.execute();
}

void JSVarFunction::setScope(JSScope* s) {
	scope = s;
}

Code* JSVarFunction::getCode() {
	return &code;
}
