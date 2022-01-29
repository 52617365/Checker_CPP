
#ifndef PROXIES_H
#define PROXIES_H
#include "filestreams.h"

/**
 * class proxies
 * The proxies class will have a class member called file that holds the
 * proxies.txt file inside of it because the base class ctor fills it up.
 */

class proxies final : public filestreams {
public:
  explicit proxies(const std::string &path) : filestreams(path) {}
};
#endif // PROXIES_H
