#include <iostream>
#include <memory>
#include <vector>

class Base {
 public:
  Base() {
    std::cout << "Base constructor\n";
  }

  virtual void PrintName() const = 0;

  virtual ~Base() = default;

  int GetX() {
    return x;
  }

  void SetX(int new_x) {
    x = new_x;
  }

 protected:
  int x;
};

class Derived : public Base {
 public:
  Derived() {
    std::cout << "Derived constructor\n";
  }

  void PrintName() const {
    std::cout << "Derived\n";
  }

  ~Derived() {
    std::cout << "Derived destr\n";
  }

  int GetX() {
    return x;
  }

  void SetX(int) {
  }
};


class AnotherDerived : public Base {
 public:
  AnotherDerived() {
    std::cout << "AnotherDerived constructor\n";
  }

  void PrintName() const {
    std::cout << "AnotherDerived\n";
  }

  ~AnotherDerived() {
    std::cout << "AnotherDerived destr\n";
  }

  int GetX() {
    return x;
  }

  void SetX(int) {
  }
};


int main() {
  std::cout << sizeof(Base) << '\n';
  std::cout << sizeof(Derived) << '\n' << '\n';

  Base base;

  Derived* d = new Derived();
  AnotherDerived* ad = new AnotherDerived();

  std::shared_ptr<Base> b = std::make_shared<Derived>();

  std::shared_ptr<Derived> shared_derived = std::dynamic_pointer_cast<Derived>(b);

  std::vector<std::shared_ptr<Base>> v;
  v.emplace_back(d);
  v.emplace_back(ad);
  d = nullptr;
  ad = nullptr;

  for (auto p : v) {
    p->PrintName();
  }

  std::cout << '\n';
  d = dynamic_cast<Derived*>(v[0].get());
  try {
    dynamic_cast<AnotherDerived&>(*v[0]);
  } catch (std::bad_cast& e) {
    std::cout << e.what() << '\n';
  }

  if (!d) {
    std::cout << "nullptr\n";
  }
}

