#include "jsvar.h"

JSVar::JSVar() {}

JSVar::JSVar(JSVarType type) {
	objectType = type;
}

JSVarType JSVar::getType() {
	return objectType;
}

void JSVar::setType(JSVarType type) {
	objectType = type;
}
