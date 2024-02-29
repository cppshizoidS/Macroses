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

/**
 * @brief Print a custom message along with file and line information.
 * 
 * Example: DBG_MSG("This is a custom message.");
 */
#define DBG_MSG(message) std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " << message << std::endl;


/**
 * @brief Print the value of a variable in hexadecimal format along with file and line information.
 * 
 * Example: DBG_HEX(x);
 */
#define DBG_HEX(expression) std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " << #expression << " = 0x" << std::hex << (expression) << std::dec << std::endl;

/**
 * @brief Print a separator line for better visibility.
 * 
 * Example: DBG_SEPARATOR();
 */
#define DBG_SEPARATOR() std::cout << "----------------------------------------" << std::endl;

/**
 * @brief Print the current function name along with file and line information.
 * 
 * Example: DBG_FUNCTION();
 */
#define DBG_FUNCTION() std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " << "Function: " << __PRETTY_FUNCTION__ << std::endl;

/**
 * @brief Print a warning message along with file and line information.
 * 
 * Example: DBG_WARNING("This is a warning message.");
 */
#define DBG_WARNING(message) std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] Warning: " << message << std::endl;

/**
 * @brief Print an error message, terminate the program, and display file and line information.
 * 
 * Example: DBG_ERROR("This is an error message.");
 */
#define DBG_ERROR(message) do { std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] Error: " << message << std::endl; std::exit(EXIT_FAILURE); } while(0);

/**
 * @brief Assert a condition, print an error message if false, and terminate the program.
 * 
 * Example: DBG_ASSERT(x > y, "x should be greater than y");
 */
#define DBG_ASSERT(condition, message) do { if (!(condition)) { std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] Assertion failed: " << #condition << ". " << message << std::endl; std::exit(EXIT_FAILURE); } } while(0);
/**
 * @brief Print the name and size of a container along with file and line information.
 *
 * Example: std::vector<int> vec = {1, 2, 3}; DBG_CONTAINER(vec);
 */
#define DBG_CONTAINER(container) \
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " \
              << "Container: " << #container << ", Size: " << (container).size() << std::endl;

/**
 * @brief Print the name, key, and value of a key-value pair along with file and line information.
 *
 * Example: std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}}; DBG_MAP_ENTRY(myMap, 2);
 */
#define DBG_MAP_ENTRY(map, key) \
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " \
              << "Map Entry: " << #key << " = " << (map)[key] << std::endl;

/**
 * @brief Print the name, size, and elements of a container along with file and line information.
 *
 * Example: std::set<int> mySet = {1, 2, 3}; DBG_SET_CONTENT(mySet);
 */
#define DBG_SET_CONTENT(set) \
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " \
              << "Set Content: " << #set << ", Size: " << (set).size() << ", Elements: "; \
    for (const auto& element : (set)) std::cout << element << " "; \
    std::cout << std::endl;

/**
 * @brief Print the name and contents of a C-style array along with file and line information.
 *
 * Example: int arr[] = {1, 2, 3}; DBG_ARRAY_CONTENT(arr, 3);
 */
#define DBG_ARRAY_CONTENT(array, size) \
    std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " \
              << "Array Content: " << #array << ", Size: " << (size) << ", Elements: "; \
    for (size_t i = 0; i < (size); ++i) std::cout << (array)[i] << " "; \
    std::cout << std::endl;