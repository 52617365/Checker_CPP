#include "unauthenticated_request.h"
response unauthenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());
  httplib::Client cli("https://httpbin.org/post");
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"}};
  auto res = cli.Post("/", "name=john1&note=coder",
                      "application/x-www-form-urlencoded");
  std::cout << res->status;
  std::cin.get();
  response p;
  return p;
}
