#include <optional>
#include <string_view>
using namespace std;
using combo = optional<pair<string, string>>;
class authentication {
private:
  bool auth;
  combo auth_combo;
  bool ask_if_authentication();
  pair<string, string> ask_for_authentication();

public:
  authentication() : auth{ask_if_authentication()} {
    if (auth) {
      auth_combo = ask_for_authentication();
    }
  }
  bool auth_getter();
  pair<string_view, string_view> combo_getter();
  friend istream &operator>>(istream &is, authentication &auth);
};
