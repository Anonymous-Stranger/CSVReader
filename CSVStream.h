/*
 * CSVReader.h
 *
 *  Created on: Aug 15, 2015
 *      Author: Akash
 */

#ifndef CSVSTREAM_H_
#define CSVSTREAM_H_

#include <istream>
#include <vector>
#include <map>
#include <unordered_set>
#include "TokenStream.h"
#include "CSVReaderErrors.h"

namespace CSVReader {

class CSVStream {

public:
	CSVStream(std::istream& in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	CSVStream(std::istream* in, char sep=d_sep): CSVStream(new TokenStream{in, sep}) {}
	CSVStream(std::istream& in, std::vector<std::string> headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}
	CSVStream(std::istream* in, std::vector<std::string> headers, char sep=d_sep):
		CSVStream(new TokenStream{in, sep}, headers) {}

	// CSVReader can't be copied.
	CSVStream(const CSVStream&)=delete;
	CSVStream& operator=(const CSVStream&)=delete;

	~CSVStream() { delete ts; };

	std::map<std::string, std::string> get();

	const std::vector<std::string>& getHeaders() const { return headers; }

	bool empty() const { return ts->empty(); }

protected:
	CSVStream(CSVStream&&)=default;
	CSVStream& operator=(CSVStream&&)=default;

private:

	constexpr static char d_sep {TokenStream::d_sep};

	TokenStream* ts;
	const std::vector<std::string> headers;

	CSVStream(TokenStream* ts): CSVStream(ts, getHeaders(ts), false) {}
	CSVStream(TokenStream* ts, std::vector<std::string> headers, bool get=true): ts{ts}, headers{headers} {
		if (get) ts->get();
	}

	std::vector<std::string> getHeaders(TokenStream* ts);

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
