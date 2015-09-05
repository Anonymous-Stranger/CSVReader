
#include <iostream>
#include <stdexcept>
#include "_test.h"

int main() try {

	CSVReaderTest::run("test.csv");

} catch (std::exception ex) {
	std::cerr << std::cerr << ex.what() << std::endl;
} catch (...) {
	std::cerr << "CSVReader Test: Something failed.";
}