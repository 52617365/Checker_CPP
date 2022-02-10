#ifndef RESPONSE_H
#define RESPONSE_H
#include <fstream>
#include <string_view>

struct response {
  const int status_code;
  const std::string combo;
  response(const int status, const std::string &combo)
      : status_code{status}, combo{combo} {}
};
#endif // RESPONSE_H
