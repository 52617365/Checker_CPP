#include "combos.h"
#include "invalid.h"
#include "proxies.h"
#include "threading.h"
#include "unauthenticated_request.h"
#include "user_agents.h"
#include "valid.h"
#include <iostream>
#include <string_view>
#include <vector>

int main() {
  try {
    const combos c{"combos.txt"};
    const proxies p{"proxies.txt"};
    const user_agents ug{"user_agents.txt"};

    if (c.file.empty() || p.file.empty() || ug.file.empty()) {
      std::cerr << "Some file is empty.\n";
      return 1;
    }
    /*
    unauthenticated_request req(c.file[0], ug.file[0], p.file[0]);
    auto req_response{req.send_request()};
    if (req_response.status_code == 200) {
      write_valid.os << req_response.combo;
    } else {
      write_invalid.os << req_response.combo;
    }
    */
    threading thread_pool;
    thread_pool.add_unauthenticated_tasks(c.file, ug.file, p.file);

    std::cin.get();
  } catch (const std::runtime_error &ex) {
    std::cerr << "\nThere was a problem with the formatting of your files.\n"
              << ex.what();
    std::cin.get();
  } catch (const std::invalid_argument &ex) {
    std::cerr << "\nThere was a problem parsing your combos/proxies.\n"
              << ex.what();
    std::cin.get();
  } catch (const std::exception &ex) {
    std::cerr << ex.what();
    std::cin.get();
    // const std::ifstream::failure &ex
    // const std::bad_alloc &ex
    // const const std::ofstream::failure &ex
    // There is no point in handling these because without them we can't do
    // anything.
  }
  return 1;
}
