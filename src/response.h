#ifndef RESPONSE_H
#define RESPONSE_H
#include <optional>
#include <sstream>
#include <string>
struct response {
  // TODO: Make overloaded output operator here.
  const int status_code;
  std::string combo;
  response(const int status, const std::string &combo)
      : status_code{status}, combo{std::move(combo)} {}
  friend std::ostream &operator<<(std::ostream &os, const response &res);
};
#endif // RESPONSE_H
