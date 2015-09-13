/*
 * Token.h
 *
 * TokenStream parses character input into these Tokens,
 * making it easier for them to be converted into associative arrays.
 * 
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#ifndef CSVREADER_TOKEN_H_
#define CSVREADER_TOKEN_H_

#include <string>

namespace CSVReader {

enum class TokenType {sep, str, ln, end}; // separator, string, newline, eof

struct Token {
	TokenType type;
	std::string str;
};

} /* namespace CSVReader */

#endif /* TOKEN_H_ */
