/*
 * Token.h
 *
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

namespace CSVReader {

enum class TokenType {sep, str, ln, end};

struct Token {
	TokenType type;
	std::string str;
};

} /* namespace CSVReader */

#endif /* TOKEN_H_ */
