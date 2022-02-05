#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "payload_container.h"
#include "request.h"
#include "response.h"
class unauthenticated_request : public request {
public:
  unauthenticated_request(const std::string &combo_payload,
                          const std::string &user_agent,
                          const std::string &proxy)
      : payload{combo_payload, user_agent, proxy} {}
  response send_request();

private:
  payload_container payload;
};
#endif // UNAUTHENTICATED_REQUEST_H
