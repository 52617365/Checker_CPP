#include "unauthenticated_request.h"
response unauthenticated_request::send_request(payload_container payload) {
  httplib::Client cli("https://httpbin.org");
  cli.set_ca_cert_path("./ca-bundle.crt");
  cli.set_read_timeout(1, 0); // 1 seconds
  cli.enable_server_certificate_verification(false);
  // cli.set_proxy(payload.proxy.first, payload.proxy.second);
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};
  if (auto res = cli.Post("/post", payload.combo_payload,
                          "application/x-www-form-urlencoded")) {

    response p(res->status, payload.combo_payload);
    return p;
  } else {
    response p(400, payload.combo_payload);
    return p;
  }
}
