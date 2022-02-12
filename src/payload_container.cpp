#include "payload_container.h"
#include <iostream>
std::string payload_container::convert_to_payload(const std::string &combo) {
  if (const size_t index_of_colon{combo.find_first_of(':')}) {
    const auto username = combo.substr(0, index_of_colon);
    const auto password = combo.substr(index_of_colon + 1);
    std::ostringstream payload;
    payload << "username=" << username << "&password=" << password;
    return payload.str();
  }
  throw std::runtime_error("Combo format was invalid.\n");
}

std::pair<const char *, int>
payload_container::proxy_format(const std::string &proxy_address) {
  if (const size_t index_of_colon{proxy_address.find_first_of(':')}) {
    const auto address = proxy_address.substr(0, index_of_colon);
    const auto port = proxy_address.substr(index_of_colon + 1);
    try {
      auto pair = std::make_pair(address.c_str(), std::stoi(port));
      return pair;
    } catch ([[maybe_unused]] const std::invalid_argument &ex) {
      throw;
    }
  }
  throw std::runtime_error("Proxy format was invalid.\n");
}
