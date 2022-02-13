#ifndef RESPONSE_H
#define RESPONSE_H
#include <string>
struct response {
  // TODO: Make overloaded output operator here.
  const int status_code;
  const std::string combo;
  response(const int status, const std::string &combo)
      : status_code{status}, combo{std::move(combo)} {}
};
#endif // RESPONSE_H
