#include <fstream>
#include <string_view>
using namespace std;

struct response {
  int status_code = 0;
  string combo;
  friend ostream &operator<<(ostream &os, const response &res) {
    // Add output format here once you figure out the format.
    return os;
  }
};
