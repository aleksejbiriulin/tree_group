#include <cstdio>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::regex wildcardToRegex(const std::string& mask) {
  std::string regexStr = "^";
  for (char c : mask) {
    if (c == '*')
      regexStr += ".*";
    else if (c == '?')
      regexStr += ".";
    else if (c == '.' || c == '+' || c == '(' || c == ')') {
      regexStr += '\\';
      regexStr += c;  // Экранирование спецсимволов
    } else {
      regexStr += c;
    }
  }
  regexStr += "$";
  return std::regex(regexStr);
}

int main(int argc, char* argv[]) {
  std::string mask = argv[1];
  std::regex pattern = wildcardToRegex(mask);
  std::cout << "Маска: " << mask << "\n\n";
  std::string s;
  bool last_line = false;
  while (std::getline(std::cin, s)) {
    // size_t others = 0;
    // for (size_t i = 0; i < std::min(s.size(), last_line.size()); ++i) {
    //   if (s[s.size() - i - 1] == last_line[last_line.size() - i - 1])
    //   ++others;
    // }
    // if (others * 2 >= s.size()) {
    //   continue;
    // }
   
    if (std::regex_match(s, pattern)) {
       if (last_line) continue;
       last_line = true;
    }
    else {
      last_line = false;
    }
    printf("%s\n", s.c_str());  // ANSI цвета проходят!
  }
  return 0;
}