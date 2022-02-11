#ifndef REQUEST_H
#define REQUEST_H
#include <string>
#include <utility>
class request {
protected:
	[[nodiscard]] std::pair<const char *, int> proxy_format(const std::string &proxy) const
  {
	  const size_t index_of_colon = proxy.find_first_of(':');
	  const auto username = proxy.substr(0, index_of_colon);
	  const auto password = proxy.substr(index_of_colon);
    return std::make_pair(username.c_str(), std::stoi(password));
  }
};

#endif // REQUEST.H
