#include "payload_container.h"

std::string payload_container::convert_to_payload(const std::string &combo) {
  if (size_t index_of_colon =
          combo.find_first_of(':') && index_of_colon != std::string::npos) {
    auto username = combo.substr(0, index_of_colon);
    auto password = combo.substr(index_of_colon);
    std::ostringstream payload;
    payload << "username=" << username << "&password=" << password;
    return payload.str();
  }
  throw std::runtime_error("Combo format was invalid.\n");
}
std::pair<const char *, int>
payload_container::proxy_format(const std::string &proxy) {
  if (size_t index_of_colon =
          proxy.find_first_of(':') && index_of_colon != std::string::npos) {
    auto address = proxy.substr(0, index_of_colon);
    auto port = proxy.substr(index_of_colon);
    try {
      auto pair = std::make_pair(address.c_str(), std::stoi(port));
      return pair;
    } catch (const std::invalid_argument &ex) {
      throw;
    }
  }
  throw std::runtime_error("Proxy format was invalid.\n");
}
