#ifndef SRC_SAMPLE_H_
#define SRC_SAMPLE_H_

/**
 * @brief Calculate the square of given number.
 *
 * @param [in] n A number.
 *
 * @return The square of given number n.
 */
int square(int n);

/**
 * @brief Calculate the factorial of given number.
 *
 * @param [in] n A number.
 *
 * @return The factorial of given number n.
 */
inline int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n-1);
}

#endif  // SRC_SAMPLE_H_
