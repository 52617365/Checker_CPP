#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class unauthenticated_request {
public:
  unauthenticated_request(const std::string &combo,
                          const std::string &user_agent,
                          const std::string &proxy) try
      : combo{std::move(combo)}, payload{combo, user_agent, proxy} {
    // TODO: Catch in main but don't do anything.
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }

  [[nodiscard]] response send_request() const;

private:
  // Just to store the original combo so we don't have to parse it later.
  std::string combo;
  payload_container payload;
};
#endif // UNAUTHENTICATED_REQUEST_H
