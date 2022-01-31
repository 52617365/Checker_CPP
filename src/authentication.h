#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
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
      auth_combo = ask_for_authentication();
    }
  }
  bool auth_getter();
  std::pair<std::string_view, std::string_view> combo_getter();
  friend std::istream &operator>>(std::istream &is, authentication &auth);
};
#endif // AUTHENTICATION_H
