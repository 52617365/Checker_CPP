#include "authenticated_request.h"
#include "response.h"
response authenticated_request::send_request() const
{
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());
  httplib::Client cli("https://httpbin.org");
  cli.set_proxy(payload.proxy.first, payload.proxy.second);
  cli.set_proxy_basic_auth(payload.proxy_authentication->first.c_str(),
                           payload.proxy_authentication->second.c_str());
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};

  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");

  std::cin.get();
  response p(res->status, combo);
  return p;
}
