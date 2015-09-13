/*
 * TokenStream.h
 *
 * Converts a character input stream into a stream of Token objects.
 * This makes it easier to parse from CSV to associative arrays.
 * 
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#ifndef CSVREADER_TOKENSTREAM_H_
#define CSVREADER_TOKENSTREAM_H_

#include <iostream>

#include <istream>
#include <sstream>
#include "Token.h"
#include "Errors.h"

namespace CSVReader {

class TokenStream {

public:
	constexpr static char d_sep {','}, d_qt {'"'}, d_ln {'\n'}; // default separator, quote, and newline

	TokenStream(std::istream& in, char sep=d_sep, char qt=d_qt, char ln=d_ln): TokenStream(&in, false, sep, qt, ln) {}
	TokenStream(std::istream* in, char sep=d_sep, char qt=d_qt, char ln=d_ln): TokenStream(in, true, sep, qt, ln) {}

	// TokenStream cannot be copied.
	TokenStream(const TokenStream&)=delete;
	TokenStream& operator=(const TokenStream&)=delete;

	~TokenStream() { freeInput(); }

	Token get(); // reads and returns the next token
	const Token& current() { return ct; } // returns the last read token

	void setInput(std::istream& in);
	void setInput(std::istream* in);

	bool empty() { return ct.type == TokenType::end; } // returns true if there are no tokens left to be streamed
	bool recordEnded() { return ct.type == TokenType::ln || empty(); } // returns true if at the end of a record

protected:
	TokenStream(TokenStream&&)=default;
	TokenStream& operator=(TokenStream&&)=default;

private:
	std::istream* in; // internal character stream
	bool owner; // if owner, will delete stream when done

	const char sep, qt, ln; // separator, quote delimiter, newline

	Token ct {TokenType::end}; // current token.

	TokenStream(std::istream* in, bool owner, char sep, char qt, char ln):
		in{in}, owner{owner}, sep{sep}, qt{qt}, ln{ln} {}

	void freeInput() { if (owner) delete in; } // releases internal character stream

	std::string readQuotedStr(); // helper method to read quoted strings

};

} /* namespace CSVReader */

#endif /* TOKENSTREAM_H_ */
