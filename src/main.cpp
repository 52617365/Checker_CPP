#include "combos.h"
#include "invalid.h"
#include "proxies.h"
#include "user_agents.h"
#include "valid.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>
using namespace std;

int main() {
  try {
    /*
  const combos c{"combos.txt"};
  const proxies p{"proxies.txt"};
  const user_agents ug{"user_agents.txt"};
*/
    valid << "test";
  } catch (const std::bad_alloc &ex) {
    std::cin.get();
    return 1;
  } catch (const ifstream::failure &ex) {
    std::cin.get();
    return 1;
  } catch (const ofstream::failure &ex) {
    return 1;
  }
  return 0;
}
