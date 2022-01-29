
#ifndef USER_AGENTS_H
#define USER_AGENTS_H
#include "in_streams.h"
/**
 * class user_agents
 * The user_agents class will have a class member called file that holds the
 * user_agents.txt file inside of it because the base class ctor fills it up.
 */

class user_agents final : public in_streams {
public:
  explicit user_agents(const std::string &path) : in_streams(path) {}
};

#endif // USER_AGENTS_H
