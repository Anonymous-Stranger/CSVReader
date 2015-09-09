/*
 * CSVReader.h
 *
 * Combines the CSVStream object with helper functions.
 *
 *  Created on: Aug 16, 2015
 *      Author: Akash
 */

#ifndef CSVREADER_CSVREADER_H_
#define CSVREADER_CSVREADER_H_

#include <sstream>
#include "CSVStream.h"
#include "Errors.h"

namespace CSVReader {

	/* (pg 730, TC++PL 4th, Stroustrup) */
	template<typename Target=std::string, typename Source=std::string>
	inline Target to(Source arg) {
		std::stringstream interp {};
		Target result;

		if ( !(interp << arg) 						// write arg to stream
			|| !(interp >> result)					// read result from stream
			|| !(interp >> std::ws).eof()) {		// stuff left in stream?
			throw BaseError{"to<>() failed"};
		}

		return result;
	}

}

#endif /* CSVREADER_H_ */
