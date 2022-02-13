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
      // Initialize a payload to be added into payloads vector.
      payload_container payload(
          combo[combo_index], user_agent[user_agent_index], proxy[proxy_index]);
      payloads.push_back(payload);
      if (payloads.size() == 8) {
        // Run the tasks and clear after.
        run_unauthenticated_tasks();
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
      payload_container payload(combo[combo_index],
                                user_agent[user_agent_index],
                                proxy[proxy_index], authentication);

      payloads.push_back(payload);
      if (payloads.size() == 8) {
        // Run the tasks and clear after.
        run_unauthenticated_tasks();
      }
    }
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  };
}

void threading::run_unauthenticated_tasks() {
  std::string shell = "KAKKA";
  payloads.clear();
  for (auto &payload : payloads) {
    responses.emplace_back(std::async(std::launch::async,
                                      &unauthenticated_request::send_request,
                                      shell, payload));
  }
  for (auto &response : responses) {
    std::cout << response.get().combo << '\n';
    if (response.get().status_code == 200) {
      valid << response.get().combo;
    } else {
      invalid << response.get().combo;
    }
  }
  payloads.clear();
}

void threading::run_authenticated_tasks() {
  std::string shell = "KAKKA";
  for (auto &payload : payloads) {
    responses.emplace_back(std::async(std::launch::async,
                                      &authenticated_request::send_request,
                                      shell, payload));
  }
}
