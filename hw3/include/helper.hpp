// @file      helper.h
// @author    Onur Demir
//
// No Copyright Freak

#ifndef TEST_UTILS_H_
#define TEST_UTILS_H_

#include <string>

namespace test_utils {
/**
 * @brief this will be inform user to starting testing new case.
 */
void initTest(const int &idx);
} // namespace test_utils

namespace file_path_helper {

/**
 * @brief this will be help to get main file name of filepath
 */
const std::string &filename(std::string &path);

/**
 * @brief this will be help to get main file name of filepath
 */
void path2File(std::string &path2file);
} // namespace file_path_helper

#endif // TEST_UTILS_H_