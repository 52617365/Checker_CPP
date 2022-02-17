#include "authentication.h"

bool authentication::ask_if_authentication() {
  char ch;
  while (ch != 'y' && ch != 'n') {
    std::cout << "Proxy authentication? y/n: ";
    std::cin >> ch;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Invalid value.\n";
    } else
      break;
  }
  if (ch == 'y') {
    return true;
  }
  return false;
}
std::pair<std::string, std::string>
authentication::format_combo(const std::string &combo) {
  if (size_t index_of_colon{combo.find(':')};
      index_of_colon != std::string::npos) {
    return std::make_pair(combo.substr(0, index_of_colon),
                          combo.substr(index_of_colon + 1));
  }
  throw std::runtime_error("Your proxy authentication format is invalid.\n");
}
std::pair<std::string, std::string> authentication::ask_for_authentication() {
  std::cout << "Enter authentication (user:pass): ";
  std::string combo;
  std::cin >> combo;
  try {
    auto authentication{format_combo(combo)};
    return authentication;
  } catch (const std::runtime_error &ex) {
    throw;
  }
}
