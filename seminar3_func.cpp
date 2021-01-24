#include <iostream>
#include <vector>


bool Comp(int x, int y) {
  if (x % 2 == y % 2) {
    return x % 2 == 0;
  }
  return x < y;
}


void PrintSomething() {
  std::cout << "Hello, World!\n";
}


int AddTwoNumbers(int x, int y) {
  return x + y;
}


std::string HelloSentence(std::string name) {
  return "Hello, " + name + "!";
}


uint64_t Power(uint64_t x, uint64_t p = 2) {
  uint64_t powered = 1;
  for (uint64_t i = 0; i < p; ++i) {
    powered *= x;
  }
  return powered;
}


void PrintArguments(std::string first,
                    std::string second = "default",
                    std::string third = "default") {
  std::cout << "The first  argument is " << first << '\n';
  std::cout << "The second argument is " << second << '\n';
  std::cout << "The third  argument is " << third << '\n';
  std::cout << '\n';
}


void fiz() {
  std::cout << "fiz ";
}

void bar(int iter);

void foo(int iter = 5) {
  if (iter == 0) {
    return;
  }
  bar(iter - 1);
  std::cout << "foo ";
}

void bar(int iter) {
  if (iter == 0) {
    return;
  }
  foo(iter - 1);
  std::cout << "bar ";
}


int main() {
  /*
  PrintSomething();
  */

  /*
  int x = AddTwoNumbers(1, 2);
  std::cout << x << '\n';
  */

  /*
  std::string name;
  std::cin >> name;
  std::cout << HelloSentence(name) << '\n';
  */

  /*
  std::cout << Power(2, 5) << '\n';
  std::cout << Power(2, 0) << '\n';
  std::cout << Power(2) << '\n';
  */

  /*
  PrintArguments("custom");
  PrintArguments("custom", "custom");
  // PrintArguments("custom", third="custom");  // Won't compile
  PrintArguments("custom", "custom", "custom");
  */

  /*
  foo();
  std::cout << '\n';
  */

  /*
  void (*print_something)(void) = PrintSomething;
  print_something();

  int (*add)(int, int) = AddTwoNumbers;
  auto add_auto = AddTwoNumbers;
  std::cout << add(5, 2) << ' ' << add_auto(5, 2) << '\n';

  std::function<void(void)> print_something_func = PrintSomething;
  std::function<int(int, int)> add_func = AddTwoNumbers;

  print_something_func();
  */
  /*
  auto print_number = [](size_t i) {
  // auto print_number = [](size_t i) -> void {
    std::cout << i << '\n';
  };
  for (size_t i = 0; i != 2; ++i) {
    print_number(i);
  }

  int x = 2;
  unsigned y = 4;
  double z = 5.6;


  auto print_number_capture = [](unsigned y) -> void {
    std::cout << x << ' ' << y << ' ' << z << '\n';
  };

  print_number_capture(y);
  x += 10;
  y += 10;
  print_number_capture(100);
  std::cout << x << '\n';
  */

  std::vector<int> a{4, 2, 6, 1};
  std::sort(a.begin(), a.end());  // 1, 2, 4, 6
  std::sort(a.begin(), a.end(), [](int x, int y) {
      if (x % 2 != y % 2) {
        return x % 2 == 0;
      }
      return x < y;
  });

  std::sort(a.begin(), a.end(), Comp);
  for (int x : a) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

