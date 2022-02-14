#include "threading.h"
#include "authenticated_request.h"
#include "invalid.h"
#include "unauthenticated_request.h"
#include "valid.h"
#include <future>

void threading::add_unauthenticated_tasks(
    const std::vector<std::string> &combo,
    const std::vector<std::string> &user_agent,
    const std::vector<std::string> &proxy) {
  try {
    for (int combo_index = 0, user_agent_index = 0, proxy_index = 0;
         combo_index < combo.size();
         ++combo_index, ++user_agent_index, ++proxy_index) {

      // out of range check for user agents.
      if (user_agent_index == user_agent.size()) {
        user_agent_index = 0;
      }
      // out of range check for proxies.
      if (proxy_index == proxy.size()) {
        proxy_index = 0;
      }
      // Initialize a payload to be added into vector containing payloads.
      if (payloads.size() < 8) {
        payload_container payload(combo[combo_index],
                                  user_agent[user_agent_index],
                                  proxy[proxy_index]);
        payloads.push_back(payload);
      } else {
        // Run the tasks and clear after.
        run_unauthenticated_tasks();
      }
    }
    // Here we might have stuff left in the payloads vector even though we ran
    // out of combos so we check those.
    if (!payloads.empty()) {
      run_unauthenticated_tasks();
    }
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }
}

void threading::add_authenticated_tasks(
    const std::vector<std::string> &combo,
    const std::vector<std::string> &user_agent,
    const std::vector<std::string> &proxy,
    const std::pair<std::string, std::string> &authentication) {

  try {
    for (int combo_index = 0, user_agent_index = 0, proxy_index = 0;
         combo_index < combo.size();
         ++combo_index, ++user_agent_index, ++proxy_index) {
      // out of range check for user agents.
      if (user_agent_index == user_agent.size()) {
        user_agent_index = 0;
      }
      // out of range check for proxies.
      if (proxy_index == proxy.size()) {
        proxy_index = 0;
      }

      if (payloads.size() < 8) {
        payload_container payload(combo[combo_index],
                                  user_agent[user_agent_index],
                                  proxy[proxy_index], authentication);
        payloads.push_back(payload);
      } else {
        // Run the tasks and clear after.
        run_authenticated_tasks();
      }
    }
    // Here we might have stuff left in the payloads vector even though we ran
    // out of combos so we check those.
    if (!payloads.empty()) {
      run_authenticated_tasks();
    }
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  };
}

void threading::run_unauthenticated_tasks() {
  for (auto &payload : payloads) {
    // using std::launch::async to hopefully launch the task on a new thread.
    try {
      responses.push_back(std::async(
          std::launch::async, &unauthenticated_request::send_request, payload));
    } catch (const std::system_error &ex) {
      std::cout << "Error initializing a thread\n";
      throw;
    }
    payloads.clear();
    write_respones();
  }
}

void threading::run_authenticated_tasks() {
  for (auto &payload : payloads) {
    try {
      responses.push_back(std::async(
          std::launch::async, &authenticated_request::send_request, payload));
    } catch (const std::system_error &ex) {
      std::cout << "Error initializing a thread\n";
      throw;
    }
    payloads.clear();
    write_respones();
  }
}

void threading::write_respones() {
  for (auto &response : responses) {
    // Awaiting response here because std::future becomes invalid after one
    // .get() and we need it later.
    auto await_response = response.get();

    if (await_response.status_code == 200) {
      valid << await_response << '\n';
    } else {
      invalid << await_response << '\n';
    }
  }
  //  responses.clear();
}
