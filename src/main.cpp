#include "combos.h"
#include "invalid.h"
#include "proxies.h"
#include "threading.h"
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

    if (c.file.size() == 0 || p.file.size() == 0 || ug.file.size() == 0) {
      std::cerr << "Some file is empty.\n";
      return 1;
    }

    for (int i = 0, j = 0, k = 0; i != c.file.size(); ++i, ++j, ++k) {
      if (j + 1 == p.file.size()) {
        j = 0;
      }
      if (k + 1 == ug.file.size()) {
        k = 0;
      }
      std::cout << c.file[i] << '|' << p.file[j] << '|' << ug.file[k] << '\n';
      std::cin.get();
    }
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
    return 2;
    std::cin.get();
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
