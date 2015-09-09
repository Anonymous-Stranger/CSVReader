/*
 * BaseError.h
 *
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#ifndef CSVREADER_ERRORS_H_
#define CSVREADER_ERRORS_H_

#include <stdexcept>

namespace CSVReader {

	struct BaseError: std::invalid_argument {
		BaseError(std::string message="something failed"): std::invalid_argument("CSV Reader: "+message) {}
	};

	struct ReadError: BaseError {
		ReadError(std::string message="bad input"): BaseError("read failed - "+message) {}
	};

	struct IllegalCharError: ReadError {
		IllegalCharError(char c): ReadError(std::string{"illegal char '"}+c+"'") {}
	};

	struct ParseError: BaseError {
		ParseError(std::string message="illegal token"): BaseError("parse failed - "+message) {}
	};

	struct ItemMismatchError: ParseError {
		ItemMismatchError(std::string message=""): ParseError("row does not match headers; "+message) {}
	};

	struct TooFewItemsError: ItemMismatchError {
		TooFewItemsError(): ItemMismatchError("too few items") {}
	};

	struct TooManyItemsError: ItemMismatchError {
		TooManyItemsError(): ItemMismatchError("too many items") {}
	};

}

#endif /* ERRORS_H_ */
