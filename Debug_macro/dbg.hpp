#include <iostream>
/**
 * @file
 * @brief Debug Macro
 *
 * This file defines a debug macro, DBG, for printing debug information.
 * The macro prints the file name, line number, and the evaluated value of a given expression.
 *
 * Example Usage:
 * @code
 * int x = 2;
 * int y = 3;
 * DBG(x+y); // Prints: [filename.cpp:6] x + y = 5
 * @endcode
 *
 * @param expression The expression to be evaluated and printed.
 *
 * @note The macro uses the __FILE__ and __LINE__ macros to include file name and line number.
 */
#define DBG(expression) std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " << #expression << " = " << (expression) << std::endl;
