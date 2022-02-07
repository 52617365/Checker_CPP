#ifndef RESPONSE_H
#define RESPONSE_H
#include <fstream>
#include <string_view>

struct response {
  const int status_code;
  const std::string combo;
  friend std::ostream &operator<<(std::ostream &os, const response &res) {
    // Add output format here once you figure out the format.
    return os;
  }
  response(const int status, const std::string &combo)
      : status_code{status}, combo{combo} {}
};
#endif // RESPONSE_H
