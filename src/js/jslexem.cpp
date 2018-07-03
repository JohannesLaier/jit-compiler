#include "jslexem.h"

#include <iostream>

JSLexem::JSLexem() {}

JSLexem::JSLexem(LexemType t) {
	type = t;
}

LexemType JSLexem::getType() {
	return type;
}

void JSLexem::setValue(std::string value) {
	s_value = value;
}

void JSLexem::setValue(long value) {
	n_value = value;
}

std::string JSLexem::getStrValue() {
	return s_value;
}

long JSLexem::getValue() {
	return n_value;
}
