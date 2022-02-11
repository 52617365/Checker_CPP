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
    valid write_valid{"valids.txt"};
    invalid write_invalid{"invalids.txt"};
    if (c.file.empty() || p.file.empty() || ug.file.empty()) {
      std::cerr << "Some file is empty.\n";
      return 1;
    }
    unauthenticated_request req(c.file[0], p.file[0], ug.file[0]);
    if (auto response = req.send_request(); response.status_code == 200) {
      write_valid.os << response.combo;
    } else {
      write_invalid.os << response.combo;
    }
    /*
    for (int i = 0, j = 0, k = 0; i < c.file.size(); ++i, ++j, ++k) {
      if (j == p.file.size()) {
        j = 0;
      }
      if (k == ug.file.size()) {
        k = 0;
      }

=======
    if (c.file.size() == 0 || p.file.size() == 0 || ug.file.size() == 0) {
      std::cerr << "Some file is empty.\n";
      return 1;
    }

    unauthenticated_request req(c.file[0], p.file[0], ug.file[0]);
    auto response = req.send_request();
    if (response.status_code == 200) {
      write_valid.os << response.combo;
    } else {
      write_invalid.os << response.combo;
    }
    for (int i = 0, j = 0, k = 0; i < c.file.size(); ++i, ++j, ++k) {
      if (j == p.file.size()) {
        j = 0;
      }
      if (k == ug.file.size()) {
        k = 0;
      }

    }
    */
    /*
        threading thread_pool;

        // This is used to run all the tasks inside thread_pool.
        thread_pool.executor.run(thread_pool.taskflow).wait();
      */
  } catch (const std::runtime_error &ex) {
    std::cout << "There was a problem with the formatting of your files.\n"
              << ex.what();
    std::cin.get();
    return 1;
  } catch (const std::invalid_argument &ex) {
    std::cerr << "There was a problem parsing your combos/proxies.\n";
    std::cin.get();
    return 2;
  } catch (const std::exception &ex) {
    std::cerr << ex.what();
    std::cin.get();
    // const std::ifstream::failure &ex
    // const std::bad_alloc &ex
    // const const std::ofstream::failure &ex
    // There is no point in handling these because without them we can't do
    // anything.
    return 3;
  }
}
