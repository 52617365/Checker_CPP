#include "unauthenticated_request.h"
#include <fstream>
#include <iostream>

int main() {
  try {
    /*
const combos c{"combos.txt"};
const proxies p{"proxies.txt"};
const user_agents ug{"user_agents.txt"};
*/

    unauthenticated_request r("Neekeri", "Neekeri", "Neekeri");
    auto x = r.send_request();
  } catch (const std::bad_alloc &ex) {
    std::cin.get();
    return 1;
  } catch (const std::ifstream::failure &ex) {
    std::cin.get();
    return 1;
  } catch (const std::ofstream::failure &ex) {
    return 1;
  }
  return 0;
}
