#include "jslexer.h"

#include <string>

JSLexer::JSLexer(const std::string& file) : Parser(file)  {}

JSLexem JSLexer::getLexem() {
	try {
		skipWhiteSpaces();

		char c = get();

		if (isDecNumber(c)) {
			long number = readNumber();
			JSLexem lexem(VAR_VALUE_NUMBER);
			lexem.setValue(number);
			return lexem;
		} else if (isVarChar(c)) {
			std::string keyword = readVarName();
			if (keyword == "if") {
				return JSLexem(KEYWORD_IF);
			} else if (keyword == "else") {
				return JSLexem(KEYWORD_ELSE);
			} else if (keyword == "do") {
				return JSLexem(KEYWORD_DO);
			} else if (keyword == "while") {
				return JSLexem(KEYWORD_WHILE);
			} else if (keyword == "for") {
				return JSLexem(KEYWORD_FOR);
			} else if (keyword == "switch") {
				return JSLexem(KEYWORD_SWITCH);
			} else if (keyword == "case") {
				return JSLexem(KEYWORD_CASE);
			} else if (keyword == "break") {
				return JSLexem(KEYWORD_BREAK);
			} else if (keyword == "default") {
				return JSLexem(KEYWORD_DEFAULT);
			} else if (keyword == "var") {
				return JSLexem(KEYWORD_VAR);
			} else {
				JSLexem lexem(VAR_NAME);
				lexem.setValue(keyword);
				return lexem;
			}
		} else {

			switch (c) {
				case '=':
					{
						match('=');
						if (get() == '=') {
							match('=');
							return JSLexem(OPERATOR_EQUALS);
						} else {
							return JSLexem(EQUALS);
						}
					}
					break;
				case '\'':
				case '"':
					{
					JSLexem lexem(VAR_VALUE_STRING);
					lexem.setValue(readString(c));
					return lexem;
					}
					break;
				case '{':
					match('{');
					return JSLexem(SCOPE_BEGIN);
				case '}':
					match('}');
					return JSLexem(SCOPE_END);
				case ';':
					match(';');
					return JSLexem(SEMICOLON);
				case '+':
					match('+');
					return JSLexem(OPERATOR_PLUS);
				case '-':
					match('-');
					return JSLexem(OPERATOR_MINUS);
				case '*':
					match('*');
					return JSLexem(OPERATOR_MUL);
				case '/':
					match('/');
					return JSLexem(OPERATOR_DIV);
				case '[':
					match('[');
					return JSLexem(ARRAY_BEGIN);
				case ',':
					match(',');
					return JSLexem(COMMA);
				case ']':
					match(']');
					return JSLexem(ARRAY_END);



			}
		}
	} catch (EndOfFIleException* e) {
		return JSLexem(FILE_EOF);
	}

	return JSLexem(FILE_EOF);
}
