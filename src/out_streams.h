#ifndef OUT_STREAMS_H
#define OUT_STREAMS_H
#include "filestreams.h"
#include <fstream>
#include <iostream>

class out_streams : filestreams {
public:
  explicit out_streams(const std::string &path)
      : filestreams(path), os{path, std::ios_base::app} {
    const std::string success_message =
        "Opened " + path + " successfully for writing.\n";
    const std::string error_message =
        "Could not open " + path + " for writing.\n";
    try {
      handle_error(os, success_message, error_message);
    } catch (const std::ofstream::failure &ex) {
      std::cerr << ex.what();
      throw;
    }
  }
  std::ofstream os;
};
#endif // OUT_STREAMS_H
