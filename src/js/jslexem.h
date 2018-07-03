#ifndef __JSLEXEM_H__
#define __JSLEXEM_H__

#include <string>

enum LexemType {
	SEMICOLON = 0,
	SCOPE_BEGIN,
	SCOPE_END,
	KEYWORD_IF,
	KEYWORD_ELSE,
	KEYWORD_DO,
	KEYWORD_WHILE,
	KEYWORD_FOR,
	KEYWORD_SWITCH,
	KEYWORD_CASE,
	KEYWORD_BREAK,
	KEYWORD_DEFAULT,
	KEYWORD_VAR,
	KEYWORD_FUNCTION,
	OPERATOR_PLUS,
	OPERATOR_MINUS,
	OPERATOR_MUL,
	OPERATOR_DIV,
	OPERATOR_EQUALS,
	VAR_VALUE_STRING,
	VAR_VALUE_NUMBER,
	VAR_NAME,
	ARRAY_BEGIN,
	ARRAY_END,
	COMMA,
	EQUALS,
	FILE_EOF
};

class JSLexem {
	private:
		LexemType type;

		std::string s_value;
		long n_value;
	public:
		JSLexem();
		JSLexem(LexemType type);

		LexemType getType();

		void setValue(std::string value);
		void setValue(long value);

		std::string getStrValue();
		long getValue();
};

#endif
