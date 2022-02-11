#include "unauthenticated_request.h"
<<<<<<< HEAD
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
=======
#include <charconv>
response unauthenticated_request::send_request() {
  //  auto pool = httplib::ThreadPool(std::thread::hardware_concurrency());
  httplib::Client cli("https://httpbin.org");
  cli.set_proxy(payload.proxy.first, payload.proxy.second);
  httplib::Headers headers = {{"Accept-Encoding", "gzip, deflate, br"},
                              {"user-agent", payload.user_agent}};
  auto res = cli.Post("/post", payload.combo_payload,
                      "application/x-www-form-urlencoded");
>>>>>>> 49d970cfe41597ff3f28c3ce70544bc622b0babe

  std::cin.get();
  response p(res->status, combo);
  return p;
}
