#include "request.h"
class authenticated_request : public request {
public:
  using request::request;
  response send_request() override;
};
