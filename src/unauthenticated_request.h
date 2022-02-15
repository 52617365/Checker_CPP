#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "payload_container.h"
#include "response.h"
class unauthenticated_request {
public:
  static response send_request(payload_container payload);
};
#endif // UNAUTHENTICATED_REQUEST_H