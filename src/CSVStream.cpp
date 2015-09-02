/*
 * CSVReader.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Akash
 */

#include "CSVStream.h"

namespace CSVReader {

	std::map<std::string, std::string> CSVStream::get() {

		if (empty()) throw ParseError{"Input empty."};

		std::map<std::string, std::string> row {};

		for (auto i=headers.begin(), max = headers.end(); i < max; ++i) {
			switch(ts->current().type) {

			case TokenType::str:
				row[*i] = ts->current().str;
				nextSkipSeparator(ts);
				break;

			case TokenType::sep: // Empty string
				row[*i] = "";
				nextSkipSeparator(ts);
				break;

			case TokenType::ln:
			case TokenType::end: // error: too few items
				throw TooFewItemsError{};
				break;

			default: throw ParseError{"unrecognized token"};

			}
		}

		if (!ts->recordEnded()) {
			throw TooManyItemsError();
		}

		if (!ts->empty()) ts->get(); // goto next record

		return row;

	}

	std::vector<std::string> CSVStream::getHeaders(TokenStream* ts) {

		ts->get();

		std::vector<std::string> headers {};
		std::unordered_set<std::string> dupCheck {};

		while (!ts->recordEnded()) {

			if (!dupCheck.emplace(ts->current().str).second) {
				// if unable to add to the set, the header is a duplicate.
				throw ParseError{"duplicate header: "+ts->current().str};
			}

			headers.push_back(ts->current().str);
			nextSkipSeparator(ts);
		}

		if (!ts->empty()) ts->get();

		return headers;

	}

} /* namespace CSVReader */
