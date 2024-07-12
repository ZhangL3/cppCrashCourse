#include <cstdarg>
#include <cstdint>
#include <cstdio>

int sum(size_t n, ...) {
  // 声明可变参数的局部变量
  va_list args;
  // 启用对可变参数的访问
  va_start(args, n);
  int result{};
  while(n--) {
    // 用于遍历可变参数的迭代
    auto next_element = va_arg(args, int);
    result += next_element;
  }
  // 用于结束对可变参数的迭代
  va_end(args);
  return result;
}

int main() {
  printf("The answer is %d.", sum(6, 2, 4, 6, 8, 10, 12));
}
