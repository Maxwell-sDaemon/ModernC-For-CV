#include <iostream>
#include <sstream>
#include <string>

int main(const int argc, const char *argv[]) {
  int first_arg, second_arg;
  std::string first_ext, second_ext;

  std::stringstream ss;
  ss << argv[1];
  ss << argv[2];

  ss >> first_arg >> first_ext >> second_arg >> second_ext;

  std::cout << first_arg << first_ext << "," << second_arg << second_ext
            << std::endl;
}