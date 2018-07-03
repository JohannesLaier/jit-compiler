#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>

class EndOfFIleException {};

class Parser {
	private:
		char* buffer;
		char* bufferPtr;

		size_t bufferSize;
	protected:
		int lineNumber;
		int lineCleft;
	protected:
		char get();
		char read();

		std::string getTo(char c);
		std::string getTo(char c1, char c2);
	
		std::string readTo(char c);
		std::string readTo(char c1, char c2);
		std::string readTo(char c1, char c2, char c3);
		std::string readTo(char c1, char c2, char c3, char c4);

		std::string readVarName();
		std::string readString(char c);

		long getNumber();
		long readNumber();

		void inc();
		void dec();

		void skip();
		void skip(char c);
		void skipWhiteSpaces();

		bool isDecNumber(char c);
		bool isHexNumber(char c);
		bool isWhitespace(char c);
		bool isOperator(char c);
		bool isVarChar(char c);

		void match(char c);
	public:
		Parser(const std::string& file);
		~Parser();
};

#endif
