#include "payload_container.h"
#include "response.h"
using namespace std;
class request {
protected:
  payload_container payload;
  // Initialize request with proxy authentication.
  request(string_view combo_payload, string_view user_agent, string_view proxy,
          pair<string_view, string_view> proxy_authentication)
      : payload{combo_payload, user_agent, proxy, proxy_authentication} {}

  // Initialize request without proxy authentication.
  request(string_view combo_payload, string_view user_agent, string_view proxy)
      : payload{combo_payload, user_agent, proxy} {}

  virtual response send_request() = 0;
  virtual ~request();
};
