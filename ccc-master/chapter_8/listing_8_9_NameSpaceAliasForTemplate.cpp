#include <cstdio>
#include <stdexcept>

template <typename To, typename From>
struct NarrowCaster {
  To cast(From value) const {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if(value != backwards)
      throw std::runtime_error{ "Narrowed!" };
    return converted;
  }
};

template <typename From>
// Use alias to fix the first parameter to short (the target type).
// Only the second parameter is a template parameter.
using short_caster = NarrowCaster<short, From>;

int main() {
  try {
    // Fill in the template parameter with int.
    const short_caster<int> caster;
    const auto cyclic_short = caster.cast(142857);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch(const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}
