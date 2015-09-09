/*
 * CSVReader.h
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
	using row_obj = std::unordered_map<std::string, std::string>;

	CSVStream(std::istream& in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	CSVStream(std::istream* in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	CSVStream(std::istream& in, header_list headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}
	CSVStream(std::istream* in, header_list headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}

	// CSVReader can't be copied.
	CSVStream(const CSVStream&)=delete;
	CSVStream& operator=(const CSVStream&)=delete;

	CSVStream(CSVStream&&)=default;
	CSVStream& operator=(CSVStream&&)=default;

	~CSVStream() { delete ts; };

	row_obj get();

	const header_list& getHeaders() const { return headers; }

	bool empty() const { return ts->empty(); }

private:

	constexpr static char d_sep {TokenStream::d_sep};

	TokenStream* ts;
	const header_list headers;

	CSVStream(TokenStream* ts): CSVStream(ts, getHeaders(ts), false) {}
	CSVStream(TokenStream* ts, header_list headers, bool get=true): ts{ts}, headers{headers} {
		if (get) ts->get();
	}

	header_list getHeaders(TokenStream* ts);

	void nextSkipSeparator(TokenStream* ts) {
		/* loads next token, skipping a separator if it's there
		 * ONLY TO BE USED AFTER A STR! See use in next(). */

		/* next token cannot be str, either sep, ln, or end.
		 * ln or end will be errors iff more headers exist.
		 * If sep, move on to next token. */
		if (ts->get().type == TokenType::sep) ts->get();
	}

};

} /* namespace CSVReader */

#endif /* CSVREADER_H_ */
