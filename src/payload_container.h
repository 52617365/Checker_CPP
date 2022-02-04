
#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H
#include <optional>
struct payload_container {
  using combo_pair = std::optional<std::pair<std::string, std::string>>;

  // Ctor that does take in a proxy authentication
  payload_container(const std::string &combo_payload,
                    const std::string &user_agent, const std::string &proxy,
                    const combo_pair &authentication)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy},
        proxy_authentication{authentication} {}

  // Ctor that does not take in a proxy authentication
  payload_container(const std::string &combo_payload,
                    const std::string &user_agent, const std::string proxy)
      : combo_payload{combo_payload}, user_agent{user_agent}, proxy{proxy} {}

  const std::string combo_payload;
  const std::string user_agent;
  const std::string proxy;
  const combo_pair proxy_authentication;
};
#endif // PAYLOAD_CONTAINER_H
