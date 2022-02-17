#include "authentication.h"
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
    threading thread_pool;

    authentication auth;
    if (auth.auth_getter()) {
      thread_pool.add_authenticated_tasks(c.file, ug.file, p.file,
                                          auth.combo_getter());
    } else {
      thread_pool.add_unauthenticated_tasks(c.file, ug.file, p.file);
    }
  } catch (const std::runtime_error &ex) {
    std::cerr << "\nThere was a problem with the formatting of your files or "
                 "combos.\n"
              << ex.what();
    std::cin.get();
  } catch (const std::invalid_argument &ex) {
    std::cerr << "\nThere was a problem parsing your combos or proxies.\n"
              << ex.what();
    std::cin.get();
  } catch (const std::exception &ex) {
    std::cerr << ex.what();
    std::cin.get();
  }
  return 1;
}
