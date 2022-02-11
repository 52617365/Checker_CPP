#include "threading.h"
#include "unauthenticated_request.h"
void threading::add_unauthenticated_task(const std::string &combo,
                                         const std::string &proxy,
                                         const std::string &user_agent) {
  try {
    taskflow.emplace([&]() {
      unauthenticated_request r{combo, proxy, user_agent};
      // TODO: Catch return value of r.send_request and then add it to some
      // array or something else to write into file.
      r.send_request();
    });
    // TODO: Catch exception in main but don't do anything.
  } catch (const std::runtime_error &ex) {
    throw;
  } catch (const std::invalid_argument &ex) {
    throw;
  }
}

void threading::add_authenticated_task(
    const std::string &combo, const std::string &proxy,
    const std::string &user_agent,
    const std::pair<std::string, std::string> &authentication) {
  try {
    taskflow.emplace([&]() {
      unauthenticated_request r{combo, proxy, user_agent};
      // TODO: Catch return value of r.send_request and then add it to some
      // array or something else to write into file.
      r.send_request();
    });
    // TODO: Catch exception in main but don't do anything.
  } catch (const std::runtime_error &ex) {
    throw;
  }
  // TODO: Catch in main and let user know that his proxy combo format is
  // wrong.
  catch (const std::invalid_argument &ex) {
    throw;
  };
}
