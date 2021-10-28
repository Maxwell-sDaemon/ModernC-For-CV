#include "helper.hpp"
#include "iostream"
#include <filesystem>
#include <iomanip>
// this will be goes other file like test_utils.cpp other
void test_utils::initTest(const int &idx) {
  std::cout << "\nour test" << idx << " is writting..." << std::endl;
}

void file_path_helper::path2File(std::string &path2file) {
  // test filename splitting with <filesystem>
  std::string delimiter = "/";
  std::string &token = path2file;
  while (token.find(delimiter) != std::string::npos) {
    // std::cout << "token = " << token << std::endl;
    token = token.substr(token.find(delimiter) + 1,
                         token.length()); // token is "scott"
    // std::cout << "current token = " << token << std::endl;
  }
  //   std::cout << "final token = " << token << std::endl;
  // test with raw output
}

const std::string &file_path_helper::filename(std::string &path) {
  // test filename splitting with <filesystem>
#ifdef _WIN32
#define DELIMETER "\\"
#endif
#ifdef linux
#define DELIMETER "/"
#endif
  std::string delimiter = DELIMETER;
  std::string &token = path;
  while (token.find(delimiter) != std::string::npos) {
    token = token.substr(token.find(delimiter) + 1, token.length());
  }
  //   std::cout << "final token = " << token << std::endl;
  // test with raw output
  return token;
}

// end helper function
