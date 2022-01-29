
#ifndef PROXIES_H
#define PROXIES_H
#include "in_streams.h"
/**
 * class proxies
 * The proxies class will have a class member called file that holds the
 * proxies.txt file inside of it because the base class ctor fills it up.
 */

class proxies final : public in_streams {
public:
  explicit proxies(const std::string &path) : in_streams(path) {}
};
#endif // PROXIES_H
