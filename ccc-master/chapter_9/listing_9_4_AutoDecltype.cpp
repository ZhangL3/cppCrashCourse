#include <cstdio>

template <typename X, typename Y>
// 使用箭头运算符->作为后缀，以提供返回类型。
// 这样就可以附加一个表达式来计算函数的返回类型
// 结合auto返回类型推断和decltype可以记录函数模板的返回类型。 
// 例如，decltype(x + y)将返回x + y的类型
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
/**
 * 也可以执行和正确计算返回类型
*/
// auto add(X x, Y y) {
//   return x + y;
// }

int main() {
  auto my_double = add(100., -10);
  printf("decltype(double + int) = double; %f\n", my_double);

  auto my_uint = add(100U, -20);
  printf("decltype(uint + int) = uint; %u\n", my_uint);

  auto my_ulonglong = add(char{ 100 }, 54'999'900ull);
  printf("decltype(char + ulonglong) = ulonglong; %llu\n", my_ulonglong);
}
