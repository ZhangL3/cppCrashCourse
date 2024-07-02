#include <cstdio>

namespace BroopKidron13::Shaltanac {
enum class Color { Mauve, Pink, Russet };
}

int main() {
  // 因为 Color 是枚举，所以可以用::来访问
  const auto shaltanac_grass = BroopKidron13::Shaltanac::Color::Russet;
  if(shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet) {
    printf("The other Shaltanac's joopleberry shrub is always "
           "a more mauvey shade of pinky russet.");
  }
}
