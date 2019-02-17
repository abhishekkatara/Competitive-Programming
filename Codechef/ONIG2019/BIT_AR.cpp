#include <iostream>
#include <string>

using ull = unsigned long long;

int main() {
  std::string str = "abab";

  ull length = str.length();

  for (ull i = 1; (2 * i) <= str.length() && str.length() % i == 0; ++i) {
    bool found = true;
    for (ull j = 1; (j * i) < str.length(); ++j) {
      for (ull k = 0; k < i; ++k) {
        if(str[k] != str[k + j * i]) {
          found = false;
        }
      }
    }
    if(found) {
      length = i;
      break;
    }
  }

  std::cout << "Maximal number: " << str.length() / length << std::endl;

  return 0;
}