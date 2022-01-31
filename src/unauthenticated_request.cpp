#include "unauthenticated_request.h"
response unauthenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());

  httplib::Client cli("https://httpbin.org/post");
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate"}};
  if (auto res = cli.Post("/", "name=john1&note=coder", "application/json")) {
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
