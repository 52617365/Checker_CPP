#include <string>
#include <utility>
class request {
protected:
  std::pair<const char *, int> proxy_format(const std::string &proxy) {
    int index_of_colon = proxy.find_first_of(':');
    auto username = proxy.substr(0, index_of_colon);
    auto password = proxy.substr(index_of_colon);
    return std::make_pair(username.c_str(), std::stoi(password));
  }
};
