#define CPPHTTPLIB_OPENSSL_SUPPORT
#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class authenticated_request {
public:
  authenticated_request(
      const std::string &combo, const std::string &user_agent,
      const std::string &proxy,
      const std::pair<std::string, std::string> &proxy_authentication) try
      : combo{std::move(combo)}, payload{combo, user_agent, proxy,
                                         proxy_authentication} {
  } catch (const std::invalid_argument &ex) {
    throw;
  } catch (const std::runtime_error &ex) {
    throw;
  }
  [[nodiscard]] response send_request() const;

private:
  // Just to store the original combo so we don't have to parse it later.
  std::string combo;
  payload_container payload;
};
#endif // AUTHENTICATED_REQUEST_H
