#include "filestreams.h"
#include <fstream>

void filestreams::handle_error(std::fstream &fstream, const char *success_message,
                  const char *error_message) {
  fstream.exceptions(std::ios_base::badbit);
  if (!fstream) {
    throw std::runtime_error("Error with stream.");
  }
  // Here it's eof().
}
