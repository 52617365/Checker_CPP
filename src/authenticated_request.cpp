#include "authenticated_request.h"
response authenticated_request::send_request() {
  httplib::Client cli("https://httpbin.org");
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"}};
  auto res = cli.Post("/post", "name=john1&note=coder",
                      "application/x-www-form-urlencoded");

  std::cout << res->body;
  std::cin.get();
  response p;
  return p;
}
