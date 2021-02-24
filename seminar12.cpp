#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <iterator>

// std::vector<int> v
// *v.begin() -> int&
template <typename It>
  // requires forward_iterator<It>
auto Add(It begin, It end) { // -> *It
  typename std::remove_reference_t<decltype(*begin)> sum{};
  for (; begin != end; ++begin) {
    sum += *begin;
  }
  return sum;
}

/*
template <typename Num,
          // typename = std::enable_if<true/false>::type>
          typename = std::enable_if_t<std::is_integral<Num>::value>
>
*/


template <typename T>
struct IsIntegral {
  constexpr static bool value = false;
};

template <>
struct IsIntegral<int> {
  constexpr static bool value = true;
};


template <typename Num>
  requires std::is_integral_v<Num> || std::is_floating_point_v<Num>
  // requires IsIntegral<Num>::value || std::is_floating_point_v<Num>
Num Add(Num x, Num y) {
  return x + y;
}


template <typename First, typename Second>
struct Pair {
  First first;
  Second second;
};

template <typename IntegralType>
class Int {
 public:
  Int(IntegralType x = 0) : x_(x) {
  }

  Int operator+(const Int& other) const {
    return Int(x_ + other.x_);
  }

  template <typename T>
  auto operator+(const Int<T>& other) const {
    return Int<decltype(x_ + other.GetData())>(x_ + other.GetData());
  }

  template <typename T>
  Int operator+(const T& other) const {
    return Int(x_ + other); // int + Int<long>
  }

  IntegralType GetData() const {
    return x_;
  }

  template <typename T>
  friend std::ostream& operator<<(std::ostream& os,
                                  const Int<T>& x);
 private:
  IntegralType x_;
};


template <typename IntegralType>
std::ostream& operator<<(std::ostream& os, const Int<IntegralType>& x) {
  os << x.x_;
  return os;
}

int main() {
  Pair<int, double> p;
  p.first = 6;
  std::cout << p.first << '\n';
  p.second = 3.14;
  std::cout << p.second << '\n';


  Int<int> x(2);
  Int<long> y(3);
  std::cout << x + y << '\n';


  std::vector<int> v{1, 2, 3, 4};
  std::list<double> l{-1.5, 3.2, 0.01};
  std::cout << Add(v.begin(), v.end()) << '\n';
  std::cout << Add(l.begin(), l.end()) << '\n';
  // Add(1, 2);
}

