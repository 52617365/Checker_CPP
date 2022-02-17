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
  threading() try
      : valid{"valids.txt", std::ios::app}, invalid{"invalids.txt",
                                                    std::ios::app} {
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
      std::optional<std::pair<std::string, std::string>> &&authentication);

  void run_unauthenticated_tasks(std::vector<payload_container> &payloads);
  void run_authenticated_tasks(std::vector<payload_container> &payloads);
  void write_respones(std::vector<std::future<response>> &futures);
};
#endif // THREADING_H
