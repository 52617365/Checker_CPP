#include "in_streams.h"

#include <fstream>

#include "filestreams.h"


void in_streams::read_file() {
  std::fstream is(file_path, std::ios::in | std::ios::binary);
  is.exceptions(std::fstream::badbit);
  handle_error(is, "open success\n", "error opening\n");
  is.seekg(0, std::ios::end);
  const std::streamoff data_size = is.tellg();
  is.seekg(0, std::ios::beg);
  const std::unique_ptr<char[]> data(new char[data_size]);
  is.read(data.get(), data_size);
  try {
      file.reserve(data_size / 40); // If you have some idea, avoid re-allocations
  } catch(const std::bad_alloc&)
	{
		throw;
		// Don't bother catching cuz at this point its over.
	}
    
                                  // as general practice with vector etc.
  for (size_t i = 0, start = 0; i < data_size; ++i) {
    if (data[i] == '\n') // End of line, got string
    {
      start = i + 1;
          file.emplace_back(data.get() + start, i - start);
    }
  }
  
}
