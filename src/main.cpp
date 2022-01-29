#include "combos.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include <vector>
using namespace std;

int main() {
  const combos c("combos.txt");
  cout << "Initialized.\n";
  cout << c.file.size();

  for (auto x : c.file) {
    cout << x << '\n';
  }
  std::cin.get();
  return 0;
}
