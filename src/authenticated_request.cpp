#include "authenticated_request.h"
#include "response.h"
#include "payload_container.h"
response authenticated_request::send_request(const payload_container payload) {
  httplib::Client cli("https://httpbin.org");
  cli.set_read_timeout(1, 0); // 1 seconds
  cli.set_ca_cert_path("./ca-bundle.crt");
  cli.enable_server_certificate_verification(false);
  cli.set_proxy(payload.proxy.first, payload.proxy.second);
  cli.set_proxy_basic_auth(payload.proxy_authentication->first.c_str(),
                           payload.proxy_authentication->second.c_str());
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};

  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");

  std::cin.get();
  response p(res->status, payload.combo_payload);
  return p;
}
