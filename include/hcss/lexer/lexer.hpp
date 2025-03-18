#pragma once

#include "token.hpp"
#include "tokenType.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
using std::string;
using std::vector;
using std::tuple;
using std::wstring;

#define COLUMN ((int) reader.tellg() - posOffset)

class Lexer {
	public:
		vector<Token> tokens;
		vector<Token>& lex();
		Lexer(std::istream& stream)
			: reader(stream)
		{};
	private:
		std::istream& reader;
		int posOffset = 0, line = 1;
        wchar_t current{};
		void addToken(TokenType type);
		void consumeWhitespace();
        wchar_t consumeEscapedCodePoint();
		void consumeString();
		wstring consumeIdent();
		void consumeHash();
		bool isIdentSequence();
		tuple<wstring, wstring> consumeNumber();
		void consumeNumericToken();
		void consumeIdentLike();
		void consumeUrl();
		void consumeBadUrl();
		void skipSpace();
};