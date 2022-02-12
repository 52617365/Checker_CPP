#include "threading.h"
#include "authenticated_request.h"
#include "unauthenticated_request.h"
void threading::add_unauthenticated_tasks(
    const std::vector<std::string> &combo,
    const std::vector<std::string> &proxy,
    const std::vector<std::string> &user_agent) {
  try {
    for (int i = 0, j = 0, k = 0; i < combo.size(); ++i, ++k, ++j) {
      if (k == user_agent.size()) {
        k = 0;
      }
      if (j == proxy.size()) {
        j = 0;
      }
      // Loop through all of them, every 8 times fill 8 tasks into the thread
      // pool and wait for them to run, the last thread being the one appending
      // all the responses into a vector.
      unauthenticated_request r{combo[i], user_agent[k], proxy[j]};
      auto [A, B, C, D, F, G, H, J] = taskflow.emplace( // create eight tasks
          [&]() { auto response = r.send_request(); }, [&]() {}, [&]() {},
          [&]() {}, [&]() {}, [&]() {}, [&]() {}, [&]() {});
      // ADD TASKS HERE.;
    }
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }
}

void threading::add_authenticated_tasks(
    const std::vector<std::string> &combo,
    const std::vector<std::string> &proxy,
    const std::vector<std::string> &user_agent,
    const std::pair<std::string, std::string> &authentication) {

  try {
    for (int i = 0, j = 0, k = 0; i < combo.size(); ++i, ++k, ++j) {
      if (k == user_agent.size()) {
        k = 0;
      }
      if (j == proxy.size()) {
        j = 0;
      }
      // Loop through all of them, every 8 times fill 8 tasks into the thread
      // pool and wait for them to run, the last thread being the one appending
      // all the responses into a vector.
      authenticated_request r{combo[i], user_agent[k], proxy[j],
                              authentication};
      auto [A, B, C, D, F, G, H, J] = taskflow.emplace( // create eight tasks
          [&]() { auto response = r.send_request(); }, [&]() {}, [&]() {},
          [&]() {}, [&]() {}, [&]() {}, [&]() {}, [&]() {});
    }
  } catch (const std::runtime_error &ex) {
    throw;
  }
  // TODO: Catch in main and let user know that his proxy combo format is
  // wrong.
  catch (const std::invalid_argument &ex) {
    throw;
  };
}
void threading::run_tasks() { executor.run(taskflow).wait(); }
