#include <boost/regex.hpp>
#include <iostream>

int main() {
  boost::regex regex{"Hell"};
  boost::smatch match;
  std::string line;

  while (std::cin) {
    std::getline(std::cin, line);

    if (boost::regex_search(line, match, regex)) {
      std::cout << "Bad word detected!" << std::endl;
    }

    std::cout << boost::regex_replace(line, regex, "****") << std::endl;
  }
}
