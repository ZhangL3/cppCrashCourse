#include <cstdio>

template <typename T>
constexpr T sum(T x) {
  return x;
}

template <typename T, typename... Args>
/**
 * The function adds the value of x to the result
 * of recursively calling sum on the rest of the arguments (args...).
 * This recursive call continues until only one argument is left,
 * at which point the first definition of sum is used.
*/
constexpr T sum(T x, Args... args) {
  return x + sum(args...);
  // 2 + sum(4, 6, 8, 10, 12)
  // 2 + 4 + sum(6, 8, 10, 12)
  // 2 + 4 + 6 + sum(8, 10, 12)
  // ...
  // 2 + 4 + 6 + 8 + 10 + sum(12)
}

int main() {
  printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12));
}
