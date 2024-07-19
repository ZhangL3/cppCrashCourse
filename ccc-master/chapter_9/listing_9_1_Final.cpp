#include <cstdio>

// final struct can not be overridden
struct BostonCorbett {
  virtual void shoot() final {
    printf("What a God we have...God avenged Abraham Lincoln\n");
  }
};

struct BostonCorbettJunior : BostonCorbett {
  // cannot override 'final' function "BostonCorbett::shoot"
  void shoot() override {} // Bang! shoot is final.
};

int main() {
  BostonCorbettJunior junior;
}
