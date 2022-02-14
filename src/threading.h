#ifndef THREADING_H
#define THREADING_H
#include "payload_container.h"
#include "response.h"
#include <fstream>
#include <future>
#include <string>
#include <vector>
struct threading {
  std::ofstream valid;
  std::ofstream invalid;
  std::vector<payload_container> payloads;
  std::vector<std::future<response>> responses;
  threading() try
      : valid{"valids.txt", std::ios::app}, invalid{"invalids.txt",
                                                    std::ios::app} {
    // reserve size to avoid reallocations, we won't need more space.
    payloads.reserve(8);
    responses.reserve(8);
  } catch (const std::ofstream::failure &ex) {
    throw;
  }

  void add_unauthenticated_tasks(const std::vector<std::string> &combo,
                                 const std::vector<std::string> &user_agent,
                                 const std::vector<std::string> &proxy);
  void add_authenticated_tasks(
      const std::vector<std::string> &combo,
      const std::vector<std::string> &user_agent,
      const std::vector<std::string> &proxy,
      const std::pair<std::string, std::string> &authentication);

  void run_unauthenticated_tasks();
  void run_authenticated_tasks();
  void write_respones();
};
#endif // THREADING_H
