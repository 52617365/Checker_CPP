#include "response.h"
#include <fstream>
#include <sstream>
std::ostream &operator<<(std::ostream &os, const response &res) {
  // username={username}&password={password}
  // username= -> 9
  //&password= -> 10

  if (size_t index_of_ampersand = res.combo.find('&');
      index_of_ampersand != std::string::npos) {

    std::string format = res.combo;
    // erases this: username=
    // string becomes this: {username}&password={password}
    format.erase(0, 9);
    // Index goes back by 9 since we just erased 9.
    index_of_ampersand -= 9;

    // Insert ':' to get username:password format.
    format.insert(format.begin() + index_of_ampersand - 1, ':');

    // erases this: &password=
    // string becomes this: {password}
    // We inserted a character so index_of_ampersand goes up by 1
    format.erase(index_of_ampersand + 1, 10);

    os << format;
  }
  return os;
}
