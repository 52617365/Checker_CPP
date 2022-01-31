#ifndef AUTHENTICATED_REQUEST_H
#define AUTHENTICATED_REQUEST_H
#include "request.h"
class authenticated_request : public request {
public:
  using request::request;
  response send_request() override;
};
#endif // AUTHENTICATED_REQUEST_H
