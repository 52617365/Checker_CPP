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
    const combos c{"combos.txt"};
    const proxies p{"proxies.txt"};
    const user_agents ug{"user_agents.txt"};

    unauthenticated_request r("Neekeri", "Neekeri", "Neekeri");
    auto xd = r.send_request();
    // std::cout << xd.combo << xd.status_code;
    std::cin.get();
  } catch (const std::ifstream::failure &ex) {
    std::cerr << ex.what();
    std::cin.get();
    return 1;
  } catch (const std::bad_alloc &ex) {
    std::cerr << ex.what();
    std::cin.get();
    return 1;
  } catch (const std::ofstream::failure &ex) {
    std::cerr << ex.what();
    return 1;
  }
  return 0;
}
