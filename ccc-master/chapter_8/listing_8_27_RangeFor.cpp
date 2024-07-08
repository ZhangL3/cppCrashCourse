#include <cstdio>

// 迭代器
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

  // To access the current value from the interpreter of the range for, it can not be private.
  // private:
  int current{ 1 }, last{ 1 };
};

struct FibonacciRange {
  explicit FibonacciRange(int max)
      : max{ max } {}
  /**
   * 每个范围都公开一个begin和end方法。
   * 这些函数是公共接口，
   * 基于范围的for循环使用该公共接口与范围进行交互。
   * 两个方法都返回迭代器。
   * 迭代器是支持operator!=、operator++和operator*的对象
  */
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

  for(const auto i : FibonacciRange{ 5000 }) {
    printf("%d ", i);
  }
  printf("\n");

  // Interpreter of range for
  FibonacciRange range{ 3000 };
  const auto e = range.end();
  for(auto i = range.begin(); i != e; ++i) {
    // *i returns the current value of the iterator.
    printf("%d ", *i);
  }
  printf("\n");

}
