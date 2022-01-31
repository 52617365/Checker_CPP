#ifndef RESPONSE_H
#define RESPONSE_H
#include <fstream>
#include <string_view>

struct response {
  int status_code = 0;
  std::string combo;
  friend std::ostream &operator<<(std::ostream &os, const response &res) {
    // Add output format here once you figure out the format.
    return os;
  }
};
#endif // RESPONSE_H
