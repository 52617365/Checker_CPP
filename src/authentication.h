#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string_view>
using combo_type = std::optional<std::pair<std::string, std::string>>;
class authentication {
private:
  bool auth;
  combo_type auth_combo;
  bool ask_if_authentication();
  std::pair<std::string, std::string> ask_for_authentication();

public:
  authentication() : auth{ask_if_authentication()} {
    if (auth) {
      try {
        auth_combo = ask_for_authentication();
      } catch (const std::runtime_error &ex) {
        throw;
      }
    }
  }
  bool auth_getter() { return auth; }
  combo_type combo_getter() { return auth_combo; };
  std::pair<std::string, std::string> format_combo(const std::string &combo);
};
#endif // AUTHENTICATION_H
