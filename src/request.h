#ifndef REQUEST_H
#define REQUEST_H
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class request {
public:
  request(const std::string_view combo_payload, const std::string_view user_agent,
          const std::string_view proxy,
          std::pair<std::string_view, std::string_view> proxy_authentication)
      : payload{combo_payload, user_agent, proxy, proxy_authentication} {}

  // Initialize request without proxy authentication.
  request(const std::string_view combo_payload, const std::string_view user_agent,
          const std::string_view proxy)
      : payload{combo_payload, user_agent, proxy} {}

  virtual response send_request() = 0;

protected:
  payload_container payload;
  // Initialize request with proxy authentication.

//  virtual ~request();
};
#endif // REQUEST_H
