#include <iostream>


enum class Color : uint8_t {
  Red = 0,
  Yellow = Red + 1,
  Green = Yellow,
};

enum Flags { // 00000011
  ReadAccess = 1,
  WriteAccess = ReadAccess << 1,
  ReadWrite = ReadAccess | WriteAccess,
};

int main() {
  // Red, Yellow, Green
  char c = 'r';
  c = 'y';
  c = 'g';

  int x = 0;

  std::cout << sizeof(Color) << '\n';

  Color color = static_cast<Color>(Color::Red);
  std::cout << (Color::Red != Color::Yellow) << '\n';
}

