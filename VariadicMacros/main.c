#include <stdio.h>
/**
 * @brief Choose the appropriate PRINTN macro based on the number of arguments.
 *
 * This macro determines the number of arguments passed to it and selects the corresponding
 * PRINTN macro to handle the printing of values. It utilizes the VALS and CT macros for this purpose.
 *
 * @param ... Variable number of arguments to be printed.
 */
#define PRINT(...) CAT(CT(__VA_ARGS__))(__VA_ARGS__)
/**
 * @brief Concatenate two macro names.
 *
 * This macro is used to concatenate the DOG macro with a numeric suffix,
 * resulting in the selection of the appropriate PRINTN macro.
 *
 * @param N Numeric suffix to be concatenated with DOG.
 */
#define CAT(N) DOG(N)
/**
 * @brief Concatenate with the PRINT macro.
 *
 * This macro is responsible for concatenating with the DOG macro
 * to form the PRINTN macro for printing N arguments.
 *
 * @param N Numeric suffix for the PRINTN macro.
 */
#define DOG(N) PRINT##N
/**
 * @brief Determine the number of arguments and select the appropriate value.
 *
 * This macro is used to determine the number of arguments passed to it and
 * selects the corresponding value from the list (5, 4, 3, 2, 1).
 *
 * @param ... Variable number of arguments.
 */
#define CT(...) VALS(__VA_ARGS__, 5, 4, 3, 2, 1)
/**
 * @brief Select the last argument from the list.
 *
 * This macro selects the last argument from the list and is used by CT.
 *
 * @param N1, N2, N3, N4, N5 Arguments forming the list.
 */
#define VALS(N1, N2, N3, N4, N5, N, ...) N
/**
 * @brief Print one argument.
 *
 * This macro prints a single argument using the printf function.
 *
 * @param A Argument to be printed.
 */
#define PRINT1(A) printf("%d\n", A)
/**
 * @brief Print two arguments and call PRINT1 for the rest.
 *
 * This macro prints the first argument and then calls PRINT1 for the remaining arguments.
 *
 * @param A First argument to be printed.
 * @param ... Remaining arguments.
 */
#define PRINT2(A, ...) printf("%d\n", A), PRINT1(__VA_ARGS__)
/**
 * @brief Print three arguments and call PRINT2 for the rest.
 *
 * This macro prints the first three arguments and then calls PRINT2 for the remaining arguments.
 *
 * @param A First argument to be printed.
 * @param ... Remaining arguments.
 */
#define PRINT3(A, ...) printf("%d\n", A), PRINT2(__VA_ARGS__)
/**
 * @brief Print four arguments and call PRINT3 for the rest.
 *
 * This macro prints the first four arguments and then calls PRINT3 for the remaining arguments.
 *
 * @param A First argument to be printed.
 * @param ... Remaining arguments.
 */
#define PRINT4(A, ...) printf("%d\n", A), PRINT3(__VA_ARGS__)
/**
 * @brief Print five arguments and call PRINT4 for the rest.
 *
 * This macro prints the first five arguments and then calls PRINT4 for the remaining arguments.
 *
 * @param A First argument to be printed.
 * @param ... Remaining arguments.
 */
#define PRINT5(A, ...) printf("%d\n", A), PRINT4(__VA_ARGS__)
/**
 * @brief Main function.
 *
 * The main function demonstrates the usage of the PRINT macro
 * to print a set of values (42, 69, 360, 1337, 0).
 *
 * @return 0 upon successful execution.
 */
int main() {
  PRINT(42, 69, 360, 1337, 0);
  return (0);
}
