#include "response.h"
#include <fstream>
#include <sstream>
std::ostream &operator<<(std::ostream &os, const response &res) {
  // username={username}&password={password}
  // username= -> 9
  //&password= -> 10
  // TODO: Fix these allocations, we can do way better.
  // We want {username}:{password}
  // Heavy use of string_view to avoid redundant allocations since substr is
  // very expensive.

  size_t index_of_ampersand = res.combo.find('&');

  // username={username}
  std::string user_payload = res.combo.substr(0, index_of_ampersand);
  // password={password}
  std::string pass_payload = res.combo.substr(index_of_ampersand + 1);

  // {username}
  std::string username =
      user_payload.substr(user_payload.find('=') + 1, index_of_ampersand);

  //{password}
  std::string password = pass_payload.substr(pass_payload.find('=') + 1);

  os << std::string{username} << ':' << std::string{password};

  return os;
}
