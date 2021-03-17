#include <iostream>
#include <optional>
#include <map>
#include <any>

class Map {
 public:
   std::optional<int> Get(const int& key) {
    if (data_.find(key) == data_.end()) {
      return std::nullopt;
    }
    return data_[key];
  }

 private:
  std::map<int, int> data_;
};



bool bar() {
  return false;
}


class Guard {
 public:
  Guard(std::function<void(void)> func) : func_(func) {
  }

  ~Guard() {
    func_();
  }

  void reset() {
    func_ = [] () {};
  }


 private:
  std::function<void(void)> func_;
};


void foo() {
  int x;
  double d;
  Guard guard([&] () {
    std::cout << "Clean x = " << x << "; d = " << d << '\n';
  });

  x = 1;
  d = 0.1;
  if (!bar()) {
    // clean
    return;
  }
  x = 2;
  d = 0.2;
  if (!bar()) {
    // clean
    return;
  }
  x = 3;
  d = 0.3;
  if (!bar()) {
    // clean
    return;
  }
  guard.reset();
  return;
}



int main() {
  // std::pair<int, bool>
  std::optional<int> opt = 5;
  *opt = 6;
  opt.reset();
  std::cout << opt.has_value() << '\n';
  std::cout << *opt << '\n';

  Map m;
  opt = m.Get(4);
  std::cout << opt.has_value() << '\n';
  int y = opt.value_or(0);
  int z = *opt;
  if (opt) {
    int x = opt.value();
  }
  std::cout << z << '\n';
  auto opt2 = std::make_optional(y);  // return std::optional<int>


  int x = 6;
  std::any a = x;
  std::cout << a.type().name() << ' ' << std::any_cast<int>(a) << '\n';
  double d = 2.4;
  a = d;
  std::cout << a.type().name() << ' ' << std::any_cast<double>(a) << '\n';

  try {
    std::any_cast<int>(a);
  } catch (std::bad_any_cast& bac) {
    std::cout << "Exception: " << bac.what() << '\n';
  }


  a = std::string("any");
  std::cout << a.type().name() << ' ' << std::any_cast<std::string>(a) << '\n';

  void* p = &x;
  std::cout << *reinterpret_cast<int*>(p) << '\n';
  p = &d;
  std::cout << *reinterpret_cast<double*>(p) << '\n';
  std::cout << *reinterpret_cast<int*>(p) << '\n';
  auto any2 = std::make_any<int>(y);




  foo();
}

