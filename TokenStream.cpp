/*
 * TokenStream.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#include "TokenStream.h"

namespace CSVReader {

	Token TokenStream::get() {
		/* Reads and returns the next token. */

		if (in->eof()) {
			ct.type = TokenType::end;
			return ct;
		}

		char c = in->get();

		if (in->eof()) ct.type = TokenType::end; //eof
		else if (c == sep) ct.type = TokenType::sep; // separator
		else if (c == ln) ct.type = TokenType::ln; // new line
		else if (c == qt) { // quoted string
			ct.type = TokenType::str;
			ct.str = readQuotedStr();
		} else { // normal string
			ct.type = TokenType::str;

			std::stringstream s {};

			s << c;

			for(;;) { // break statement in loop

				if ((c = in->get()) == ln || c == sep) {
					in->putback(c);
					break;
				}

				if (in->eof()) break;

				if (in->fail()) throw IllegalCharError{c};
				if (c == qt) throw ReadError{"unexpected quotation mark"};

				s << c;
			}

			ct.str = s.str();
		}

		return ct;

	}

	std::string TokenStream::readQuotedStr() {
		/* Reads and returns the remainder of a quoted string. */

		std::stringstream s {};

		for (;;) { // break statement in loop

			char c = in->get();

			if (in->eof()) break;

			if (in->fail()) throw IllegalCharError{c};

			if (c == qt && in->peek() != qt) { // unescaped quote => end of string
				return s.str();
			} else s << c;
		}

		throw ReadError{"quoted string reached end of input without closing"};

	}

	void TokenStream::setInput(std::istream& in) {
		freeInput();
		this->in = &in;
		owner = false;
		ct.type = TokenType::end;
	}

	void TokenStream::setInput(std::istream* in) {
		freeInput();
		this->in = in;
		owner = true;
		ct.type = TokenType::end;
	}

} /* namespace CSVReader */
