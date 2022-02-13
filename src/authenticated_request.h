#define CPPHTTPLIB_OPENSSL_SUPPORT
#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class authenticated_request {
public:
  static response send_request(std::string combo, payload_container payload);
};
#endif // AUTHENTICATED_REQUEST_H
