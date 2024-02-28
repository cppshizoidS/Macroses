#include "dbg.hpp"

auto main() -> int {
  int x = 2;
  int y = 3;

  // Example of using DBG macro to print the result of an expression
  DBG(x + y);

  // Example of using DBG_MSG macro to print a custom message
  DBG_MSG("This is a custom message.");

  // Example of using DBG_HEX macro to print the variable in hexadecimal format
  DBG_HEX(x);

  // Example of using DBG_SEPARATOR macro to print a separator line
  DBG_SEPARATOR();

  // Example of using DBG_FUNCTION macro to print the current function name
  DBG_FUNCTION();

  // Example of using DBG_WARNING macro to print a warning message
  DBG_WARNING("This is a warning message.");

  // Example of using DBG_ERROR macro to print an error message and terminate the program
  DBG_ERROR("This is an error message.");

  // Example of using DBG_ASSERT macro to assert a condition and print an error message if false
  DBG_ASSERT(x > y, "x should be greater than y");

  return 0;
}
