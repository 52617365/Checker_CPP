
#ifndef IN_STREAMS_H
#define IN_STREAMS_H
#include "filestreams.h"
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class in_streams : filestreams {
protected:
	explicit in_streams(const std::string& path) : filestreams(path) {
    try {
      read_file();
    } catch (const std::runtime_error &ex) {
      std::cerr << ex.what();
    }
  }
  // This member will hold the contents of a file. For combos, it will hold
  // combos.txt, for proxies, it will hold proxies.txt and for user agents, it
  // will hold user_agents.txt.
  std::vector<std::string_view> file;

  void read_file();
};

#endif // IN_STREAMS_H
