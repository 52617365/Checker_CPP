#include "filestreams.h"
#include <fstream>
#include <iostream>

using namespace std;

void filestreams::handle_error(fstream &fs, const string &success_message,
                               const string &error_message) {
  fs.exceptions(ios_base::badbit);
  if (!fs) {
    throw ifstream::failure(error_message);
  }
  // Here it's eof().
  cout << success_message;
}

void filestreams::handle_error(ofstream &os, const string &success_message,
                               const string &error_message) {
  os.exceptions(ios_base::badbit);
  if (!os) {
    throw ofstream::failure(error_message);
  }
  // Here it's eof().
  cout << success_message;
}
