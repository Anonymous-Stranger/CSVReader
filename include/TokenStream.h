/*
 * TokenStream.h
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
	constexpr static char d_sep {','}, d_qt {'"'}, d_ln {'\n'};

	TokenStream(std::istream& in, char sep=d_sep, char qt=d_qt, char ln=d_ln): TokenStream(&in, false, sep, qt, ln) {}
	TokenStream(std::istream* in, char sep=d_sep, char qt=d_qt, char ln=d_ln): TokenStream(in, true, sep, qt, ln) {}

	// TokenStream cannot be copied.
	TokenStream(const TokenStream&)=delete;
	TokenStream& operator=(const TokenStream&)=delete;

	~TokenStream() { freeInput(); }

	Token get(); /* Reads and returns the next token. */
	const Token& current() { return ct; }

	void setInput(std::istream& in);
	void setInput(std::istream* in);

	bool empty() { return ct.type == TokenType::end; }
	bool recordEnded() { return ct.type == TokenType::ln || empty(); }

protected:
	TokenStream(TokenStream&&)=default;
	TokenStream& operator=(TokenStream&&)=default;

private:
	std::istream* in;
	bool owner;

	const char sep, qt, ln;

	Token ct {TokenType::end};

	TokenStream(std::istream* in, bool owner, char sep, char qt, char ln):
		in{in}, owner{owner}, sep{sep}, qt{qt}, ln{ln} {}

	void freeInput() { if (owner) delete in; }

	std::string readQuotedStr();

};

} /* namespace CSVReader */

#endif /* TOKENSTREAM_H_ */
