#include "parser.h"

#include <fstream>
#include <sstream>
#include <cstring>
#include <cassert>

#include <iostream>

Parser::Parser(const std::string& file) {
	std::ifstream in(file.c_str());
	if (in.is_open()) {
		std::stringstream stream;
		stream << in.rdbuf();
		std::string sourceCode = stream.str();
		buffer = new char[sourceCode.size()];
		bufferPtr = buffer;
		bufferSize = sourceCode.size();
		memcpy(buffer, sourceCode.c_str(), sourceCode.size());
	}
	in.close();

	lineNumber = 1;
	lineCleft = 1;
}

Parser::~Parser() {
	delete[] bufferPtr;
}

char Parser::get() {
	return buffer[0];
}

char Parser::read() {
	lineCleft++;
	if (buffer[0] == ';') {
		lineCleft = 0;
		lineNumber++;
	}

	if (buffer > bufferPtr + bufferSize) {
		throw new EndOfFIleException();
	}

	return buffer++[0];
}

std::string Parser::getTo(char c) {
	std::string data("");
	while (get() != c) {
		data += read();
	}
	buffer -= data.size();
	return data;
}

std::string Parser::getTo(char c1, char c2) {
	std::string data("");
	while (get() != c1 && get() != c2) {
		data += read();
	}
	buffer -= data.size();
	return data;
}

std::string Parser::readTo(char c) {
	std::string data("");
	while (get() != c) {
		data += read();
	}
	return data;
}

std::string Parser::readTo(char c1, char c2) {
	std::string data("");
	while (get() != c1 && get() != c2) {
		data += read();
	}
	return data;
}

std::string Parser::readTo(char c1, char c2, char c3) {
	std::string data("");
	while (get() != c1 && get() != c2 && get() != c3) {
		data += read();
	}
	return data;
}

std::string Parser::readTo(char c1, char c2, char c3, char c4) {
	std::string data("");
	while (get() != c1 && get() != c2 && get() != c3 && get() != c4) {
		data += read();
	}
	return data;
}

std::string Parser::readVarName() {
	std::string data("");
	while (isVarChar(get())) {
		data += read();
	}
	return data;
}

std::string Parser::readString(char sep) {
	match(sep);
	std::string str("");
	char c;
	while (get() != sep) {
		c = read();
		str += c;
	}
	match(sep);
	return str;
}

long Parser::getNumber() {
	std::string data("");
	while (isDecNumber(get())) {
		data += read();
	}
	std::stringstream stream;
	stream << data;
	buffer -= data.size();

	long f = 0;
	stream >> f;
	return f;
}

long Parser::readNumber() {
	std::string data("");
	while (isDecNumber(get())) {
		data += read();
	}
	return ::atol(data.c_str());
}

bool Parser::isDecNumber(char c) {
	return c >= '0' && c <=  '9';
}

bool Parser::isHexNumber(char c) {
	return (c >= '0' && c <=  '9')
		|| (c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f');
}

bool Parser::isVarChar(char c) {
	return (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| c == '_';
}

bool Parser::isWhitespace(char c) {
	return c == ' '
		|| c == '\t'
		|| c == '\r'
		|| c == '\n';
}

bool Parser::isOperator(char c) {
	return c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/'
		|| c == '%';
}

void Parser::skip() {
	inc();
}

void Parser::skip(char c) {
	assert(get() == c);
	skip();
}

void Parser::skipWhiteSpaces() {
	while (isWhitespace(get()) == true) {
		skip();
	}
}

void Parser::inc() {
	buffer++;
}

void Parser::dec() {
	buffer--;
}

void Parser::match(char c) {
	assert (c == get());
	read();
}
