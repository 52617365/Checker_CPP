#include "payload_container.h"

std::string payload_container::convert_to_payload(const std::string &combo) {

	if (const size_t index_of_colon = combo.find_first_of(':'); index_of_colon != std::string::npos)
  { 
	  const auto username = combo.substr(0, index_of_colon);
    const auto password = combo.substr(index_of_colon);
    std::ostringstream payload;
    payload << "username=" << username << "&password=" << password;
    return payload.str();
  }
  throw std::runtime_error("Combo format was invalid.\n");
}
std::pair<const char *, int>
payload_container::proxy_format(const std::string &proxy) const
{
	if (const size_t index_of_colon = proxy.find_first_of(':'); index_of_colon != std::string::npos)
  { 
	  const auto address = proxy.substr(0, index_of_colon);
	  const auto port = proxy.substr(index_of_colon);
    try {
      auto pair = std::make_pair(address.c_str(), std::stoi(port));
      return pair;
    } catch ([[maybe_unused]] const std::invalid_argument &ex) {
      throw;
    }
  }
  throw std::runtime_error("Proxy format was invalid.\n");
}
