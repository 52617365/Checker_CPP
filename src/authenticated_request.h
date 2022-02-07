#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class authenticated_request {
public:
  authenticated_request(
      const std::string &combo_payload, const std::string &user_agent,
      const std::string &proxy,
      std::pair<std::string, std::string> &proxy_authentication) try
      : payload{combo_payload, user_agent, proxy, proxy_authentication} {
  } catch (const std::invalid_argument &ex) {
    throw;
  } catch (const std::runtime_error &ex) {
    throw;
  }
  response send_request();

private:
  payload_container payload;
};
#endif // AUTHENTICATED_REQUEST_H
