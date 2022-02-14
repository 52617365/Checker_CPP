#include "response.h"
#include <fstream>
#include <sstream>
std::ostream &operator<<(std::ostream &os, const response &res) {
  // username={username}&password={password}
  // username= -> 9
  // &password= -> 10

  std::string format = res.combo;
  // erases this: username=
  // string becomes this: {username}&password={password}
  format.erase(0, 9);
  size_t index_of_ampersand = format.find('&');

  // index_of_ampersand becomes itself + 1 after erasing;

  // Insert ':' to get username:password format.
  format.insert(format.begin() + index_of_ampersand - 1, ':');

  // erases this: &password=
  // string becomes this: {password}
  format.erase(index_of_ampersand + 1, 10);

  os << format << '\n';

  return os;
}
