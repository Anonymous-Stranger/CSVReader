/*
 * CSVStream.h
 *
 * Reads csv data and returns associative array records!!!
 * 
 *  Created on: Aug 15, 2015
 *      Author: Akash
 */

#ifndef CSVREADER_CSVSTREAM_H_
#define CSVREADER_CSVSTREAM_H_

#include <istream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "TokenStream.h"
#include "Errors.h"

namespace CSVReader {

class CSVStream {

public:
	using header_list = std::vector<std::string>;
	using row_obj = std::unordered_map<std::string, std::string>; // a record

	// Constructors assuming the first row contains the headers
	explicit CSVStream(std::istream& in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	explicit CSVStream(std::istream* in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	
	// Constructors having the user pass in a list of headers
	CSVStream(std::istream& in, header_list headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}
	CSVStream(std::istream* in, header_list headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}

	// CSVReader can't be copied.
	CSVStream(const CSVStream&)=delete;
	CSVStream& operator=(const CSVStream&)=delete;

	// Default move works for CSVStreams
	CSVStream(CSVStream&&)=default;
	CSVStream& operator=(CSVStream&&)=default;

	~CSVStream() { delete ts; };

	row_obj get(); // reads and returns the next record as an associative array

	const header_list& getHeaders() const { return headers; } // returns the headers of the csv file

	bool empty() const { return ts->empty(); } // checks if file is fully read

private:

	constexpr static char d_sep {TokenStream::d_sep}; // default separator

	TokenStream* ts; // the underlying stream of tokens (which parses character input into Token objects)
	const header_list headers; // the headers, saved from the first row of the file or passed in through the constructor.

	CSVStream(TokenStream* ts): CSVStream(ts, readHeaders(ts), false) {}
	/**
	 * note: the readHeaders(ts) function has an additional ts->get() operation at the end,
	 * so we don't need to read the first token off the TokenStream (see below).
	 */

	CSVStream(TokenStream* ts, header_list headers, bool get=true): ts{ts}, headers{headers} {
		if (get) ts->get(); // read the first token
	}

	header_list readHeaders(TokenStream* ts); // reads the headers from the first line of csv data

	void nextSkipSeparator(TokenStream* ts) {
		/** 
		 * loads next token, skipping a separator if it's there
		 * ONLY TO BE USED AFTER A STR! See use in next(). 
		 */

		/** 
		 * next token shouldn't be str; should be either sep, ln, or end.
		 * ln or end will be errors iff more headers exist.
		 * If sep, move on to next token. 
		 */
		
		if (ts->get().type == TokenType::sep) ts->get();
	}

};

} /* namespace CSVReader */

#endif /* CSVREADER_H_ */
