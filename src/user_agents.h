
#ifndef USER_AGENTS_H
#define USER_AGENTS_H
#include "filestreams.h"

/**
 * class user_agents
 * The user_agents class will have a class member called file that holds the
 * user_agents.txt file inside of it because the base class ctor fills it up.
 */

class user_agents final : filestreams {
public:
  explicit user_agents(const std::string &path) : filestreams(path) {}
};

#endif // USER_AGENTS_H
