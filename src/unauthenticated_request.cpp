#include "unauthenticated_request.h"
response unauthenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());

  // Segmentation fault.
  httplib::Client cli("https://httpbin.org");
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"}};
  auto res = cli.Post("/post", "name=john1&note=coder",
                      "application/x-www-form-urlencoded");

  std::cout << res->body;
  std::cin.get();
  response p;
  return p;
}
