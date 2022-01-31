#include "combos.h"
#include "invalid.h"
#include "proxies.h"
#include "unauthenticated_request.h"
#include "user_agents.h"
#include "valid.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>

int main() {
  try {
    /*
const combos c{"combos.txt"};
const proxies p{"proxies.txt"};
const user_agents ug{"user_agents.txt"};
*/

    unauthenticated_request r("Neekeri", "Neekeri", "Neekeri");
    r.send_request();
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
