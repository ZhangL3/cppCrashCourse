#include <stdio.h>

int absolute_value(int x) {
  return x >= 0 ? x : -x;
}

int main(int argc, char const *argv[])
{
  int my_num = -10;
  printf("The absolute value of %d is %d\n", my_num, absolute_value(my_num));
  return 0;
}
