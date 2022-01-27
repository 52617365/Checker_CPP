#include "out_streams.h"
#include <iostream>

void out_streams::write_file(const response &res) {
  // response will have an overloaded operator that does the formatting and
  // error handling for us.
  os << res;
}
