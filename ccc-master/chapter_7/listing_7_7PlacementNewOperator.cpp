#include <cstddef>
#include <cstdio>
#include <new>

struct Point {
  Point()
      : x{}
      , y{}
      , z{} {
    printf("Point at %p constructed.\n", this);
  }
  /**
   * if MyClass does not acquire any resources
   * (it does not allocate memory with new, open files, etc.),
   * then it would be safe to not call the destructor.
   * But as a good practice,
   * it's recommended to always call the destructor explicitly
   * when using placement new,
   * because it makes your code safer
   * if you later modify MyClass to acquire resources.
  */
  ~Point() {
    printf("Point at %p destructed.\n", this);
  }
  double x, y, z;
};

int main() {
  const auto point_size = sizeof(Point);
  std::byte data[3 * point_size];
  printf("Data starts at %p.\n", data);
  // `new(...) Point{}`: This is the placement new operator. It constructs a [`Point`]
  auto point1 = new(&data[0 * point_size]) Point{};
  auto point2 = new(&data[1 * point_size]) Point{};
  auto point3 = new(&data[2 * point_size]) Point{};
  /**
   * you need to explicitly call the destructor for the object,
   * because the placement new does not allocate memory,
   * it just constructs an object in the provided memory location.
  */
  point1->~Point();
  point2->~Point();
  point3->~Point();
}
