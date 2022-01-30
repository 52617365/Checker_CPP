#include "request.h"
class unauthenticated_request : public request {
public:
  using request::request;
  response send_request() override;
};
