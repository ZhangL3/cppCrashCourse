#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
  SimpleString(size_t max_size)
      : max_size{ max_size }
      , length{} {
    if(max_size == 0) {
      throw std::runtime_error{ "Max size must be at least 1." };
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString() {
    delete[] buffer;
  }
  // copy constructor (parameter is lvalue)
  // & 左值引用: 引用的是对象本身，改写引用会修改对象，用 const 保护
  SimpleString(const SimpleString& other)
      : max_size{ other.max_size }
      , buffer{ new char[other.max_size] }
      , length{ other.length } {
    // deep copy, separate memory
    std::strncpy(buffer, other.buffer, max_size);
  }
  // move constructor (parameter is rvalue)
  // && 右值引用：引用的是对象的值，可以修改
  SimpleString(SimpleString&& other) noexcept
      : max_size(other.max_size)
      , buffer(other.buffer)
      , length(other.length) {
    other.length = 0;
    other.buffer = nullptr;
    other.max_size = 0;
  }
  // copy value: = lvalue
  SimpleString& operator=(const SimpleString& other) {
    if(this == &other)
      return *this;
    const auto new_buffer = new char[other.max_size];
    // 删除原来的 buffer，因为它的长度可能不够
    delete[] buffer;
    // 把 buffer 重新指向到新的 buffer，长度是够的
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy(buffer, other.buffer, max_size);
    // *this 是左值，返回引用, *: 解引用 this 指针
    return *this;
  }
  // move value: = rvalue
  SimpleString& operator=(SimpleString&& other) noexcept {
    if(this == &other)
      return *this;
    delete[] buffer;
    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *this;
  }
  void print(const char* tag) const {
    printf("%s: %s", tag, buffer);
  }
  bool append_line(const char* x) {
    const auto x_len = strlen(x);
    if(x_len + length + 2 > max_size)
      return false;
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

  private:
  size_t max_size;
  char* buffer;
  size_t length;
};

int main() {
  // copy constructor
  SimpleString copy_constructor{ 50 };
  copy_constructor.append_line("We apologize for the");
  SimpleString copy_constructor_copy(copy_constructor);
  copy_constructor.append_line("inconvenience");
  copy_constructor_copy.append_line("incontinence");
  copy_constructor.print("copy_constructor");
  copy_constructor_copy.print("copy_constructor_copy");

  // copy value
  SimpleString copy_value{ 50 };
  copy_value.append_line("We apologize for the");
  SimpleString copy_value_copy{ 50 };
  copy_value_copy.append_line("Last message");
  copy_value.print("copy_value");
  copy_value_copy.print("copy_value_copy");
  copy_value_copy = copy_value;
  copy_value.print("copy_value");
  copy_value_copy.print("copy_value_copy");

  // move constructor (parameter is an rvalue)
  SimpleString move_constructor{ 50 };
  move_constructor.append_line("We apologize for the");
  move_constructor.print("move_constructor");
  // std:move convert lvalue to rvalue
  SimpleString move_constructor_target(std::move(move_constructor));
  // nullptr ??? warum move_constructor ist jetzt nullptr ???
  // Das Parameter ist ein right value, es ändert das originale Object nicht, oder?
  move_constructor.print("move_constructor");
  move_constructor_target.print("move_constructor_target");
  
  // move value
  SimpleString move_value{ 50 };
  move_value.append_line("We apologize for the");
  SimpleString move_value_target{ 50 };
  move_value_target.append_line("Last message");
  move_value.print("move_value");
  move_value_target.print("move_value_target");
  move_value_target = std::move(move_value);
  // move_value is "moved-from"
  move_value_target.print("move_value_target");
  // nullptr ??? warum move_constructor ist jetzt nullptr ???
  move_value.print("move_value");
}
