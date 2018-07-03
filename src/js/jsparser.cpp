#include "jsparser.h"
#include "jsscope.h"
#include "jsvar.h"
#include "jsvarnumber.h"
#include "jsvarstring.h"

#include "../code.h"
#include "../opcodes.h"

#include <cassert>
#include <iostream>

JSParser::JSParser(const std::string& file) : JSLexer(file) {
	lexem = getLexem();
	nextLexem = getLexem();

	Opcodes opcodes(mainFunction.getCode());
	scope = JSScope(NULL);
	mainFunction.setScope(&scope);

	parse();

	opcodes.RET();

	mainFunction.getCode()->execute();
	std::cout << "test => " << scope.getNumber("test")->getValue() << std::endl;
}

void JSParser::parse() {
	while (get().getType() != FILE_EOF) {
		switch (get().getType()) {
			case KEYWORD_VAR:
				parseVar();
				break;
			case SCOPE_BEGIN:
				parseScope();
				break;
		}
	}
}

void JSParser::parseVar() {
	match(KEYWORD_VAR);

	std::string varName = get().getStrValue();
	match(VAR_NAME);

	Opcodes opcodes(mainFunction.getCode());

	JSVar* var;

	if (get().getType() == SEMICOLON) {
		match(SEMICOLON);
		var = new JSVarNumber(0);
	} else if (get().getType() == EQUALS) {
		match(EQUALS);

		JSVar* var1;
		JSLexem varType = get();
		switch (varType.getType()) {
			case VAR_VALUE_NUMBER:
				if (next().getType() == SEMICOLON) {
					var = parseVarNumber();
				} else {
					match(VAR_VALUE_NUMBER);
					opcodes.MOV_VALUE_TO_REG(EAX, varType.getValue());
				}
				break;
			case VAR_NAME:				
				if (next().getType() == SEMICOLON) {
					var = parseVarNumber();
				} else {
					match(VAR_NAME);
					var1 = scope.getNumber(varType.getStrValue());
					opcodes.MOV_ADDR_VALUE_TO_REG(EAX, EBX, ((JSVarNumber*) var1)->getValuePtr());
				}
				break;
		}

		if (get().getType() != SEMICOLON) {
			JSLexem operatorType = read();

			JSVar* var2;
			varType = read();
			switch (varType.getType()) {
				case VAR_VALUE_NUMBER:
					match(VAR_VALUE_NUMBER);
					opcodes.MOV_VALUE_TO_REG(ECX, varType.getValue());
					break;
				case VAR_NAME:
					match(VAR_NAME);
					var2 = scope.getNumber(varType.getStrValue());
					opcodes.MOV_ADDR_VALUE_TO_REG(ECX, EBX, ((JSVarNumber*) var2)->getValuePtr());
					break;
			}

			switch (operatorType.getType()) {
				case OPERATOR_PLUS:
					opcodes.ADD_REG(EAX, ECX);
					break;
				case OPERATOR_MINUS:
					opcodes.SUB_REG(EAX, ECX);
					break;
				case OPERATOR_MUL:
					opcodes.MUL_REG(ECX);
					break;
				case OPERATOR_DIV:
					opcodes.DIV_REG(ECX);
					break;
			}

			var = new JSVarNumber(0);
			opcodes.MOV_REG_TO_ADDR_VALUE(EAX, EBX, ((JSVarNumber*) var)->getValuePtr());
		}
	}

	scope.add(varName, var);

	match(SEMICOLON);
}

JSVarNumber* JSParser::parseVarNumber() {
	JSLexem current = lexem;
	match(VAR_VALUE_NUMBER);
	return new JSVarNumber(current.getValue());
}

JSVarString* JSParser::parseVarString() {
	JSLexem current = lexem;
	match(VAR_VALUE_STRING);
	return new JSVarString(current.getStrValue());
}

JSVarArray* JSParser::parseVarArray() {
	match(ARRAY_BEGIN);

	JSVarArray* arr = new JSVarArray();
	while (get().getType() != ARRAY_END) {
		switch (get().getType()) {
			case VAR_VALUE_NUMBER:
				arr->addValue(parseVarNumber());
				break;
			case VAR_VALUE_STRING:
				arr->addValue(parseVarString());
				break;
			case ARRAY_BEGIN:
				arr->addValue(parseVarArray());
				break;
		}

		if (get().getType() == COMMA) {
			match(COMMA);
			continue;
		}
	}

	match(ARRAY_END);
	return arr;
}

void JSParser::parseScope() {
	match(SCOPE_BEGIN);

	scope = JSScope(scope);

	parse();

	scope = scope.getParent();

	match(SCOPE_END);
}

bool JSParser::isNext(LexemType type) {
	return (next().getType() == type);
}

void JSParser::match(LexemType type) {
	assert (get().getType() == type);
	read();
}

JSLexem JSParser::get() {
	return lexem;
}

JSLexem JSParser::next() {
	return nextLexem;
}

JSLexem JSParser::read() {
	lexem = nextLexem;
	nextLexem = getLexem();
	return lexem;
}
