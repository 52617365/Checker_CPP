#ifndef FILESTREAMS_H
#define FILESTREAMS_H
#include <string>


class filestreams {
protected:
  explicit filestreams(std::string file_path) : file_path{move(file_path)} {}

  const std::string file_path;
  static void handle_error(std::fstream &fs, const std::string &success_message,
                           const std::string &error_message);
  static void handle_error(std::ofstream &os, const std::string &success_message,
                           const std::string &error_message);
};

#endif // FILESTREAMS_H
