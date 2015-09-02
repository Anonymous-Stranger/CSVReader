/*
 * CSVReaderError.h
 *
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#ifndef CSVREADERERRORS_H_
#define CSVREADERERRORS_H_

#include <stdexcept>

namespace CSVReader {

	struct CSVReaderError: std::invalid_argument {
		CSVReaderError(std::string message="something failed"): std::invalid_argument("CSV Reader: "+message) {}
	};

	struct ReadError: CSVReaderError {
		ReadError(std::string message="bad input"): CSVReaderError("read failed - "+message) {}
	};

	struct IllegalCharError: ReadError {
		IllegalCharError(char c): ReadError(std::string{"illegal char '"}+c+"'") {}
	};

	struct ParseError: CSVReaderError {
		ParseError(std::string message="illegal token"): CSVReaderError("parse failed - "+message) {}
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

#endif /* CSVREADERERROR_H_ */
