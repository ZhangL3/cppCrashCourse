#include <cstdio>

// final class 不可被继承
struct BostonCorbett final {
  void shoot() {
    printf("What a God we have...God avenged Abraham Lincoln");
  }
};

// a 'final' class type cannot be used as a base class
// struct BostonCorbettJunior : BostonCorbett {}; // Bang!

int main() {
  //  BostonCorbettJunior junior;
}
