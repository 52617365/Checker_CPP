
#ifndef PAYLOAD_CONTAINER_H
#define PAYLOAD_CONTAINER_H
#include <optional>
#include <string_view>
struct payload_container
{
	using combo_pair = std::optional<std::pair<std::string_view, std::string_view>>;

	payload_container(std::string_view combo_payload, std::string_view user_agent, std::string_view proxy, const combo_pair authentication): combo_payload{ combo_payload }, user_agent{ user_agent }, proxy{ proxy }
	{
		if (authentication) { proxy_authentication = authentication; }
	}
 std::string_view combo_payload;
 std::string_view user_agent;
 std::string_view proxy;
 std::optional<std::pair<std::string_view, std::string_view>> proxy_authentication;
};
#endif // PAYLOAD_CONTAINER_H
