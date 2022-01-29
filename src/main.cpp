#include "combos.h"
#include "proxies.h"
#include "user_agents.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>
using namespace std;

int main() {
  try {
    const combos c{"combos.txt"};
    const proxies p{"proxies.txt"};
    const user_agents ug{"user_agents.txt"};
    for (auto x : p.file) {
      cout << x << '\n';
    }
    for (auto x : c.file) {
      cout << x << '\n';
    }
    for (auto x : ug.file) {
      cout << x << '\n';
    }
    std::cin.get();
  } catch (const std::bad_alloc &ex) {
    std::cin.get();
    return 1;
  } catch (const ifstream::failure &ex) {
    std::cin.get();
    return 1;
  }
  std::cin.get();
  return 0;
}
