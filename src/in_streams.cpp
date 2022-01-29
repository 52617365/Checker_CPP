#include "in_streams.h"
#include "filestreams.h"
#include <fstream>

void in_streams::read_file() {
  std::fstream is{file_path, std::ios::in | std::ios::binary};
  is.exceptions(std::fstream::badbit);
  // Will throw if file path not found but no point catching it.
  handle_error(is, "get file size " + file_path + " success\n",
               "error getting file size of " + file_path + '\n');
  is.seekg(0, std::ios::end);
  const std::streamsize data_size = is.tellg();
  is.seekg(0, std::ios::beg);
  std::unique_ptr<char[]> data(new char[data_size]);
  is.read(data.get(), data_size);

  file.reserve(data_size / 40);

  std::cout << "Deleting duplicates.\n";

  size_t i = 0;
  size_t start = 0;
  while (i < data_size) {
    ++i;
    if (data[i] == '\n') // End of line, got string
    {
      file.emplace_back(data.get() + start, i - start);
      start = i + 1;
    }
  }
  file.emplace_back(data.get() + start, i - start);
  //  is.close();
  // return data_size / 40;
}
