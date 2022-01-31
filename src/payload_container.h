
#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H
#include <optional>
struct payload_container {
  using combo_pair = std::optional<std::pair<std::string_view, std::string_view>>;

  // Ctor that does take in a proxy authentication
  payload_container(std::string_view combo_payload, std::string_view user_agent,
                    std::string_view proxy, const combo_pair authentication)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy} {
    if (authentication) {
      proxy_authentication = authentication;
    }
  }

  // Ctor that does not take in a proxy authentication
  payload_container(std::string_view combo_payload, std::string_view user_agent,
                    std::string_view proxy)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy} {}

  std::string_view combo_payload;
  std::string_view user_agent;
  std::string_view proxy;
  combo_pair proxy_authentication;
};
#endif // PAYLOAD_CONTAINER_H
