#include "unauthenticated_request.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT

response unauthenticated_request::send_request() const
{
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());
  httplib::Client cli("https://httpbin.org");
  cli.set_proxy(payload.proxy.first, payload.proxy.second);
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};
  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");

  std::cin.get();
  response p(res->status, combo);
  return p;
}
