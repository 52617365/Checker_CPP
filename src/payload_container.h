#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H
#include <optional>
#include <sstream>
struct payload_container {
  using combo_pair = std::pair<std::string, std::string>;

  const std::string combo_payload;
  const std::string user_agent;
  const std::pair<const char *, int> proxy;
  const std::optional<combo_pair> proxy_authentication;

  // Ctor that does take in a proxy authentication
  payload_container(const std::string &combo, const std::string &user_agent,
                    const std::string &proxy,
                    const combo_pair &authentication) try
      : combo_payload{convert_to_payload(combo)},
        user_agent{std::move(user_agent)}, proxy{proxy_format(proxy)},
        proxy_authentication{authentication} {
    // Gets caught in request classes + threading class which then throws it
    // into main.
  } catch ([[maybe_unused]] const std::invalid_argument &ex) {
    throw;
  } catch ([[maybe_unused]] const std::runtime_error &ex) {
    throw;
  }
  // Ctor that does not take in a proxy authentication
  payload_container(const std::string &combo, const std::string &user_agent,
                    const std::string &proxy) try
      : combo_payload{convert_to_payload(combo)},
        user_agent{std::move(user_agent)}, proxy{proxy_format(proxy)} {
  } catch ([[maybe_unused]] const std::runtime_error &ex) {
    throw;
  }

  static std::string convert_to_payload(const std::string &combo);
  [[nodiscard]] static std::pair<const char *, int>
  proxy_format(const std::string &proxy);
};
#endif // PAYLOAD_CONTAINER_H
