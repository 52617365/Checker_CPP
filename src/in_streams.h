
#ifndef IN_STREAMS_H
#define IN_STREAMS_H
#include "filestreams.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
class in_streams : filestreams {
public:
  // This member will hold the contents of a file. For combos, it will hold
  // combos.txt, for proxies, it will hold proxies.txt and for user agents, it
  // will hold user_agents.txt.
  std::vector<std::string> file;

protected:
  explicit in_streams(const std::string &path) try
      : filestreams(path), file{read_file()} {
  } catch (const ifstream::failure &ex) {
    std::cerr << ex.what();
    throw;
  } catch (const std::bad_alloc &ex) {
    std::cerr << ex.what();
    throw;
  }
  std::vector<std::string> read_file();
};

#endif // IN_STREAMS_H
