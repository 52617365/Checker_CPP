#include "unauthenticated_request.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
response unauthenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());

  httplib::Client cli("https://httpbin.org/post");
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"}};
  if (auto res = cli.Post("/", "test", "application/json")) {
    if (res->status == 200) {
      std::cout << res->body << std::endl;
    }
  } else {
    auto err = res.error();
    std::cout << "Err is: " << err;
  }

  std::cin.get();
  response p;
  return p;
}
