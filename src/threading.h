#ifndef THREADING_H
#define THREADING_H
#include "taskflow/taskflow/taskflow.hpp"
#include <string>

struct threading {
  tf::Executor executor;
  tf::Taskflow taskflow;

  void add_unauthenticated_tasks(const std::vector<std::string> &combo,
                                 const std::vector<std::string> &proxy,
                                 const std::vector<std::string> &user_agent);
  void add_authenticated_tasks(
      const std::vector<std::string> &combo,
      const std::vector<std::string> &proxy,
      const std::vector<std::string> &user_agent,
      const std::pair<std::string, std::string> &authentication);

  void run_tasks();
};
#endif // THREADING_H
