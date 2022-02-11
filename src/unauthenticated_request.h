#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "authenticated_request.h"
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class unauthenticated_request {
public:
  unauthenticated_request(const std::string &combo,
                          const std::string &user_agent,
                          const std::string &proxy) try
      : payload{combo, user_agent, proxy}, combo{combo} {
    // TODO: Catch in main but don't do anything.
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }
  response send_request();

private:
  // Just to store the original combo so we don't have to parse it later.
  std::string combo;
  payload_container payload;
};
#endif // UNAUTHENTICATED_REQUEST_H
