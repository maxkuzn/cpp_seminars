#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class A {
 public:
  A() {
    std::cout << "A()\n";
  }

  // 1
  ~A() {
    std::cout << "~A()\n";
  }

  // 2
  A(const A&) {
    std::cout << "A(const A&)\n";
  }

  // 3
  A& operator=(const A&) {
    std::cout << "operator=(const A&)\n";
    return *this;
  }

  // 4
  A(A&&) {
    std::cout << "A(A&&)\n";
  }

  // 5
  A& operator=(A&&) {
    std::cout << "operator=(A&&)\n";
    return *this;
  }
};


class B {
 public:
  B() {
    std::cout << "B()\n";
  }

  ~B() {
    std::cout << "~B()\n";
  }

  B(const B&) {
    std::cout << "B(const B&)\n";
  }

  B(B&&) {
    swap(other);
    std::cout << "B(B&&)\n";
  }

  B& operator=(B other) {
    swap(other);
    std::cout << "operator=(B)\n";
    return *this;
  }

  void swap(B& other) {
  }
};



class MyException : public std::exception {
 public:
  MyException(const std::string& explanation)
    : explanation_(explanation) {
  }

  const char* what() const noexcept {
    return explanation_.c_str();
  }

 private:
  std::string explanation_;
};


void throw_and_exception(char c) {
  if (c == 'i') {
    throw 42;
  } else if (c == 's') {
    throw std::string("Exception");
  } else if (c == 'r') {
    throw std::runtime_error("Explanation of an exception");
  } else if (c == 'e') {
    throw std::exception();
  } else if (c == 'l') {
    throw std::logic_error("Some logic error");
  } else if (c == 'm') {
    throw MyException("My exception!!!");
  }
}

void foo() {
  try {
    throw_and_exception('r');
  } catch (...) {
    // clean-up
    std::cout << "foo: clean-up\n";
    throw;
  }
}

void bar() {
  try {
    foo();
  } catch (const std::logic_error& le) {
    std::cout << "bar: logic_error\n";
  }
}





int main() {
  B a;
  B b;
  B c;
  // B b = a;
  // B c = std::move(a);
  // b = a;
  c = std::move(a);

  /*
  try {
    throw_and_exception('s');
  } catch (int x) {
    std::cout << x << '\n';
  } catch (const std::string& str) {
    std::cout << str << '\n';
  }

  try {
    throw_and_exception('i');
  } catch (...) {
    std::cout << "There was some exception\n";
  }

  try {
    throw_and_exception('m');
  } catch (const std::logic_error& le) {
    std::cout << "Logic error: " << le.what() << '\n';
  } catch (const MyException& my) {
    std::cout << "My: " << my.what() << '\n';
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  try {
    bar();
  } catch (const std::exception& e) {
    std::cout << "main: " << e.what() << '\n';
  }

  std::vector<int> v(5);
  try {
    v.at(10);
  } catch (const std::out_of_range& oor) {
    std::cout << oor.what() << '\n';
  }
  */
}

