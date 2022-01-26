
#ifndef FILESTREAMS_H
#define FILESTREAMS_H

#include <string>

class filestreams
{
public:
	explicit filestreams(std::string file_path) : file_path{std::move(file_path)} {}

  const std::string file_path;
protected:
  static void handle_error(std::fstream &fstream, const char *success_message,
                           const char *error_message);

};

#endif // FILESTREAMS_H
