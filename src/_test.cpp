/*
 * _main.cpp
 *
 * A test to see if CSVStream is working. Should work with any proper csv file with first row headers.
 * 
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#include "_test.h"

namespace CSVReaderTest {

	void run(std::string testFile) {

		CSVReader::CSVStream in {new std::ifstream(testFile)}; // load the file

		while (!in.empty()) { // loop through file

			// fetch a record and print it:

			auto record = in.get();

			for (auto& item : record) {
				std::cout << item.first << ":" << item.second << "  ";
			}

			std::cout << std::endl;
		}

		std::cout << "File read." << std::endl;

	}

}


