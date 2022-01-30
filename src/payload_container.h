
#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H
#include <optional>
#include <string_view>
using namespace std;
struct payload_container {
  using combo_pair = optional<pair<string_view, string_view>>;

  // Ctor that does take in a proxy authentication
  payload_container(string_view combo_payload, string_view user_agent,
                    string_view proxy, const combo_pair authentication)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy} {
    if (authentication) {
      proxy_authentication = authentication;
    }
  }

  // Ctor that does not take in a proxy authentication
  payload_container(string_view combo_payload, string_view user_agent,
                    string_view proxy)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy} {}

  string_view combo_payload;
  string_view user_agent;
  string_view proxy;
  combo_pair proxy_authentication;
};
#endif // PAYLOAD_CONTAINER_H
