#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "authenticated_request.h"
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class unauthenticated_request {
public:
  unauthenticated_request(const std::string &combo_payload,
                          const std::string &user_agent,
                          const std::string &proxy) try
      : payload{combo_payload, user_agent, proxy} {
    // TODO: Catch in main but don't do anything.
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }
  response send_request();

private:
  payload_container payload;
};
#endif // UNAUTHENTICATED_REQUEST_H
