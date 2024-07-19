#include <cstdio>

// This means args can be any number of arguments of any type.
template <typename... T>
// The use of a fold expression makes the function simpler and more efficient
// than the equivalent function using recursion.
constexpr auto sum(T... args) {
  // The (... + args) syntax is a unary right fold.
  // It expands to arg1 + (arg2 + (arg3 + (... + argN)))
  return (... + args);
}

int main() {
  printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12));
}
