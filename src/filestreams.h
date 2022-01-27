
#ifndef FILESTREAMS_H
#define FILESTREAMS_H
#include <string>

using namespace std;

class filestreams {
protected:
  explicit filestreams(string file_path) : file_path{move(file_path)} {}

  const string file_path;
  static void handle_error(ifstream &is, const string success_message,
                           const string error_message);
  static void handle_error(ofstream &os, const string success_message,
                           const string error_message);
};

#endif // FILESTREAMS_H
