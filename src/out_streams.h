
#ifndef OUT_STREAMS_H
#define OUT_STREAMS_H
#include "filestreams.h"
#include "response.h"
#include <fstream>
#include <iostream>

class out_streams : filestreams {
protected:
	explicit out_streams(const std::string &path) : filestreams(path), os{path, std::ios_base::app} {
    const std::string success_message =
        "Opened " + path + " successfully for writing.\n";
    const std::string error_message = "Could not open " + path + " for writing.\n";
    try {
      handle_error(os, success_message, error_message);
    } catch (const std::ofstream::failure &ex) {
	    std::cerr << ex.what();
      // Do not bother catching because we can't function without the output
      // file.
      throw;
    }
  }

  std::ofstream os;
  void write_file(const response &res) { os << res; }
};
#endif // OUT_STREAMS_H
