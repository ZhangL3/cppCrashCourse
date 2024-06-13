#include <cstdio>

char read_from(const char* str, int index, int strSize) {
  if (index >= strSize - 1) {
    printf("Index %d is out of bounds\n", index);
    return '\0';
  }
  return str[index];
}

void write_to(char* str, int index, char value, int strSize) {
  if (index >= strSize - 1) {
    printf("Index %d is out of bounds\n", index);
    return;
  }
  str[index] = value;
}


int main() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = upper; // Equivalent: &upper[0]

  lower[3] = 'd'; // lower now contains a b c d e \0
  upper_ptr[3] = 'D'; // upper now contains A B C D E \0

  char letter_d = lower[3]; // letter_d equals 'd'
  char letter_D = upper_ptr[3]; // letter_D equals 'D'

  printf("original: lower: %s\nupper: %s\n", lower, upper);

  char getChar = read_from(lower, 3, sizeof(lower)/sizeof(lower[0]));
  printf("getChar: %c\n", getChar);

  printf("upper size: %lu\n", sizeof(upper)/sizeof(upper[0]));
  write_to(upper_ptr, 4, 'D', sizeof(upper)/sizeof(upper[0]));
  write_to(upper, 5, 'D', sizeof(upper)/sizeof(upper[0]));
  printf("lower: %s\nupper: %s\n", lower, upper);

  lower[7] = 'g'; // Super bad. You must never do this.
}
