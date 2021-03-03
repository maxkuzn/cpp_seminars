#include <iostream>


class A {
 public:
  A() {
    std::cout << "Constructor A\n";
  }

  ~A() {
    std::cout << "Destructor A\n";
  }

  void hi() const {
    std::cout << "A hi\n";
  }
};


class B {
 public:
  B() {
    std::cout << "Constructor B\n";
    a.hi();
  }

  ~B() {
    std::cout << "Destructor B\n";
  }

  static B make() {
    return B{};
  }

  static void hi() {
    std::cout << "B hi: " << x << '\n';
  }

 public:
  int some_int;

  static int x;
  const static int y = 4;

 private:
  static A a;
};

int B::x;
A B::a;


int foo(int x_) {
  static int x = x_;
  return x++;
}

void A_hi() {
  static A a;
  a.hi();
}


/*
class Logger;

Logger* GetLogger() {
  static Logger logger;
  return &logger;
}
*/


int main() {
  {
    B b;
    B c;

    B d = B::make();
    // B::a.hi();
    // b.a.hi();

    b.x = 5;
    b.hi();
    c.x = 10;
    B::x = 15;
    B::hi();
    std::cout << (&b.x == &B::x) << '\n';
    std::cout << "X: " << b.x << ' ' << c.x << ' ' << B::x << '\n';
  }

  std::cout << foo(1) << '\n';
  std::cout << foo(5) << '\n';
  std::cout << foo(2) << '\n';
  std::cout << foo(0) << '\n';
  std::cout << foo(-100) << '\n';

  A_hi();
  A_hi();
  A_hi();
  A_hi();

  std::cout << "End of main\n";
}

