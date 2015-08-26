/*
 * _main.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: Akash
 */

#include "_test.h"

namespace CSVReaderTest {

	void run(std::string testFile) {

		try {

			CSVReader::CSVStream in {new std::ifstream(testFile)};

			while (!in.empty()) {

				auto record = in.get();

				for (auto& item : record) {
					std::cout << item.first << ":";
					if (item.first == "cities") std::cout << item.second;
					else std::cout << CSVReader::to<double>(item.second);
					std::cout << "  ";
				}

				std::cout << std::endl;

			}

		} catch (std::exception& ex) {
			std::cerr << ex.what() << std::endl;
		} catch (...) {
			std::cerr << "Something failed." << std::endl;
		}

	}

}


