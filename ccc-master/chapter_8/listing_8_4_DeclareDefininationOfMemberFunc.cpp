#include <cstdint>
#include <cstdio>

struct RandomNumberGenerator {
  /**
   * When a constructor is declared as explicit,
   * it means that the compiler will not use that constructor
   * for implicit conversions 隐式转换 or copy-initializations.
   * It can only be used for direct initialization.
   *class MyClass {
    public:
        explicit MyClass(int x) {
            // Constructor implementation
        }
    };

    MyClass obj1 = 10; // Error: constructor is explicit
    MyClass obj2(10);  // OK: direct initialization
  */
  explicit RandomNumberGenerator(uint32_t seed)
      : iterations{}
      , number{ seed } {}
  uint32_t next();
  size_t get_iterations() const;

  private:
  size_t iterations;
  uint32_t number;
};

int main() {
  RandomNumberGenerator rng{ 0x4c4347 };
  while(rng.next() != 0x474343) {
    // Do nothing...
  }
  printf("%zd", rng.get_iterations());
}

uint32_t RandomNumberGenerator::next() {
  ++iterations;
  number = 0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
  return number;
}

size_t RandomNumberGenerator::get_iterations() const {
  return iterations;
}
