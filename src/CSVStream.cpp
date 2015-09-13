/*
 * CSVStream.cpp
 *
 * Reads csv data and returns associative array records!!!
 * 
 *  Created on: Aug 15, 2015
 *      Author: Akash
 */

#include "CSVStream.h"

namespace CSVReader {

	CSVStream::row_obj CSVStream::get() {
	/* reads and returns the next record as an associative array */

		if (empty()) throw ParseError{"Input empty."};

		row_obj row {};

		for (auto i=headers.begin(), max = headers.end(); i < max; ++i) {
			switch(ts->current().type) { // consider the current token

			case TokenType::str: // a string should be saved
				row[*i] = ts->current().str;
				nextSkipSeparator(ts); // go to the next important token (the separator is uninteresting)
				break;

			case TokenType::sep: // a separator implies an empty string
				row[*i] = "";
				ts->get();
				break;

			case TokenType::ln:
			case TokenType::end:
				if (i + 1 == max) row[*i] == ""; // either the last header is an empty string
				else throw TooFewItemsError{}; // or error: too few items
				break;

			default: throw ParseError{"unrecognized token"};

			}
		}

		if (!ts->recordEnded()) { // if we're not at the end of the record, something failed
			throw TooManyItemsError{};
		}

		if (!ts->empty()) ts->get(); // goto next record

		return row;

	}

	CSVStream::header_list CSVStream::readHeaders(TokenStream* ts) {
	/* reads the headers from the first line of csv data */

		header_list headers {};
		std::unordered_set<std::string> dupCheck {};

		ts->get();

		while (!ts->recordEnded()) {

			// should be a string; otherwise input is improper
			if (ts->current().type != TokenType::str) throw ParseError{"headers must have names"};

			if (!dupCheck.emplace(ts->current().str).second) {
				// if unable to add to the set, the header is a duplicate.
				throw ParseError{"duplicate header: "+ts->current().str};
			}

			// add to headers list
			headers.push_back(ts->current().str);
			
			// go to next interesting token
			nextSkipSeparator(ts);
		}

		if (!ts->empty()) ts->get(); // if there are any records, go to their start

		return headers;

	}

} /* namespace CSVReader */
