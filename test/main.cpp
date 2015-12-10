
#include <iostream>
#include <stdexcept>
#include "_test.h"

int main() try {

	std::cout << "This should work: " << std::endl;
	CSVReaderTest::run("test.csv");

	std::cout << std::endl << "And this should fail: " << std::endl;
	CSVReaderTest::run("test_bad.csv");

} catch (std::exception& ex) {
	std::cerr << std::endl << ex.what() << std::endl;
} catch (...) {
	std::cerr << std::endl << "CSVReader Test: Something failed." << std::endl;
}
