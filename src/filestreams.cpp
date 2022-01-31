#include "filestreams.h"
#include <fstream>
#include <iostream>


void filestreams::handle_error(std::fstream &fs, const std::string &success_message,
                               const std::string &error_message) {
  fs.exceptions(std::ios_base::badbit);
  if (!fs) {
    throw std::ifstream::failure(error_message);
  }
  // Here it's eof().
	std::cout << success_message;
}

void filestreams::handle_error(std::ofstream &os, const std::string &success_message,
                               const std::string &error_message) {
  os.exceptions(std::ios_base::badbit);
  if (!os) {
    throw std::ofstream::failure(error_message);
  }
  // Here it's eof().
	std::cout << success_message;
}
