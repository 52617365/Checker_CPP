#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class authenticated_request {
public:
  authenticated_request(
      const std::string &combo, const std::string &user_agent,
      const std::string &proxy,
      std::pair<std::string, std::string> &proxy_authentication) try
      : payload{combo, user_agent, proxy, proxy_authentication}, combo{combo} {
  } catch (const std::invalid_argument &ex) {
    throw;
  } catch (const std::runtime_error &ex) {
    throw;
  }
  response send_request();

private:
  // Just to store the original combo so we don't have to parse it later.
  std::string combo;
  payload_container payload;
};
#endif // AUTHENTICATED_REQUEST_H
