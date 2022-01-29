
#ifndef OUT_STREAMS_H
#define OUT_STREAMS_H
#include "filestreams.h"
#include "payload_container.h"
#include "response.h"
#include <fstream>
#include <iostream>
using namespace std;

class out_streams : filestreams {
protected:
  out_streams(const string &path) : filestreams(path), os{path, ios_base::app} {
    const string success_message =
        "Opened " + path + " successfully for writing.\n";
    const string error_message = "Could not open " + path + " for writing.\n";
    try {
      filestreams::handle_error(os, success_message, error_message);
    } catch (const ofstream::failure &ex) {
      cerr << ex.what();
      // Do not bother catching because we can't function without the output
      // file.
      throw;
    }
  }
  ofstream os;
  void write_file(const response &res) { os << res; }
};
#endif // OUT_STREAMS_H
