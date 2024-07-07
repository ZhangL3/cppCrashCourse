#include <cstdio>

struct FibonacciIterator {
  // The const keyword at the end of the function declaration means that
  // this function does not modify any member variables of the class.
  bool operator!=(int x) const {
    return x >= current;
  }

  FibonacciIterator& operator++() {
    const auto tmp = current;
    current += last;
    last = tmp;
    return *this;
  }

  int operator*() const {
    return current;
  }

  private:
  int current{ 1 }, last{ 1 };
};

struct FibonacciRange {
  explicit FibonacciRange(int max)
      : max{ max } {}
  FibonacciIterator begin() const {
    return FibonacciIterator{};
  }
  int end() const {
    return max;
  }

  private:
  const int max;
};

int main() {
/**
 * const auto e = range.end();
 * for(auto i = range.begin(); i != e; ++i) {
 *    const auto& element = *i;
 * }
*/
  for(const auto i : FibonacciRange{ 5000 }) {
    printf("%d ", i);
  }
}
