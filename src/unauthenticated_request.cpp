#include "unauthenticated_request.h"
response unauthenticated_request::send_request(payload_container payload) {
  httplib::Client cli("https://httpbin.org");
  cli.set_ca_cert_path("./ca-bundle.crt");
  cli.enable_server_certificate_verification(false);
  //  cli.set_proxy(payload.proxy.first, payload.proxy.second);
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};
  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");

  std::cin.get();
  response p(res->status, payload.combo_payload);
  return p;
}
