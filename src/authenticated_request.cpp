#include "authenticated_request.h"
#include "response.h"
response authenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());

  // TODO: Add proxy authentication into here.
  httplib::Client cli("https://httpbin.org");
  auto [host, port]{proxy_format(payload.proxy)};
  cli.set_proxy(host, port);
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};

  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");

  std::cin.get();
  response p(res->status, payload.combo_payload);
  return p;
}
