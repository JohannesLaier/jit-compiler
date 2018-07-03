#include "jsscope.h"

#include <iostream>

JSScope::JSScope() {
	parent = NULL;
}

JSScope::JSScope(JSScope* p) {
	parent = p;
}

bool JSScope::add(std::string name, JSVar* var) {
	if (elements.find(name) != elements.end()) {
		return false; // Element allready exists
	}
	elements[name] = var;
	return true;
}

JSScope::~JSScope() {
	for (std::map<std::string, JSVar*>::iterator it = elements.begin(); it != elements.end(); it++) {
		delete it->second;
	}
}

JSScope* JSScope::getParent() {
	return parent;
}

JSVar* JSScope::getVar(std::string name) {
	JSScope* scope = this;
	while (scope != NULL) {
		std::map<std::string, JSVar*>::iterator it = scope->elements.find(name);
		if (it != elements.end()) {
			return it->second;
		}
		scope = scope->getParent();
	}
	return NULL;
}

JSVarNumber* JSScope::getNumber(std::string name) {
	JSVar* var = getVar(name);
	if (var == NULL || var->getType() != NUMBER) {
		return NULL;
	}
	return (JSVarNumber*) var;
}

JSVarFunction* JSScope::getFunction(std::string name) {
	JSVar* var = getVar(name);
	if (var == NULL || var->getType() != FUNCTION) {
		return NULL;
	}
	return (JSVarFunction*) var;
}
