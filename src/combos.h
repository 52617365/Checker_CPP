#ifndef COMBOS_H
#define COMBOS_H
#include "in_streams.h"

/**
 * class combos
 * The combos class will use a base class member called file that holds the
 * combos.txt file inside of it because the base class ctor fills it up.
 */

class combos final : public in_streams {
public:
  explicit combos(const std::string &path) : in_streams(path) {}
};
#endif // COMBOS_H
