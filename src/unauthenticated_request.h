#ifndef UNAUTHENTICATED_REQUEST_H
#define UNAUTHENTICATED_REQUEST_H
#include "request.h"
class unauthenticated_request final : public request {
public:
  using request::request;
  response send_request() override;
};
#endif // UNAUTHENTICATED_REQUEST_H
