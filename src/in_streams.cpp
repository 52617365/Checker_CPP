#include "in_streams.h"
#include "filestreams.h"
#include <fstream>
#include <memory>
std::vector<std::string> in_streams::read_file() const {
  try {
    std::fstream is{file_path, std::ios::in | std::ios::binary};
    is.exceptions(std::fstream::badbit);
    // Will throw if file path not found but no point catching it.
    handle_error(is, "reading of " + file_path + " success\n",
                 "error while reading " + file_path + '\n');
    is.seekg(0, std::ios::end);
    const std::streamsize data_size = is.tellg();
    is.seekg(0, std::ios::beg);
    std::unique_ptr<char[]> data(new char[data_size]);
    is.read(data.get(), data_size);

    std::vector<std::string> load_file;
    // Data size / sizeof(std::string)
    load_file.reserve(data_size / 32);

    size_t i = 0;
    size_t start = 0;
    while (i < data_size) {
      ++i;
      if (data[i] == '\n') // End of line, got string
      {
        load_file.emplace_back(data.get() + start, i - start);
        start = i + 1;
      }
    }
    return load_file;
  } catch (const std::bad_alloc &ex) {
    throw;
  }
}
