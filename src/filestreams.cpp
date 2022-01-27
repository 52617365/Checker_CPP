#include "filestreams.h"
#include <fstream>
#include <iostream>

using namespace std;

void filestreams::handle_error(ifstream &is, const char *success_message,
                               const char *error_message) {
  is.exceptions(ios_base::badbit);
  if (!is) {
    throw ifstream::failure(error_message);
  }
  // Here it's eof().
  cout << success_message;
}

void filestreams::handle_error(ofstream &os, const char *success_message,
                               const char *error_message) {

  os.exceptions(ios_base::badbit);
  if (!os) {
    throw ofstream::failure(error_message);
  }
  // Here it's eof().
  cout << success_message;
}
