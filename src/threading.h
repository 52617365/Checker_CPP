#ifndef THREADING_H
#define THREADING_H
#include <string>

#include "taskflow/taskflow/taskflow.hpp"
struct threading {
  tf::Executor executor;
  tf::Taskflow taskflow;

  void add_unauthenticated_task(const std::string &combo,
                                const std::string &proxy,
                                const std::string &user_agent);
  void add_authenticated_task(
      const std::string &combo, const std::string &proxy,
      const std::string &user_agent,
      const std::pair<std::string, std::string> &authentication);
};
#endif // THREADING_H
