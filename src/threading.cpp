#include "threading.h"
#include "authenticated_request.h"
#include "unauthenticated_request.h"
void threading::add_unauthenticated_tasks(
    const std::vector<std::string> &combo,
    const std::vector<std::string> &proxy,
    const std::vector<std::string> &user_agent) {

  std::vector<payload_container> send;
  try {
    for (int combo_index = 0, user_agent_index = 0, proxy_index = 0;
         combo_index < combo.size();
         ++combo_index, ++user_agent_index, ++proxy_index) {
      if (user_agent_index == user_agent.size()) {
        user_agent_index = 0;
      }
      if (proxy_index == proxy.size()) {
        proxy_index = 0;
      }

      payload_container payload(
          combo[combo_index], user_agent[user_agent_index], proxy[proxy_index]);
      send.push_back(payload);
      // Loop through all of them, every 8 times fill 8 tasks into the
      // thread pool and wait for them to run, the last thread being the one
      // appending all the responses into a vector.
      if (send.size() == 8) {
        unauthenticated_request r{combo[combo_index],
                                  user_agent[user_agent_index],
                                  proxy[proxy_index]};
        auto [A, B, C, D, F, G, H, J] = taskflow.emplace( // create eight tasks
            [&]() { auto response = r.send_request(); }, [&]() {}, [&]() {},
            [&]() {}, [&]() {}, [&]() {}, [&]() {}, [&]() {});
        // ADD TASKS HERE.;
        send.clear();
      }
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
    for (int combo_index = 0, user_agent_index = 0, proxy_index = 0;
         combo_index < combo.size();
         ++combo_index, ++user_agent_index, ++proxy_index) {
      if (user_agent_index == user_agent.size()) {
        user_agent_index = 0;
      }
      if (proxy_index == proxy.size()) {
        proxy_index = 0;
      }
      // all the responses into a vector.
      authenticated_request r{combo[combo_index], user_agent[user_agent_index],
                              proxy[proxy_index], authentication};
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
